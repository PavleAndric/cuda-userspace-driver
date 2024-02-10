import clang
import clang.cindex

# "NV2080_CTRL_GR_GET_GLOBAL_SM_ORDER_PARAMS"
#  NVC36F_CTRL_GET_CLASS_ENGINEID_PARAMS

ZERO = ["NV0000_CTRL_GPU_ATTACH_IDS_PARAMS","NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS","NV0000_CTRL_CLIENT_SET_INHERITED_SHARE_POLICY_PARAMS"  ,"NV0000_CTRL_GPU_GET_MEMOP_ENABLE_PARAMS","NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS","NV0000_CTRL_GPU_GET_ID_INFO_PARAMS","NV0000_SYNC_GPU_BOOST_GROUP_INFO_PARAMS","NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS","NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS"]

need = [
        "NV2080_CTRL_GPU_GET_GID_INFO_PARAMS"
       ,"NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS"
       ,"NVC36F_CTRL_GET_CLASS_ENGINEID_PARAMS"
       ,"NV2080_CTRL_MC_GET_ARCH_INFO_PARAMS"
       ,"NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS"
       ,"NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS"
       ,"NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS"
       ,"NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS"
       ,"NV2080_CTRL_MC_SERVICE_INTERRUPTS_PARAMS"
       ,"_clc5b5_tag0"
       ,'NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS'
       ,"NV0080_ALLOC_PARAMETERS"
       ,"NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS"
       ,"NV2080_ALLOC_PARAMETERS"
       ,'Nvc46fControl_struct'
       ,"NV2080_CTRL_BUS_GET_PCI_INFO_PARAMS"
        #ROOT
       ,"NV0000_CTRL_GPU_ATTACH_IDS_PARAMS"
       ,"NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS"
       ,"NV0000_CTRL_CLIENT_SET_INHERITED_SHARE_POLICY_PARAMS"  # ,"NV0000_CTRL_CMD_SYSTEM_GET_FABRIC_STATUS" ,"NV0000_CTRL_CMD_SYNC_GPU_BOOST_GROUP_INFO"
       ,"NV0000_CTRL_GPU_GET_MEMOP_ENABLE_PARAMS"
       ,"NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS"
       ,"NV0000_CTRL_GPU_GET_ID_INFO_PARAMS"
       ,"NV0000_SYNC_GPU_BOOST_GROUP_INFO_PARAMS"
       ,"NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS"
       ,"NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS"
       ]

all = {}
is_struct  = {clang.cindex.CursorKind.TYPEDEF_DECL, clang.cindex.CursorKind.STRUCT_DECL}
types = {"NvV32":"x" ,"NvU32":"x", "NvHandle":"x" , "NvP32":"p" , "NvU64":"llx" , "NvP64":'p'}
seen = []

def get_dname(k:list):
  if len(k) <= 1:
    return k[0].displayname
  else:
    if (ret := k[-1].displayname) != "": return ret 
    else: return "NvP32"


def get_fields(sturct:list, depth = 1):
  fields, sub = [] , []
  for x in sturct:
      
    #if any([y.kind == clang.cindex.CursorKind.INTEGER_LITERAL for y in x.get_children()]) and len(list(x.get_children())) >= 2:
    #print([x.spelling for  x  in list(x.get_children())[-1].get_tokens()])

    if x.kind == clang.cindex.CursorKind.FIELD_DECL: fields.append((x.displayname, get_dname(list(x.get_children())))) 
    if x.kind == clang.cindex.CursorKind.UNION_DECL:
      sub = get_fields(list(x.get_children()) ,depth+1)
  
  #if any([x.displayname == "gpuIds" for  x in sturct]): exit(1)
  return fields + ([sub] if sub else [])

def traverse(node):
  if node in seen: return
  
  if node.kind in is_struct and node.displayname in need:
    seen.append(node) 
    struct_ch = list(node.get_children())
    if struct_ch and struct_ch[0] not in seen:
      all[node.displayname] = get_fields(struct_ch)

  for child in node.get_children():
    traverse(child)

clang.cindex.Config.set_library_file("/usr/lib/llvm-14/lib/libclang-14.so.1")
index = clang.cindex.Index.create()

tu = index.parse("include.c",
  ["-I../../ide_cuda/open-gpu-kernel-modules/kernel-open/nvidia-uvm/",
   "-I../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc" ,
   "-I../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/ctrl/",
   "-I../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/class/"])

traverse(tu.cursor)

def make(name, args): 
  print(f"void pretty_print(struct {name}* p_){'{'}")
  print(f'  printf("{name}\\n");')
  spaces = max([len(x[0]) for x in args])

  for i,x in enumerate(args):
    if isinstance(x[0] , (tuple, list)):
      for y in x:
        data_ = args[i-1] 
        t_ = "x" if y[-1] not in types else types[y[-1]]
        print(f'    printf("\t{y[0]} {" " * (spaces - len(y[0]))} %{t_}\\n" , p_->{data_[0]}.{y[0]});')
    else:
      t_ = "x" if x[-1] not in types else types[x[-1]] 
      print(f'    printf("\t{x[0]} {" " * (spaces - len(x[0]))} %{t_}\\n",p_->{x[0]});')
      
      if t_ == "p" and name in ZERO:
        print(f"\tif (p_->{x[0]} != NULL)"+"{")
        print(f"\t  for(int i = 0 ; i < 32; i ++)" "{" + f"if(p_->{x[0]}[i])" +"{" f'printf("%d: %x\\n",i ,p_->{x[0]}[i]);' + "}}\n\t}")
  print("}")

all = {k:v for k ,v in all.items() if v and k}
for k,v in all.items(): make(k , v)

"""

for(int i = 0 ; i < 0x3f;  i ++){if(p_->engineList[i]){printf("engine :%x \n", p_->engineList[i]);}}

void pretty_print(struct NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS* p_){
  printf("NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS\n");
    printf("	pciBarCount  %x\n",p_->pciBarCount);
    printf("	pciBarInfo   %p\n",p_->pciBarInfo);
    for(int i = 0 ; i < 8 ; i ++){
      printf("pciBarInfo[%x].flags = %x " ,i, p_->pciBarInfo[i].flags);
      printf("pciBarInfo[%x].barSize = %x " ,i,p_->pciBarInfo[i].barSize);
      printf("pciBarInfo[%x].barSizeBytes = %llx " ,i,p_->pciBarInfo[i].barSizeBytes);
      printf("pciBarInfo[%x].barOffset = %llx " ,i,p_->pciBarInfo[i].barOffset);
      printf("\n");
    }
}"""