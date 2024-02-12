import clang
import clang.cindex
import re 

# "NV2080_CTRL_GR_GET_GLOBAL_SM_ORDER_PARAMS"
#  NVC36F_CTRL_GET_CLASS_ENGINEID_PARAMS

ZERO = ["NV0000_CTRL_GPU_ATTACH_IDS_PARAMS","NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS","NV0000_CTRL_CLIENT_SET_INHERITED_SHARE_POLICY_PARAMS"  ,"NV0000_CTRL_GPU_GET_MEMOP_ENABLE_PARAMS","NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS","NV0000_CTRL_GPU_GET_ID_INFO_PARAMS","NV0000_SYNC_GPU_BOOST_GROUP_INFO_PARAMS","NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS","NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS"]
need = [
        "NV0080_CTRL_HOST_GET_CAPS_V2_PARAMS"
       ,"NV_MEMORY_ALLOCATION_PARAMS"
       ,"NV2080_CTRL_GPU_GET_GID_INFO_PARAMS"
       ,"NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS"
       ,"NVC36F_CTRL_GET_CLASS_ENGINEID_PARAMS"
       ,"NV2080_CTRL_MC_GET_ARCH_INFO_PARAMS"
       ,"NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS"
       ,"NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS"
       ,"NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS"
       ,"NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS"
       ,"NV2080_CTRL_MC_SERVICE_INTERRUPTS_PARAMS"
       ,"_clc5b5_tag0"
       ,"NV2080_CTRL_GSP_GET_FEATURES_PARAMS"
       ,'NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS'
       ,"NV0080_ALLOC_PARAMETERS"
       ,"NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS"
       ,"NV2080_ALLOC_PARAMETERS"
       ,'Nvc46fControl_struct'
       ,"NV2080_CTRL_BUS_GET_PCI_INFO_PARAMS"
        #root
       ,"NV0000_CTRL_GPU_ATTACH_IDS_PARAMS"
       ,"NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS"
       ,"NV0000_CTRL_CLIENT_SET_INHERITED_SHARE_POLICY_PARAMS"  
       ,"NV0000_CTRL_GPU_GET_MEMOP_ENABLE_PARAMS"
       ,"NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS"
       ,"NV0000_CTRL_GPU_GET_ID_INFO_PARAMS"
       ,"NV0000_SYNC_GPU_BOOST_GROUP_INFO_PARAMS"
       ,"NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS"
       ,"NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS"
       ]

all, seen = {}, []
is_struct  = {clang.cindex.CursorKind.TYPEDEF_DECL, clang.cindex.CursorKind.STRUCT_DECL}
types = {"NvV32":"x" ,"NvU32":"x", "NvHandle":"x" , "NvP32":"p" , "NvU64":"llx" , "NvP64":'p' , "int":"lx"}

def get_dname(k):
  if not k: return ""
  #print(k.type.spelling)
  return k.type.spelling

def get_uvm_ioctl_names():
  regex_pattern = r"^\s*#define\s+UVM_[A-Z_]+\s+UVM_IOCTL_BASE\(\d+\)$"
  file = "".join(open("../../ide_cuda/open-gpu-kernel-modules/kernel-open/nvidia-uvm/uvm_ioctl.h" ,"r").read())
  matches = [x.replace("\n", "") for x  in re.findall(regex_pattern, file, re.MULTILINE)]
  dont_need = ["UVM_REGION_SET_BACKING" , "UVM_REGION_UNSET_BACKING"]
  matches = [x.replace("#define" , "").replace(" " , "").split("UVM_IOCTL_BASE") for x in matches]
  return {k:int(v.replace("(","").replace(")","")) for k,v in matches if k not in dont_need}  
  
def get_fields(sturct:list):
  fields, sub = [] , []

  for x in sturct:
    if x.kind == clang.cindex.CursorKind.FIELD_DECL:
      k = get_dname(x)
      fields.append((x.displayname , k))
      
    if x.kind == clang.cindex.CursorKind.UNION_DECL or clang.cindex.CursorKind.STRUCT_DECL: ## ovo si menjao
      sub = get_fields(list(x.get_children()))

  return fields + (([sub] if not isinstance(sub ,list) else sub) if sub else [])

def traverse(node):
  if node in seen: return
  
  if node.kind in is_struct and (node.displayname in need or node.displayname in need_uvm): ##   
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
   "-I../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/class/",
   "-I../../ide_cuda/open-gpu-kernel-modules/kernel-open/nvidia-uvm"])

def get_type(x):
  if "[" in x[-1]: return "p"
  else:return "lx" if x[-1] not in types else types[x[-1]]


not_wanted = {"gpuUuid" , "gpuUuidArray" , "gpuUuidA" , "gpuUuidB" , "gpu_uuid" , "preferredLocation" ,"accessedByUuid" ,"destinationUuid" ,"processor","multiGpu" ,"sharePolicy"}

def make(name, args): 
  print(f"void pretty_print({'struct' if not 'UVM' in name else ''} {name}* p_){'{'}")
  print(f'  printf("{name}\\n");')
  spaces = max([len(x[0]) for x in args])

  for i,x in enumerate(args):
    if isinstance(x[0] , (tuple, list)):
      for y in x:
        data_ = args[i-1] 
        t_ = get_type(y)
        if t_ != "struct" and y[0] not in not_wanted:
          print(f'    printf("\t{y[0]} {" " * (spaces - len(y[0]))} %{t_}\\n" , {"(uint64_t)(" if t_ == "lx" else ""} p_->{data_[0]}.{y[0]}) {")" if t_ == "lx" else ""};')
        else:
          print(f'    printf("{y[0]} LMAO POPRAVI OVO\\n");')
    else:
      t_ = get_type(x)
      if t_ != "struct" and x[0] not in not_wanted:
        print(f'    printf("\t{x[0]} {" " * (spaces - len(x[0]))} %{t_}\\n",{"(uint64_t)(" if t_ == "lx" else ""}p_->{x[0]}) {")" if t_ == "lx" else ""};')
      else:
        print(f'    printf("{x[0]} LMAO POPRAVI OVO\\n");')
      if t_ == "p" and name in ZERO:
        print(f"\tif (p_->{x[0]} != NULL)"+"{")
        print(f"\t  for(int i = 0 ; i < 32; i ++)" "{" + f"if(p_->{x[0]}[i])" +"{" f'printf("%d: %x\\n",i ,p_->{x[0]}[i]);' + "}}\n\t}")
  print("}")

if __name__ == "__main__":
  uvm_ioct = get_uvm_ioctl_names()
  need_uvm = [k + "_PARAMS" for k  in  uvm_ioct.keys()]

  print("#include"  +'"uvm_ioctl.h"')
  traverse(tu.cursor)
  all = {k:v for k ,v in all.items() if v and k}
  for k,v in all.items(): 
    make(k , v)

  print("void get_uvm_ioct(int nr,void *argp){")
  print("  switch(nr){")
  for k,uvm_io in  zip(uvm_ioct.keys() , need_uvm):
    print(f"    case {k}:"+ "{")
    #nv_ioctl_alloc_os_event *p = (nv_ioctl_alloc_os_event*)argp; 
    print(f"      {uvm_io} *p = ({uvm_io}*)argp; pretty_print(p);")
    print("    }") 
  print("  }")
  print("}")
  exit(1)


"""
for(int i = 0 ; i < 0x3f;  i ++){if(p_->engineList[i]){printf("engine :%x \n", p_->engineList[i]);}}
for(int i = 0  ; i < 0x40 ; i ++){if(p_->firmwareVersion[i]){printf("%x \n" , p_->firmwareVersion[i]);}}

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