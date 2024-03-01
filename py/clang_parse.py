import clang
import clang.cindex
import re   

types = {"NvV32":"x" ,"NvU32":"x", "NvHandle":"x" , "NvP32":"p" , "NvU64":"llx" , "NvP64":'p' , "int":"x", "NV_STATUS":"x" , "NvBool":"x" , "NvS32":"x" , "NvU16":"x"}
not_wanted = {"gpuUuid" , "gpuUuidArray" , "gpuUuidA" , "gpuUuidB" , "gpu_uuid" , "preferredLocation" ,"accessedByUuid" ,"destinationUuid" ,"processor","multiGpu" ,"sharePolicy"}

mtdh =  ["NVC5C0_SET_OBJECT","NVC5C0_NO_OPERATION","NVC5C0_SET_SHADER_SHARED_MEMORY_WINDOW_A","NVC5C0_SET_SHADER_SHARED_MEMORY_WINDOW_B","NVC5C0_SET_SPA_VERSION","NVC5C0_SET_CWD_REF_COUNTER","NVC5C0_SET_RESERVED_SW_METHOD07","NVC5C0_SET_RESERVED_SW_METHOD10","NVC5C0_SET_RESERVED_SW_METHOD09","NVC5C0_SET_VALID_SPAN_OVERFLOW_AREA_A","NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_C","NVC5C0_INVALIDATE_SKED_CACHES","NVC5C0_LAUNCH_DMA","NVC5C0_OFFSET_OUT_UPPER","NVC5C0_LINE_LENGTH_IN","NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_A","NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_B","NVC5C0_SET_INLINE_QMD_ADDRESS_A","NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE","NVC597_SET_STREAM_OUT_BUFFER_LOAD_WRITE_POINTER","NVC597_SET_L1_CONFIGURATION","NVC597_SET_ROOT_TABLE_VISIBILITY","NVC597_LOAD_INLINE_DATA"]
ioctl =[
 ("NV_ESC_CARD_INFO","nv_ioctl_card_info_t")
,("NV_ESC_REGISTER_FD","nv_ioctl_register_fd")
,("NV_ESC_ALLOC_OS_EVENT","nv_ioctl_alloc_os_event")
,("NV_ESC_NUMA_INFO","nv_ioctl_numa_info_t")
,("NV_ESC_RM_FREE","NVOS00_PARAMETERS")
,("NV_ESC_RM_MAP_MEMORY","NVOS33_PARAMETERS")
,("NV_ESC_RM_UPDATE_DEVICE_MAPPING_INFO", "NVOS56_PARAMETERS")
,("NV_ESC_RM_ALLOC_MEMORY", "nv_ioctl_nvos02_parameters_with_fd")
,("NV_ESC_SYS_PARAMS","nv_ioctl_sys_params_t")
]
alloc = [
 ("NV01_EVENT_OS_EVENT","NV0005_ALLOC_PARAMETERS")
,("NV50_MEMORY_VIRTUAL","NV_MEMORY_ALLOCATION_PARAMS")
,("NV01_MEMORY_LOCAL_USER","NV_MEMORY_ALLOCATION_PARAMS")
,("NV01_MEMORY_SYSTEM","NV_MEMORY_ALLOCATION_PARAMS")
,("FERMI_CONTEXT_SHARE_A","NV_CTXSHARE_ALLOCATION_PARAMETERS")
,("KEPLER_CHANNEL_GROUP_A","NV_CHANNEL_GROUP_ALLOCATION_PARAMETERS")
,("TURING_COMPUTE_A","NV_GR_ALLOCATION_PARAMETERS")
,("FERMI_VASPACE_A","NV_VASPACE_ALLOCATION_PARAMETERS")
,("NV0080_ALLOC_PARAMETERS_MESSAGE_ID","NV0080_ALLOC_PARAMETERS")
,("NV2080_ALLOC_PARAMETERS_MESSAGE_ID","NV2080_ALLOC_PARAMETERS")
,("TURING_CHANNEL_GPFIFO_A","NV_CHANNEL_ALLOC_PARAMS")
,("TURING_DMA_COPY_A","NVB0B5_ALLOCATION_PARAMETERS")
]
control = [  
("NV2080_CTRL_CMD_GR_GET_INFO","NV2080_CTRL_GR_GET_INFO_PARAMS")
,("NVA06C_CTRL_CMD_GPFIFO_SCHEDULE"," NVA06F_CTRL_GPFIFO_SCHEDULE_PARAMS")
,("NV0080_CTRL_CMD_HOST_GET_CAPS_V2"," NV0080_CTRL_HOST_GET_CAPS_V2_PARAMS")
,("NV2080_CTRL_CMD_GSP_GET_FEATURES"," NV2080_CTRL_GSP_GET_FEATURES_PARAMS")
,("NV2080_CTRL_CMD_BUS_GET_PCI_INFO"," NV2080_CTRL_BUS_GET_PCI_INFO_PARAMS")
,("NV0000_CTRL_CMD_GPU_ATTACH_IDS"," NV0000_CTRL_GPU_ATTACH_IDS_PARAMS")
,("NV0000_CTRL_CMD_GPU_GET_ID_INFO_V2"," NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS")
,("NV0000_CTRL_CMD_GPU_GET_PROBED_IDS"," NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS")
,("NV0000_CTRL_CMD_GPU_GET_ID_INFO"," NV0000_CTRL_GPU_GET_ID_INFO_PARAMS")
,("NV0000_CTRL_CMD_GPU_GET_ATTACHED_IDS"," NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS")
,("NV0080_CTRL_CMD_GPU_GET_CLASSLIST_V2"," NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS")
,("NV2080_CTRL_CMD_BUS_GET_PCI_BAR_INFO"," NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS")
,("NV2080_CTRL_CMD_GPU_GET_ENGINES_V2"," NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS")
,("NV2080_CTRL_CMD_MC_GET_ARCH_INFO"," NV2080_CTRL_MC_GET_ARCH_INFO_PARAMS")
,("NV2080_CTRL_CMD_MC_SERVICE_INTERRUPTS"," NV2080_CTRL_MC_SERVICE_INTERRUPTS_PARAMS")
,("NV2080_CTRL_CMD_GPU_GET_GID_INFO"," NV2080_CTRL_GPU_GET_GID_INFO_PARAMS")
,("NVC36F_CTRL_GET_CLASS_ENGINEID"," NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS")
,("NV2080_CTRL_CMD_GR_GET_CTX_BUFFER_SIZE"," NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS")
,("NV0080_CTRL_CMD_FIFO_GET_CHANNELLIST"," NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS")
,("NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN"," NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS")
,("NV0000_CTRL_CMD_CLIENT_GET_ADDR_SPACE_TYPE"," NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS")
,("NV0000_CTRL_CMD_CLIENT_SET_INHERITED_SHARE_POLICY")
,("NV2080_CTRL_CMD_GR_GET_GLOBAL_SM_ORDER")
,("NV00FD_CTRL_CMD_ATTACH_GPU")
,("NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION")
,("NV0000_CTRL_CMD_SYNC_GPU_BOOST_GROUP_INFO")
,("NV0002_CTRL_CMD_UPDATE_CONTEXTDMA")
,("NV2080_CTRL_CMD_GPU_GET_ACTIVE_PARTITION_IDS")
,("NV0080_CTRL_CMD_GPU_GET_SPARSE_TEXTURE_COMPUTE_MODE")
,("NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS")
,("NV2080_CTRL_CMD_GPU_GET_SIMULATION_INFO")
,("NV2080_CTRL_CMD_GR_GET_CAPS_V2")
,("NV2080_CTRL_CMD_CE_GET_ALL_CAPS")
,("NV2080_CTRL_CMD_GPU_QUERY_ECC_STATUS")
,("NV2080_CTRL_CMD_GPU_GET_SHORT_NAME_STRING")
,("NV2080_CTRL_CMD_GPU_GET_NAME_STRING")
,("NV2080_CTRL_CMD_GPU_QUERY_COMPUTE_MODE_RULES")
,("NV0000_CTRL_CMD_SYSTEM_GET_FABRIC_STATUS")
,("NV2080_CTRL_CMD_RC_RELEASE_WATCHDOG_REQUESTS")
,("NV2080_CTRL_CMD_RC_SOFT_DISABLE_WATCHDOG")
,("NV2080_CTRL_CMD_BUS_GET_C2C_INFO")
,("NV0080_CTRL_CMD_GPU_GET_NUM_SUBDEVICES")
,("NV_CONF_COMPUTE_CTRL_CMD_SYSTEM_GET_CAPABILITIES")
,("NV83DE_CTRL_CMD_DEBUG_SET_EXCEPTION_MASK")
,("NV2080_CTRL_CMD_GR_SET_CTXSW_PREEMPTION_MODE")
,("NV0000_CTRL_CMD_GPU_GET_MEMOP_ENABLE")
,("NV2080_CTRL_CMD_GPU_GET_INFO")
,("NV2080_CTRL_CMD_GR_GET_GPC_MASK")
,("NV2080_CTRL_CMD_GR_GET_TPC_MASK")
,("NVA06C_CTRL_CMD_SET_TIMESLICE")
,("NV2080_CTRL_CMD_PERF_BOOST")
,("NV2080_CTRL_CMD_BUS_GET_INFO_V2")
,("NV0080_CTRL_CMD_FB_GET_CAPS_V2")
,("NV2080_CTRL_CMD_FB_GET_INFO_V2")
,("NV0080_CTRL_CMD_GPU_GET_VIRTUALIZATION_MODE")]


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
    if x.kind == clang.cindex.CursorKind.FIELD_DECL: fields.append((x.displayname , x.type.spelling))
    if x.kind == clang.cindex.CursorKind.UNION_DECL or clang.cindex.CursorKind.STRUCT_DECL: # TODO: fix this 
      sub = get_fields(list(x.get_children()))
  return fields + (([sub] if not isinstance(sub ,list) else sub) if sub else [])

