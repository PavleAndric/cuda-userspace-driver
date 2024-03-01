#include<stdio.h>
#include<sys/ioctl.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<stdint.h>
#include<assert.h>
#include<unistd.h>
#include<string.h> 
#include<dlfcn.h>

#include"nvos.h" 
#include"nv_escape.h" 
#include"nvtypes.h"
#include"nv-ioctl.h"
#include"nvCpuUuid.h"
#include"nv-unix-nvos-params-wrappers.h"
#include"uvm_linux_ioctl.h"
#include"uvm_ioctl.h"

#include "ctrl/ctrl0000/ctrl0000gpu.h"
#include "ctrl/ctrl0000/ctrl0000client.h"
#include "ctrl/ctrl2080/ctrl2080rc.h"
#include "ctrl/ctrl2080/ctrl2080gsp.h"
#include "ctrl/ctrl2080/ctrl2080gpu.h"
#include "ctrl/ctrl0080/ctrl0080fifo.h"
#include "ctrl/ctrl2080/ctrl2080gr.h"
#include "ctrl/ctrla06f/ctrla06fgpfifo.h"
#include "ctrl/ctrl2080/ctrl2080mc.h"
#include "ctrl/ctrlc36f.h"
#include "ctrl/ctrla06c.h"

#include "class/clc597.h"
#include "class/clc5c0.h"
#include "class/cl003e.h"
#include "class/clcb33.h"
#include "class/cl0080.h"
#include "class/cl2080.h"
#include "class/clc461.h"
#include "class/cl50a0.h"
#include "class/cl90f1.h"
#include "class/cl0070.h"
#include "class/cl0040.h"
#include "class/cl9067.h"
#include "class/cla06c.h"
#include "class/cl00c2.h"
#include "class/clc46f.h"
#include "class/clc46f.h"
#include "class/clc5b5.h"
#include "class/cl0005.h"
#include "class/clb0b5sw.h"

#include"helpers.h"
#include"novu.h"


NvU8 uud[16] = {0x9f,0xa6,0xcc,0x3,0x56,0xa2,0x1f,0x6b,0x26,0x26,0x8,0x90,0xb,0xbd,0xb4,0x94}; 

NvHandle alloc_object(int fd , NvHandle hroot ,NvHandle hObjectParent,NvV32 hClass ,NvP64 pAllocParams){
  
  NVOS21_PARAMETERS object = {.hRoot = hroot,.hObjectParent = hObjectParent,.hClass =hClass,.pAllocParms = pAllocParams,.paramsSize = 0};
  int res = ioctl(fd, _IOC(_IOC_READ|_IOC_WRITE, 0x46, NV_ESC_RM_ALLOC, sizeof(object)), &object);

  assert(object.status == 0);assert(res == 0);
  return object.hObjectNew;
}

void ctrl(int fd , NvHandle hClient,NvHandle hObject,NvV32 cmd,NvU32 flags,NvP64 params,NvU32 paramsSize){

  NVOS54_PARAMETERS parameters = {.hClient =hClient ,.hObject = hObject,.cmd = cmd,.flags = flags,.params = params ,.paramsSize = paramsSize};
  int res = ioctl(fd, _IOC(_IOC_READ|_IOC_WRITE, 0x46, NV_ESC_RM_CONTROL, sizeof(parameters)), &parameters);
  assert(parameters.status == 0);  assert(res == 0);
}

void* rm_map_mem(int fd, NvHandle hClient,NvHandle hDevice,NvHandle hMemory,NvU64 offset,NvU64 length,NvP64 pLinearAddress,NvU32 flags){

  int nv_0 = open64("/dev/nvidia0", O_RDWR | O_CLOEXEC);

  NVOS33_PARAMETERS p = {.hClient=hClient,.hDevice=hDevice,.hMemory=hMemory,.offset= offset,.length=length,.pLinearAddress=pLinearAddress,.flags=flags};
  nv_ioctl_nvos33_parameters_with_fd parameters = {.params = p ,.fd  = nv_0};
  int res = ioctl(fd, _IOC(_IOC_READ|_IOC_WRITE, 0x46, NV_ESC_RM_MAP_MEMORY, sizeof(parameters)), &parameters);
  
  assert(p.status == 0);assert(res == 0);
  void *ret = mmap64(NULL, 0x10000, PROT_READ|PROT_WRITE, MAP_SHARED, nv_0, 0);close(nv_0);
  return ret;
}

void init_uvm(int nv_uvm_fd){
  
  int nv_uvm_fd_2 = open64("/dev/nvidia-uvm", O_RDWR | O_CLOEXEC);

  UVM_INITIALIZE_PARAMS  uvm_init = {0}; uvm_init.flags = 0x0; 
  UVM_MM_INITIALIZE_PARAMS uvm_init_mm = {0}; uvm_init_mm.uvmFd = nv_uvm_fd;
  UVM_PAGEABLE_MEM_ACCESS_PARAMS uvm_i_pageble=  {0};

  int res_0 = ioctl(nv_uvm_fd, UVM_INITIALIZE, &uvm_init);
  int res_1 = ioctl(nv_uvm_fd_2, UVM_MM_INITIALIZE, &uvm_init_mm);
  int res_2 = ioctl(nv_uvm_fd, UVM_PAGEABLE_MEM_ACCESS, &uvm_i_pageble);

  assert(uvm_i_pageble.rmStatus == 0);assert(uvm_init.rmStatus == 0);assert(uvm_init_mm.rmStatus == 0);
  assert(res_0 == 0);assert(res_1 == 0);assert(res_2 == 0);
}

void second_uvm(int nv_uvm_fd){

  UVM_REGISTER_GPU_PARAMS register_ = {0}; register_.rmCtrlFd = -1;
  UVM_PAGEABLE_MEM_ACCESS_ON_GPU_PARAMS pagable = {0};
  UVM_CREATE_RANGE_GROUP_PARAMS range = {0};

  memcpy((void*)register_.gpu_uuid.uuid , (void*)uud ,sizeof(register_.gpu_uuid.uuid));
  memcpy((void*)pagable.gpu_uuid.uuid , (void*)uud ,sizeof(pagable.gpu_uuid.uuid));

  int res_0 = ioctl(nv_uvm_fd, UVM_REGISTER_GPU, &register_);
  int res_1 =  ioctl(nv_uvm_fd ,UVM_PAGEABLE_MEM_ACCESS_ON_GPU , &pagable);
  int res_2 =  ioctl(nv_uvm_fd ,UVM_CREATE_RANGE_GROUP , &range);

  assert(register_.rmStatus == 0);assert(pagable.rmStatus == 0);assert(range.rmStatus == 0);
  assert(res_0 == 0);assert(res_1 == 0);assert(res_2 == 0);
}

