import clang
import clang.cindex

#skip = ['NvHandle','NvWchar','NvHandle','NvBool','NvTristate','NvUPtr','NvSPtr','NvLength','NvU64_ALIGN32','NvU32','NvHandle' , 'RsAccessLimb', 'NvU16']

need = ["NV2080_CTRL_GPU_GET_GID_INFO_PARAMS"
       ,"NV2080_CTRL_GR_GET_GLOBAL_SM_ORDER_PARAMS"
       ,"NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS"
       ,"NVC36F_CTRL_GET_CLASS_ENGINEID_PARAMS"
       ,"NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS"
       ,"NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS"
       ,"NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS"]

#def l_print(d, k): return f"{d*2*' '} {k}"
is_struct  = {clang.cindex.CursorKind.TYPEDEF_DECL, clang.cindex.CursorKind.STRUCT_DECL}
seen = []


def get_fields(sturct:list, depth = 1):
  fields, sub = [] , []
  for x in sturct:
    if x.kind == clang.cindex.CursorKind.FIELD_DECL: fields.append((x.displayname, list(x.get_children())[0].displayname)) 
    if x.kind == clang.cindex.CursorKind.UNION_DECL:
      sub = get_fields(list(x.get_children()) ,depth+1)
  return fields + ([sub] if sub else [])

all = {}

def traverse(node):
  if node in seen: return

  if node.kind in is_struct:
    seen.append(node)
    struct_ch = list(node.get_children())
    if struct_ch and struct_ch[0] not in seen:
      all[node.displayname] = get_fields(struct_ch)

  for child in node.get_children():
    traverse(child)

clang.cindex.Config.set_library_file("/usr/lib/llvm-14/lib/libclang-14.so.1")
index = clang.cindex.Index.create()

tu = index.parse("include.c",
  ["-I../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc" ,
   "-I../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/ctrl/",
   "-I../../ide_cuda/open-gpu-kernel-modules/kernel-open/nvidia-uvm/"])

traverse(tu.cursor)

def make(name, args): 
  print(f"sturct {name} *strct_ = (struct {name}*)p->AlloctParams;")
  for x in args:
    print(f'printf("%{x[-1]}\\n",p_->{x[0]});')

all = {k:v for k ,v in all.items() if v and k}
for k,v in all.items():
  make(k , v)