def traverse(node):
  if node.displayname in seen: return

  if node.kind in is_struct and (node.displayname in need or node.displayname in need_uvm): ##   
    seen.add(node.displayname) 
    struct_ch = list(node.get_children())
    if struct_ch and struct_ch[0].displayname not in seen:
      all[node.displayname] = get_fields(struct_ch)

  for child in node.get_children():
    traverse(child)

clang.cindex.Config.set_library_file("/usr/lib/llvm-14/lib/libclang-14.so.1")
index = clang.cindex.Index.create()

tu = index.parse("include.c",
  ["-I../../ide_cuda/open-gpu-kernel-modules/kernel-open/nvidia-uvm",
   "-I../../ide_cuda/open-gpu-kernel-modules/kernel-open/common/inc",
   "-I../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc" ,
   "-I../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/ctrl/",
   "-I../../ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/class/",
   "-I../../ide_cuda/open-gpu-kernel-modules/kernel-open/nvidia-uvm",
   "-I../../ide_cuda/open-gpu-kernel-modules/src/nvidia/arch/nvalloc/unix",
   "-I../../ide_cuda/open-gpu-kernel-modules/src/nvidia/arch/nvalloc/unix/include"
   ])

def get_type(x):
  if x[0] in  not_wanted: return "p"
  if "[" in x[-1]: return "p"
  else:return "p" if x[-1] not in types else types[x[-1]]