void uvm_external_range(uint64_t base, uint64_t lenght , NvHandle mappingObject , NvHandle root , int control_fd , int nv_uvm_fd){

  UVM_CREATE_EXTERNAL_RANGE_PARAMS rom_1 = {.base = base, .length = lenght};
  UVM_MAP_EXTERNAL_ALLOCATION_PARAMS rom_2 = {.base = base,.length = lenght, .gpuAttributesCount = 0x1 ,.rmCtrlFd = control_fd,.hClient = root ,.hMemory = mappingObject}; // imas jedan gpu
  memcpy((void*)rom_2.perGpuAttributes[0].gpuUuid.uuid , (void*)uud , sizeof(rom_2.perGpuAttributes[0].gpuUuid.uuid)); rom_2.perGpuAttributes[0].gpuMappingType = 0x1;

  int res_dumb_1 = ioctl(nv_uvm_fd, UVM_CREATE_EXTERNAL_RANGE ,&rom_1);
  int res_dumb_2 = ioctl(nv_uvm_fd, UVM_MAP_EXTERNAL_ALLOCATION ,&rom_2);

  assert(res_dumb_1 == 0);assert(rom_1.rmStatus == 0);
  assert(res_dumb_2 == 0);assert(rom_2.rmStatus == 0);
}

//ISPRAVI OVO OCAJ
void *map_object(int mapping_fd, int control_fd, NvHandle root_, NvHandle device, NvHandle subDevice, NvHandle mappingObject , uint32_t mapFlags , uint32_t addrSpaceType ,uint32_t lenght, void* addr ,int not_mmap){
  void *res = NULL;
  NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS params ={ .hObject = mappingObject,.mapFlags = mapFlags};
  NVOS33_PARAMETERS p = {.hClient = root_, .hDevice = subDevice,.hMemory = mappingObject, .length=lenght,.flags=mapFlags};
  nv_ioctl_nvos33_parameters_with_fd map_params = {.params = p ,.fd  = mapping_fd}; // OVO NIJE OX4 ALI SAMO  TAKO RADI ????? HEX TE JE ZAJEBAO

  ctrl(control_fd, root_, root_, NV0000_CTRL_CMD_CLIENT_GET_ADDR_SPACE_TYPE, 0 ,&params , sizeof(params));
  int res_map = ioctl(control_fd, _IOC(_IOC_READ|_IOC_WRITE, 0x46, NV_ESC_RM_MAP_MEMORY, sizeof(map_params)), &map_params);
  if (not_mmap == 1){res = mmap64(addr , lenght, PROT_READ|PROT_WRITE , MAP_SHARED|MAP_FIXED, mapping_fd, 0);}

  ///printf("%x %x %x \n",map_params.params.status, p.status, res_map);
  assert(map_params.params.status == 0);assert(p.status == 0);assert(res_map == 0);
  return res;
}