def make_str(x ,spc ,t_ ,addr, additional = ""):
  print(f'    printf("\t{x}{spc} %{t_}\\n", {"&" if addr else ""}p_->{additional + "." if additional and not addr else ""}{x});' + ("// fix this" if addr else ""))

def make_print(name, args): 
  print(f"void pretty_print({'struct' if not 'UVM' else ''} {name}* p_){'{'}")
  print(f'  printf("{name}\\n");')
  spaces = max([len(x[0]) for x in args])
  for x in args:
    t_, spc = get_type(x), " " * (spaces - len(x[0]))
    make_str(x[0] , spc, t_, x[-1] not in types or x[0] in not_wanted)
  print("}")

def make_switch(name, arr_1, args):
  print(f"void get_{name}({''.join([x + (',' if i != len(args)-1 else '') for i, x in enumerate(args)])})" + "{")
  switch_arg , arg = args[0].split(" ")[-1], args[-1].split(" ")[-1]
  print(f"  switch  ({switch_arg})" + "{")
  for k, s in arr_1:
    if s != "":
      print(f"    case {k}:" + "{")
      print(f"      {s} *p = ({s}*){arg}; pretty_print(p);break;")
      print("    }")
    else:
      print(f'    case {k}:' , "{" +f'printf("{k}\\n");break;'+ "}")
  print('    default:printf("not important :) \\n");')
  print("  }\n}")

if __name__ == "__main__":
  need = [x[-1].replace(" " , "") for x in  alloc if len(x) == 2]  + [x[-1].replace(" " , "") for x in  control] + [x[-1] for x in ioctl]
  is_struct  = {clang.cindex.CursorKind.TYPEDEF_DECL, clang.cindex.CursorKind.STRUCT_DECL}
  all, seen = {}, set()

  uvm_ioct = get_uvm_ioctl_names()
  need_uvm = [k + "_PARAMS" for k  in  uvm_ioct.keys()]
  
  traverse(tu.cursor)
  all = {k:v for k ,v in all.items() if v and k}
  for k,v in all.items(): 
    make_print(k , v)

  make_switch("uvm_ioctl", list(zip(uvm_ioct.keys(), need_uvm)), ["uint32_t nr", "void* argp"])
  make_switch("command", [x if len(x) == 2 else (x, "")  for x in control] , ["uint32_t cm", "void* params"])
  make_switch("alloc", [x if len(x) == 2 else (x, "")  for x in alloc] , ["uint32_t hClass", "void* params"])
  print("/*")
  make_switch("mthd", [x if len(x) == 2 else (x, "")  for x in mtdh] , ["uint32_t mthd"])
  print("*/")