int main(){ 

  int control[0x100];
  int control_2[0x100];
  // ROOT
  int control_fd = open64( "/dev/nvidiactl", O_RDWR);
  int nv0_fd = open64("/dev/nvidia0", O_RDWR | O_CLOEXEC);
  int nv_uvm_fd = open64("/dev/nvidia-uvm", O_RDWR | O_CLOEXEC);

  nv_ioctl_card_info_t args = {0};
  int res_0 = ioctl(control_fd, _IOC(_IOC_READ|_IOC_WRITE, 0x46, 0xc8, sizeof(args)), &args);

  //ROOT
  NvHandle root_ = alloc_object(control_fd, 0, 0, NV01_ROOT_CLIENT, NULL);
  //init uvm part_1
  init_uvm(nv_uvm_fd); 
  //device 
  NV0080_ALLOC_PARAMETERS p_80 = {.deviceId=0x0,.hClientShare=root_,.hTargetClient=0,.hTargetDevice=0,.flags=0,.vaSpaceSize=0,.vaStartInternal=0,.vaLimitInternal=0,.vaMode=0x2};
  NvHandle o52 = alloc_object(control_fd, root_ ,root_, NV01_DEVICE_0, &p_80);
  //subdevices
  NV2080_ALLOC_PARAMETERS p_2080 = {.subDeviceId = 0x0};
  NvHandle o53 = alloc_object(control_fd, root_ ,o52, NV20_SUBDEVICE_0, &p_2080);
  //turing_usemode_a
  NvHandle o54 = alloc_object(control_fd, root_ ,o53, TURING_USERMODE_A, NULL); 
  //Fermi_1 , ovo  mozda nije dobro posto, ioctl  u  straceu ima isti  argument za ova  sistemska poziva
  NV_VASPACE_ALLOCATION_PARAMETERS p_fermi_1 = {.index = 0 , .flags = 0x48 , .vaSize = 0 ,.vaStartInternal = 0 , .vaLimitInternal = 0 , .bigPageSize = 0 , .vaBase =0x1000};
  NvHandle o55 = alloc_object(control_fd, root_ ,o52, FERMI_VASPACE_A, (void*)&p_fermi_1);
  //Fermi_2
  NV_VASPACE_ALLOCATION_PARAMETERS p_fermi_2 = {.index = 0 , .flags = 0x0 , .vaSize = 0 ,.vaStartInternal = 0 , .vaLimitInternal = 0 , .bigPageSize = 0 , .vaBase =0x5000000};
  NvHandle o56 = alloc_object(control_fd, root_ ,o52, FERMI_VASPACE_A, &p_fermi_2);  
  //init uvm  part_2
  second_uvm(nv_uvm_fd);
  //virtual
  NV_MEMORY_ALLOCATION_PARAMS romcina = {.owner = (NvU32)root_ , .flags = 0x8c415 ,.size= 0xfb000000,.offset = 0x5000000 ,.hVASpace=o56}; 
  NvHandle o58 = alloc_object(control_fd, root_ ,o52, NV50_MEMORY_VIRTUAL, &romcina);  
  //void *big_map = mmap64((void*)0x200000000 ,0x100200000 , PROT_READ|PROT_WRITE , MAP_PRIVATE|MAP_ANONYMOUS ,-1,0); assert(big_map != NULL);
  /// INIT DONE ///
  
  /// CONTEXT BEGIN ///
  //ENGINES
  uint32_t engineList[0x3FU];
  NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS engine_v2_params = {.engineCount = 0x3f};
  ctrl(control_fd , root_ , o53 ,NV2080_CTRL_CMD_GPU_GET_ENGINES_V2, 0, &engine_v2_params ,sizeof(engine_v2_params));

  //gr_params
  uint64_t gr_arr[0x38];for(int i  = 0 ; i < 0x38 ;i ++){gr_arr[i] = i;}
  NV2080_CTRL_GR_GET_INFO_PARAMS gr_params = {.grInfoListSize = 0x38 , .grInfoList = gr_arr};
  ctrl(control_fd , root_ , o53 ,NV2080_CTRL_CMD_GR_GET_INFO, 0, &gr_params , sizeof(gr_params));

  //register vaspace params
  UVM_REGISTER_GPU_VASPACE_PARAMS register_ = {.rmCtrlFd = control_fd , .hClient = root_ , .hVaSpace = o55};
  memcpy((void*)register_.gpuUuid.uuid , (void*)uud ,sizeof(register_.gpuUuid.uuid));
  int res =  ioctl(nv_uvm_fd, UVM_REGISTER_GPU_VASPACE, &register_); assert(res == 0);

  //BAR
  NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS p_= {.hObject =o54 , .mapFlags=0x80002 , .addrSpaceType = 0};
  ctrl(control_fd , root_ , root_ ,NV0000_CTRL_CMD_CLIENT_GET_ADDR_SPACE_TYPE,0, &p_  ,sizeof(p_));
  void *bar_start = rm_map_mem(control_fd , root_, o53, o54, 0,0x10000, NULL, p_.mapFlags);
  uint64_t* door_bell = (uint64_t*)((uint64_t)bar_start + 0x90);  
  printf("BAR -> %p \n" ,bar_start);

  // OVO  JE  MOZDA POTREBNO ???
  NV2080_CTRL_GPU_GET_GID_INFO_PARAMS gid = {0}; gid.flags = 0x2;
  ctrl(control_fd , root_, o53 ,NV2080_CTRL_CMD_GPU_GET_GID_INFO , 0, &gid , sizeof(gid));
  // kepler group
  NV_CHANNEL_GROUP_ALLOCATION_PARAMETERS k_g = {.hObjectError = 0 , .hObjectEccError = 0  , .hVASpace= 0 , .engineType = 1};
  NvHandle kepler_group =  alloc_object(control_fd, root_ ,o52, KEPLER_CHANNEL_GROUP_A, &k_g);  
  // fermi context
  NV_CTXSHARE_ALLOCATION_PARAMETERS f_c  = {.hVASpace = o55 , .flags = 1 ,.subctxId = 0}; 
  NvHandle fermi_context =  alloc_object(control_fd, root_ ,kepler_group, FERMI_CONTEXT_SHARE_A, &f_c); 

  //SECOND PART CONTEXT
  //MMAP NV_0 
  NV_MEMORY_ALLOCATION_PARAMS nv_0_mapping = {
    .owner = root_,
    .flags = 0x1c101,
    .attr = 0x18000000,
    .size = 0x200000,
    .alignment = 0x200000}; 

  NvHandle nv_0_object = alloc_object(control_fd , root_ , o52, NV01_MEMORY_LOCAL_USER, (void*)&nv_0_mapping);
  int new_nv0 = openat(AT_FDCWD, "/dev/nvidia0", O_RDWR|O_CLOEXEC);
  void* nv_gas_ =  map_object(new_nv0 ,control_fd, root_, o52, o53, nv_0_object, 0xc0000, 0x0, 0x200000 , (void*)0x200200000 , 1); close(new_nv0);
  printf("/dev/nvidia0 -> %p\n" , nv_gas_);

  // UPDATE MAPPING INFO
  NVOS56_PARAMETERS update = {.hClient = root_ ,.hDevice = o53,.hMemory =nv_0_object ,.pOldCpuAddress = (void*)0xb0170000,.pNewCpuAddress = (void*)0x200200000};
  int mapping_res = ioctl(control_fd, _IOC(_IOC_READ|_IOC_WRITE, 0x46, NV_ESC_RM_UPDATE_DEVICE_MAPPING_INFO, sizeof(update)), &update); 
  assert(mapping_res == 0); assert(update.status == 0);
  uvm_external_range(0x200200000 , 0x200000 ,nv_0_object, root_,control_fd , nv_uvm_fd);

  //MMAP NV_CTRLs // ovo  mozda nije dobro
  
  NV_MEMORY_ALLOCATION_PARAMS nv_ctrl_mapping {   
    .owner = root_,
    .flags = 0xc001,
    .attr = 0x5a000000,
    .size = 0x3800000,
  };

  //ovo  mozda nije dobro
  int new_ctrl = openat(AT_FDCWD, "/dev/nvidiactl", O_RDWR|O_CLOEXEC);
  NvHandle nv_crtl_object = alloc_object(control_fd, root_, o52, NV01_MEMORY_SYSTEM, (void*)&nv_ctrl_mapping);   // 3e
  void* nv_ctrl_gas =  map_object(new_ctrl ,control_fd, root_, o52, o52, nv_crtl_object, 0xc0000, 0x0, 0x3800000 , (void*)0x200400000 ,1); close(new_ctrl); 
  printf("/dev/nvidiactrl -> %p\n" ,nv_ctrl_gas);
  uvm_external_range(0x200400000 , 0x3800000 ,nv_crtl_object, root_,control_fd , nv_uvm_fd);

  //POPRAVI OVO  OVO JE BESKORISNO IZRISI
  NV_MEMORY_ALLOCATION_PARAMS o516_mapping  = {   
    .owner = o52,
    .flags = 0xc001,
    .attr = 0x3a000000,
    .size = 0x1000
  };
  // NV_ESC_RM_MAP_MEMORY, fd=10 hDevice=5c000002, len=1000, offset=0, flags=c0000, linaddr=(nil), hmem_=5c000016,hClient=c1d03cd2, status__=0
  int new_ctrl_ = openat(AT_FDCWD, "/dev/nvidiactl", O_RDWR|O_CLOEXEC);
  NvHandle o516 =   alloc_object(control_fd, root_, o52, NV01_MEMORY_SYSTEM, (void*)&o516_mapping);   // 5c016 
  void* o516_addr =  map_object(new_ctrl_ ,control_fd, root_, o52, o52, o516, 0xc0000, 0x0, 0x1000 , (void*)0x7fffe2fdf000 ,1); close(new_ctrl_);
  printf("o516_addr %p\n" , o516_addr);
  ///// OVO JE SVE OK ////////


  //CONTEXT FIFO napravi TURING_CHANNEL_GPFIFO_A objekat  
  NV_CHANNEL_ALLOC_PARAMS params_Gp = {.hObjectError = o516 ,.hObjectBuffer = nv_0_object,.gpFifoOffset = 0x200200000 ,.gpFifoEntries = 0x400,.hContextShare = fermi_context};
  params_Gp.hUserdMemory[0] = nv_0_object; params_Gp.userdOffset[0] = 0x2000;
  NvHandle glupi_objekat = alloc_object(control_fd , root_ ,kepler_group, TURING_CHANNEL_GPFIFO_A, (void*)&params_Gp); // c46f

  uint32_t arr[] = {glupi_objekat , 0x1}; uint32_t arr_2[2] = {0};
  NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS fifo_get_chnl  = {.numChannels = 0x1 , .pChannelHandleList = (void*)arr , .pChannelList = (void*)arr_2}; // .pChannelList = (void*)0x7ffff5ca8c68
  ctrl(control_fd, root_, o52 ,NV0080_CTRL_CMD_FIFO_GET_CHANNELLIST, 0, &fifo_get_chnl, sizeof(fifo_get_chnl));

  //TURING_COMPUTE_A  dete TURING_CHANNEL_GPFIFO_A  ------ 5c017 ------
  NV_GR_ALLOCATION_PARAMETERS turing_cp_params = {.size = 0xffffca60 , .caps = 0x7ffff};
  NvHandle turing_compute_a = alloc_object(control_fd , root_ ,glupi_objekat,TURING_COMPUTE_A, (void*)&turing_cp_params);

  // ovo uzmi classEngineID_ c5c0 classID_ c5c0 engineID_ 1 
  NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS engineid_params_0 = {.hObject = turing_compute_a};
  ctrl(control_fd , root_ , glupi_objekat ,NVC36F_CTRL_GET_CLASS_ENGINEID , 0 , &engineid_params_0 , sizeof(engineid_params_0));

  //TURING_DMA_COPY
  NVB0B5_ALLOCATION_PARAMETERS turing_dma_params = {.engineType = 0x1};
  NvHandle turing_dma = alloc_object(control_fd , root_ , glupi_objekat, TURING_DMA_COPY_A, (void*)&turing_dma_params);

  //classEngineID_ c5b5 classID_ c5b5 engineID_ a 
  NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS engineid_params = {.hObject = turing_dma};
  ctrl(control_fd , root_ , glupi_objekat ,NVC36F_CTRL_GET_CLASS_ENGINEID , 0 , &engineid_params , sizeof(engineid_params));

  //WORK_SUBMIT_TOKEN
  NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS token = {.workSubmitToken = 0x0};
  ctrl(control_fd, root_, glupi_objekat ,NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN, 0, &token,sizeof(token));

  //NV2080_CTRL_CMD_GR_GET_CTX_BUFFER_SIZE
  NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS buffer_size = {.hChannel = glupi_objekat};
  ctrl(control_fd , root_ , o53 ,NV2080_CTRL_CMD_GR_GET_CTX_BUFFER_SIZE, 0 , &buffer_size, sizeof(buffer_size));

  void* shared = mmap((void*)0x7fffed000000, 0x10000, PROT_NONE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0); //ovo mnogo mapira 

  ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// /////   
                                              //------------------------------------SMECE------------------------------------//////
  NV_MEMORY_ALLOCATION_PARAMS adresa_lmao_params = {.owner = root_ , .type = 0x0 , .flags = 0x1c101 ,.attr =0x11800000,.size = 0x200000 ,.alignment=0x200000 , .offset = 0x2000000};
  NvHandle adresa_lmao = alloc_object(control_fd , root_ ,o52, NV01_MEMORY_LOCAL_USER ,  (void*)&adresa_lmao_params);
  uvm_external_range((uint64_t)0x205400000 , 0x200000 , adresa_lmao, root_ , control_fd , nv_uvm_fd);
  void * addr_gas = mmap((void*)0x205400000 , 0x200000 , PROT_WRITE|PROT_READ, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0); 

  // 0x205400000 - 0x205807000 
  NV_MEMORY_ALLOCATION_PARAMS program_ovject_params = {.owner = root_ , .type = 0x0 , .flags = 0x1c101 ,.attr=0x11800000,.size = 0x200000 ,.alignment=0x200000 , .offset = 0x2e00000};
  NvHandle program_object = alloc_object(control_fd , root_ , o52 , NV01_MEMORY_LOCAL_USER, (void*)&program_ovject_params);
  uvm_external_range((uint64_t)0x7fffcfe00000 , 0x200000 , program_object, root_ , control_fd , nv_uvm_fd);
  void *program_adrr = mmap((void*)0x7fffcfe00000 , 0x200000 , PROT_WRITE|PROT_READ, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0); 

  
  NV_MEMORY_ALLOCATION_PARAMS sub_program_params = {.owner = root_ , .type = 0x0 , .flags = 0x1c101 ,.attr=0x11800000,.size = 0x2400000 ,.alignment=0x200000 , .offset = 0x3000000};
  NvHandle sub_program = alloc_object(control_fd , root_ , o52 , NV01_MEMORY_LOCAL_USER, (void*)&sub_program_params);
  uvm_external_range((uint64_t)0x7fffcc000000 , 0x2400000 , sub_program, root_ , control_fd , nv_uvm_fd);
  void *sub_program_adrr = mmap((void*)0x7fffcc000000 , 0x2400000/*0x1a00000 je dobro*/ , PROT_WRITE|PROT_READ, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0); 
  printf("addr_gas = %p program_adrr = %p sub_program_adrr = %p \n" , addr_gas ,program_adrr , sub_program_adrr);

  struct nouveau_pushbuf push_buf = {.cur = (uint32_t*)0x200400000}; // 0x200434054
  nouveau_pushbuf *push =  &push_buf;

  *((uint32_t*)0x200200000)= 0x400000; 
  *((uint32_t*)0x200200004)= 0x2a602;

  // command buffer //??????????
  PUSH_DATA(push , 0x20012000);
  PUSH_DATA(push , 0xc5c0);
  PUSH_DATA(push , 0x200120a8);   // NVC5C0_SET_SHADER_SHARED_MEMORY_WINDOW_A
  PUSH_DATA(push , 0x7fff);
  PUSH_DATA(push , 0x200120a9);   // NVC5C0_SET_SHADER_SHARED_MEMORY_WINDOW_B
  PUSH_DATA(push , 0xed000000);
  PUSH_DATA(push , 0x200120b9);   // NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_A
  PUSH_DATA(push , 0x0);
  PUSH_DATA(push , 0x200120b9);   // NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_B
  PUSH_DATA(push , 0x8);     // ????????


  *((uint32_t*)0x200224000) =0x2c00000;
  *((uint32_t*)0x200224004) =0x2202;

  push->cur = (uint32_t*)0x202c00000;
  PUSH_DATA(push , 0x20018000);
  PUSH_DATA(push , 0xc5b5);
  

  UVM_REGISTER_CHANNEL_PARAMS register_params_0 = {
    .rmCtrlFd = control_fd,
    .hClient = root_,
    .hChannel = glupi_objekat,
    .base = 0x203c00000,
    .length = 0xc82000,
  };memcpy((void*)register_params_0.gpuUuid.uuid , (void*)uud ,sizeof(register_params_0.gpuUuid.uuid));

  //REGISTER_PARAMS
  int res_channel_params = ioctl(nv_uvm_fd, UVM_REGISTER_CHANNEL, &register_params_0);
  assert(res_channel_params == 0); 
  assert(register_params_0.rmStatus == 0);

  // SCHEDULE_PARAMSe
  NVA06F_CTRL_GPFIFO_SCHEDULE_PARAMS gpfifo ={.bEnable = 0x1, .bSkipSubmit = 0x0};
  ctrl(control_fd , root_ ,kepler_group , NVA06C_CTRL_CMD_GPFIFO_SCHEDULE , 0 ,&gpfifo , sizeof(gpfifo));

  nv_ioctl_register_fd_t fd_t = {.ctl_fd = control_fd}; 
  int fd_t_res = ioctl(nv0_fd, _IOC(_IOC_READ|_IOC_WRITE, 0x46, NV_ESC_REGISTER_FD, sizeof(fd_t)), &fd_t);
  assert(fd_t_res == 0);

  //NV_ESC_ALLOC_OS_EVENT / NV_ESC_ALLOC_OS_EVENT = 0xce NV_O_fd
  nv_ioctl_alloc_os_event_t os_event_params = {.hClient = root_ ,.hDevice = o53, .fd = (NvU32)nv0_fd}; 
  int res_os_event = ioctl(nv0_fd, _IOC(_IOC_READ|_IOC_WRITE, 0x46, NV_ESC_ALLOC_OS_EVENT, sizeof(os_event_params)), &os_event_params);
  assert(res_os_event == 0); assert(os_event_params.Status == 0);

  //79 OBJECT
  NV0005_ALLOC_PARAMETERS os_79 = {.hParentClient  = root_ , .hClass = NV01_EVENT_OS_EVENT, .notifyIndex = 0x3800000c, .data = (void*)((uint64_t)nv0_fd)}; //0x3800000c
  NvHandle object_79 = alloc_object(nv0_fd , root_ , o53 , NV01_EVENT_OS_EVENT, &os_79); 

  usleep(10000);
  ////// second onject ///////////
  /// kepler_2
  NV_CHANNEL_GROUP_ALLOCATION_PARAMETERS kepler_2_params = {.hVASpace = o55 , .engineType = 0xc}; 
  NvHandle kepler_2 = alloc_object(control_fd , root_ , o52 , KEPLER_CHANNEL_GROUP_A , (void*)&kepler_2_params);

  // helper ili sta vec
  NV_MEMORY_ALLOCATION_PARAMS helper_obj_params = {.owner = o52 , .type = 0xd , .flags = 0xc001 ,.attr =0x3a000000,.size = 0x1000}; //
  NvHandle helper_obj = alloc_object(control_fd , root_ , o52 , NV01_MEMORY_SYSTEM , &helper_obj_params);  
  void* helper_obj_addr =  map_object(control_fd ,control_fd, root_, o52, o52, helper_obj, 0xc0000, 0x0, 0x1000 , (void*)0x7fffe2fe1000 ,1); // 0x7fffe2fdf000
  printf("helper_obj_addr -> %p\n" , helper_obj_addr);

  //Drugi turing objekat
  NV_CHANNEL_ALLOC_PARAMS turing_obj_2 = {.hObjectError = helper_obj ,.hObjectBuffer = nv_0_object,.gpFifoOffset = 0x200224000 ,.gpFifoEntries = 0x400};
  turing_obj_2.hUserdMemory[0] = nv_0_object; turing_obj_2.userdOffset[0] = 0x26000;
  NvHandle drugi_turing = alloc_object(control_fd , root_ ,kepler_2, TURING_CHANNEL_GPFIFO_A, (void*)&turing_obj_2); // c46f

  uint32_t arr_turing[] = {drugi_turing , 0x1}; uint32_t arr_turing_2[2] = {0};
  NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS fifo_get_chnl_2  = {.numChannels = 0x1 , .pChannelHandleList = (void*)arr_turing , .pChannelList = (void*)arr_turing_2}; // .pChannelList = (void*)0x7ffff5ca8c68
  ctrl(control_fd, root_, o52 ,NV0080_CTRL_CMD_FIFO_GET_CHANNELLIST, 0, &fifo_get_chnl_2, sizeof(fifo_get_chnl_2));

  //turing_dma_2 provori da li je ovo dma objekat
  NVB0B5_ALLOCATION_PARAMETERS turing_dma_params_2 = {.engineType = 0x3};
  NvHandle turing_dma_2 = alloc_object(control_fd , root_ , drugi_turing, TURING_DMA_COPY_A, (void*)&turing_dma_params_2);

  //EngineID
  NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS engineid_params_2 = {.hObject = turing_dma_2};
  ctrl(control_fd , root_ , drugi_turing ,NVC36F_CTRL_GET_CLASS_ENGINEID , 0 , &engineid_params_2 , sizeof(engineid_params_2));

  //WORK_SUBMIT_TOKEN
  NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS token_2 = {.workSubmitToken = 0x0};
  ctrl(control_fd, root_, drugi_turing ,NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN, 0, &token_2,sizeof(token_2));

  UVM_REGISTER_CHANNEL_PARAMS register_params_2 = {.rmCtrlFd = control_fd, .hClient = root_ ,.hChannel = drugi_turing};
  memcpy((void*)register_params_2.gpuUuid.uuid , (void*)uud ,sizeof(register_params_2.gpuUuid.uuid));
  int res_channel_params_2 = ioctl(nv_uvm_fd, UVM_REGISTER_CHANNEL, &register_params_2);
  assert(res_channel_params_2 == 0);

  NVA06F_CTRL_GPFIFO_SCHEDULE_PARAMS gpfifo_2 ={.bEnable = 0x1, .bSkipSubmit = 0x0};
  ctrl(control_fd , root_ ,kepler_2 , NVA06C_CTRL_CMD_GPFIFO_SCHEDULE , 0 ,&gpfifo_2 , sizeof(gpfifo_2));

  //////////// register_2 ////////////
  int nv_fd_2 = open64("/dev/nvidia0", O_RDWR | O_CLOEXEC);
  nv_ioctl_register_fd_t fd_t_2 = {.ctl_fd = control_fd}; 
  int fd_t_res_2 = ioctl(nv_fd_2, _IOC(_IOC_READ|_IOC_WRITE, 0x46, NV_ESC_REGISTER_FD, sizeof(fd_t_2)), &fd_t_2);
  assert(fd_t_res_2 == 0);

  //NV_ESC_ALLOC_OS_EVENT / NV_ESC_ALLOC_OS_EVENT = 0xce NV_O_fd
  nv_ioctl_alloc_os_event_t os_event_params_2 = {.hClient = root_ ,.hDevice = o53, .fd = (NvU32)nv_fd_2}; 
  int res_os_event_2 = ioctl(nv_fd_2, _IOC(_IOC_READ|_IOC_WRITE, 0x46, NV_ESC_ALLOC_OS_EVENT, sizeof(os_event_params_2)), &os_event_params_2);
  assert(res_os_event_2 == 0); assert(os_event_params_2.Status == 0);
  
  //79 OBJECT_2
  NV0005_ALLOC_PARAMETERS os_79_2 = {.hParentClient  = root_ , .hClass = NV01_EVENT_OS_EVENT, .notifyIndex = 0x3800001a, .data = (void*)((uint64_t)nv_fd_2)};
  NvHandle object_79_2 = alloc_object(nv_fd_2 , root_ , o53 , NV01_EVENT_OS_EVENT, &os_79_2);

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // DEVICE_PTR
  void *k  = mmap((void*)0x7fffcc000000, 0x1a00000 ,PROT_READ | PROT_WRITE , MAP_SHARED|MAP_ANONYMOUS , -1 , 0);
  NV_MEMORY_ALLOCATION_PARAMS arr_  = {   
    .owner = root_,
    .flags = 0x1c101,
    .attr = 0x18000000,
    .size = 0x200000,
    .alignment = 0x200000,
  };
  NvHandle device_ptr = alloc_object(control_fd , root_, o52 ,NV01_MEMORY_LOCAL_USER ,(void*)&arr_);
  uvm_external_range((uint64_t)k , 0x200000 , device_ptr, root_ , control_fd , nv_uvm_fd);

  memset((void*)control ,0x0 , 0x100); memset((void*)control_2 ,0x0 , 0x100); 
  hexdump((void*)control , 0x20);


  push->cur = (uint32_t*)0x2004002a4;
  PUSH_DATA(push , 0x20022062); 
  PUSH_DATAh(push , (uint64_t)k);  // 0x7fffcc000000
  PUSH_DATAl(push , (uint64_t)k); // 0x7fffcc000000
  PUSH_DATA(push , 0x20022060); 
  PUSH_DATA(push , 0x28);
  PUSH_DATA(push , 0x1);
  PUSH_DATA(push , 0x2001206c); 
  PUSH_DATA(push , 0x41);
  PUSH_DATA(push , 0x600a206d); 
  for(int  i = 0 ; i < 10; i ++){PUSH_DATA(push , i);}

  *((uint32_t*)0x200200008) = 0x4002a4;
  *((uint32_t*)0x20020000c) = 0x6202;
  *((uint32_t*)0x200202088)= 2;
  *((uint32_t*)0x20020208c)= 2; 
  *door_bell = 0x9;
  usleep(50000);
  printf("CURR %p \n", push->cur);  
  //dump_small((void*)0x200400000 , (void*)0x203c00000);
  
  clear_nvctrl();
  push->cur = (uint32_t*)0x202c00020;
  PUSH_DATA(push ,0x20048100); 
  PUSH_DATAh(push ,(uint64_t)k); 
  PUSH_DATAl(push ,(uint64_t)k);
  PUSH_DATAh(push ,(uint64_t)control);
  PUSH_DATAl(push ,(uint64_t)control + 0x4);
  PUSH_DATA(push ,0x20018106);
  PUSH_DATA(push  , 0x28);
  BEGIN_NVC0(push ,0x4, NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE, 0x1);
  PUSH_DATA(push , 0x182);

  // device to host
  *((uint32_t*)0x200224008)= 0x2c00020;
  *((uint32_t*)0x20022400c)= 0x3e02;    
  *((uint32_t*)0x200226088)= 0x2;
  *((uint32_t*)0x20022608c) =0x2; 
  *door_bell = 0x9000a;
  usleep(50000);
  clear_nvctrl();
  hexdump((void*)control , 0x20);
  
  void* off_uper = mmap((void*)0x7fffcc000000, 0x2400000, PROT_READ | PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0); //ovo mnogo mapira 

  //printf("prg_addr = %p \n" ,prg_addr); // 0x7ffff7e84000
  printf("off_uper = %p \n" ,off_uper); // 0x7ffff5400000 - 0x7ffff7800000
  printf("shared = %p \n" ,shared); // 0x7ffff5400000 - 0x7ffff7800000
  /* program  */
  constexpr int N =  64; 
  uint32_t program[N] = {
    0x00017a02, 0x00000a00, 0x00000f00, 0x000fc400, 
    0x00067919, 0x00000000, 0x00002500, 0x000e2200, 
    0x00077802, 0x00000004, 0x00000f00, 0x000fc600, 
    0x00037919, 0x00000000, 0x00002100, 0x000e2400, 
    0x06067a24, 0x00000000, 0x078e0203, 0x001fc800, 
    0x06027625, 0x00005800, 0x078e0207, 0x000fc800, 
    0x06047625, 0x00005a00, 0x078e0207, 0x000fc800, 
    0x02027381, 0x00000000, 0x001ee900, 0x000ea800, 
    0x04057381, 0x00000000, 0x001ee900, 0x000ea200, 
    0x06067625, 0x00005c00, 0x078e0207, 0x000fe200, 
    0x02097210, 0x00000005, 0x07ffe0ff, 0x004fd000, 
    0x06007386, 0x00000009, 0x0010e900, 0x000fe200, 
    0x0000794d, 0x00000000, 0x03800000, 0x000fea00, 
    0x00007947, 0xfffffff0, 0x0383ffff, 0x000fc000, 
    0x00007918, 0x00000000, 0x00000000, 0x000fc000, 
    0x00007918, 0x00000000, 0x00000000, 0x000fc000
  };

  constexpr int M = 88; 
  uint32_t load_1[M] = { // 0x7fffcc100000
    0x0000000a, 0x00000001, 0x00000001, 0x00000001, 
    0x00000001, 0x00000001, 0xed000000, 0x00007fff,  // 0xf5600000 nije ova
    0xeb000000, 0x00007fff, 0x00fffdc0, 0x00000000,  // 0x00fffdc0
    0x00000001, 0x00000000, 0x05408000, 0x00000002,  // 0x02054080
    0xce220000, 0x00007fff, 0xce010000, 0x00007fff,  // f5600000 ? vrv  nij edobro, 0xcc102160, 0xcc102360
    0x00000000, 0x00000000, 0x00000000, 0x00000000,                 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x02ee2efe, 0x00000000,  //  0x02ee2efe ???
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000001, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000010, 
    0x00000000, 0x00000178, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x05800000, 0x00000002,  // 0x05800000
    0xcfe3b300, 0x00007fff, 0x00000000, 0x00000000,  // cfe00000 cfe3b300
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
  };

  
  constexpr int O = 66;
  uint32_t load_2[O] ={0x00000000, 0x02054080, 0x00000000, 0x00000000,  // 0x02054080 ******  0x02031000
    0x00000000, 0x00000000, 0x0000047f, 0x3c000000,  // ovo je adresa 0x3c000000  , mozda ne ???
    0x00000000, 0x00000000, 0xffcfe3b3, 0x00000000,  // 7ffffcc102100 cc102160 ????
    0x00000000, 0x44010000, 0x00000001, 0x00000001, 
    0x00000001, 0x00000000, 0x00000000, 0x22240000,  // 22240000  0x7ffcc1021000.
    0x000a0023, 0x00010001, 0x00121083, 0x00000000, 
    0x00000000, 0x03007f7c, 0x80000002, 0x00000006,  // 0x05607f7c
    0x00000000, 0x00000000, 0x00000000, 0x08000000,  // 08000000 ??? ovo mozda nije dobro
    0x00000640, 0x7300127f, 0xce220000, 0x0c4c7fff,  //  0x7300127f  /*
    0xce010000, 0x04107fff, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0xce000000, 0x80007fff, 0xcfe3b300, 0x00007fff,  // 0xce000000, ovo  osmica ovde je cudna
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000
  };

  //PCCLIENT_GCC faulted @ 0x7ffc_c1021000. Fault is of type FAULT_PDE ACCES

  /* function  */
  // 7fffcfe3b300 je njimas
  clear_nvctrl();
  printf("CURR %p \n", push->cur);  
  push->cur = (uint32_t*)0x200400304;
  PUSH_DATA(push , 0x20022062);          // NVC5C0_OFFSET_OUT_UPPER
  PUSH_DATAh(push , (uint64_t)0x7fffcfe3b300); // ovo ne slama 0x7fffcc020000 0x1a00000
  PUSH_DATAl(push , (uint64_t)0x7fffcfe3b300); // ovo ne slama 0x7fffcc020000     80000 
  PUSH_DATA(push , 0x20022060);          // NVC5C0_LINE_LENGTH_IN
  PUSH_DATA(push , 0x100);
  PUSH_DATA(push , 0x1);
  PUSH_DATA(push , 0x2001206c);          // NVC5C0_LAUNCH_DMA
  PUSH_DATA(push , 0x41);
  PUSH_DATA(push , 0x6040206d);          // NVC597_LOAD_INLINE_DATA
  for(int i = 0 ; i < N ; i ++){PUSH_DATA(push , program[i]);} // LOAD PROGRAM
  
  *((uint32_t*)0x200200010) = 0x400304;
  *((uint32_t*)0x200200014) = 0x13a02;
  *((uint32_t*)0x200202088)= 0x3;
  *((uint32_t*)0x20020208c)= 0x3;
  *door_bell = 0x9; 
  usleep(50000); 
  dump_small((void*)0x200400000 , (void*)0x203c00000);
  clear_nvctrl();

  //OVO je izgleda ok
  push->cur = (uint32_t*)0x20040043c; // 43c
  PUSH_DATA(push , 0x20022062);          // NVC5C0_OFFSET_OUT_UPPER
  PUSH_DATAh(push , (uint64_t)0x7fffce220000); // ovo vrv ne valja off_uper
  PUSH_DATAl(push , (uint64_t)0x7fffce220000);
  PUSH_DATA(push , 0x20022060);          // NVC5C0_LINE_LENGTH_IN
  PUSH_DATA(push , 0x160);
  PUSH_DATA(push , 0x1);
  PUSH_DATA(push , 0x2001206c);          // NVC5C0_LAUNCH_DMA
  PUSH_DATA(push , 0x41);
  PUSH_DATA(push , 0x6058206d);            // NVC597_LOAD_INLINE_DATA
  for(int i = 0 ; i < M ; i ++){PUSH_DATA(push , load_1[i]);} //load_1[i]
  
  PUSH_DATA(push , 0x20022062);           // NVC5C0_OFFSET_OUT_UPPER
  PUSH_DATAh(push , (uint64_t)0x7fffce220160);      //  ce220160 ko njih
  PUSH_DATAl(push , (uint64_t)0x7fffce220160);
  PUSH_DATA(push , 0x20022060);            // NVC5C0_LINE_LENGTH_IN
  PUSH_DATA(push , 0x18);
  PUSH_DATA(push , 0x1); 
  PUSH_DATA(push , 0x2001206c);            // NVC5C0_LAUNCH_DMA
  PUSH_DATA(push , 0x41);            

  PUSH_DATA(push , 0x6006206d);             // NVC597_LOAD_INLINE_DATA
  PUSH_DATAl(push , (uint64_t)k);
  PUSH_DATAh(push , (uint64_t)k);
  PUSH_DATAl(push , (uint64_t)k);
  PUSH_DATAh(push , (uint64_t)k);
  PUSH_DATAl(push , (uint64_t)k + 0x400);
  PUSH_DATAh(push , (uint64_t)k + 0x400);

  PUSH_DATA(push , 0x20022062);           // NVC5C0_OFFSET_OUT_UPPER
  PUSH_DATAh(push , (uint64_t)0x7fffce221860);
  PUSH_DATAl(push , (uint64_t)0x7fffce221860);
  PUSH_DATA(push , 0X20022060);            // NVC5C0_LINE_LENGTH_IN
  PUSH_DATA(push , 0x20);
  PUSH_DATA(push , 0x1); 
  PUSH_DATA(push , 0x2001206c);            // NVC5C0_LAUNCH_DMA
  PUSH_DATA(push , 0x41);            

  PUSH_DATA(push , 0x6008206d);            // NVC597_LOAD_INLINE_DATA
  PUSH_DATAl(push , (uint64_t)0x7fffcfe3b300);
  PUSH_DATAh(push , (uint64_t)0x7fffcfe3b300);
  PUSH_DATA(push ,  0x0);
  PUSH_DATA(push ,  0x0);
  PUSH_DATA(push ,  0x0);
  PUSH_DATA(push ,  0x0);
  PUSH_DATA(push ,  0x1);
  PUSH_DATA(push ,  0x0);

  // IZGLEDA DA JE OVDE PROBLEM ????
  PUSH_DATA(push , 0x20022062);            // NVC5C0_OFFSET_OUT_UPPER
  PUSH_DATA(push ,  0x2);                  
  PUSH_DATA(push , 0x03007f7c);            // ovo nije dobr verovatno  0x205607000 
  PUSH_DATA(push , 0x20022060);            // NVC5C0_LINE_LENGTH_IN
  PUSH_DATA(push ,  0x4);                  
  PUSH_DATA(push ,  0x1);                  
  PUSH_DATA(push ,  0x2001206c);           // NVC5C0_LAUNCH_DMA
  PUSH_DATA(push ,  0x41);
  PUSH_DATA(push ,  0x6001206d);           // NVC597_LOAD_INLINE_DATA
  PUSH_DATA(push ,  0x5);                  
  // qmd //
  PUSH_DATA(push ,  0x204220c6);
  for(int i = 0 ; i < O ; i ++){PUSH_DATA(push ,  load_2[i]);}                  

  *((uint32_t*)0x200200018) = 0x40043c;
  *((uint32_t*)0x20020001c) = 0x34e02; //   
  *((uint32_t*)0x200202088)= 0x4;
  *((uint32_t*)0x20020208c)= 0x4; 
  *door_bell = 0x9;
  usleep(50000);

  //dump_small((void*)0x200400000 , (void*)0x203c00000);
  
  clear_nvctrl();
  push->cur = (uint32_t*)0x202c0005c;
  PUSH_DATA(push ,0x20048100); 
  PUSH_DATAh(push ,(uint64_t)k + 0x400); 
  PUSH_DATAl(push ,(uint64_t)k + 0x400);
  PUSH_DATAh(push ,(uint64_t)control_2);
  PUSH_DATAl(push ,(uint64_t)control_2);
  PUSH_DATA(push ,0x20018106);
  PUSH_DATA(push  , 0x28);
  BEGIN_NVC0(push ,0x4, NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE, 0x1);
  PUSH_DATA(push , 0x182);

  *((uint32_t*)0x200224010)= 0x2c0005c;
  *((uint32_t*)0x200224014)= 0x3e02;    
  *((uint32_t*)0x200226088)= 0x3;
  *((uint32_t*)0x20022608c) =0x3; 
  *door_bell = 0x9000a;
  usleep(50000);
  clear_nvctrl();

  hexdump((void*)control_2 , 0x20);
  return 0;
}



/*
interesantan fajl
/home/pa/ide_cuda/open-gpu-kernel-modules/src/common/unix/nvidia-push/interface/nvidia-push-init.h

  Submitting new work to a channel involves the following steps:

  1. Write methods to a pushbuffer segment
  2. Construct a new GP entry pointing to that pushbuffer segment
  3. Update GP_PUT in USERD to indicate the new GP entry is ready
  4. Request the doorbell handle from RM, given the channel ID
  5. Write the channel's handle to the NOTIFY_CHANNEL_PENDING register

  USERD is described in dev_ram.ref.  The formatting of the contents of a
pushbuffer segment is described in dev_ram.ref.  The formatting of a GP entry
and how it affects the processing of a pushbuffer segment is described in
dev_pbdma.ref.
*/