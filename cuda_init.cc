#include<stdio.h>
#include"nv_escape.h" 
#include"nvos.h" 
#include"nvtypes.h"
#include"uvm_ioctl.h"
#include"nvCpuUuid.h"
#include"uvm_linux_ioctl.h"
#include"nv-ioctl.h"
#include"rmapi_deprecated.h"

#include "ctrl/ctrl0000/ctrl0000gpu.h"
#include "ctrl/ctrl0000/ctrl0000client.h"
#include "ctrl/ctrl2080/ctrl2080rc.h"
#include "ctrl/ctrl2080/ctrl2080gsp.h"
#include "ctrl/ctrl2080/ctrl2080gpu.h"


#include "cl003e.h"
#include "clcb33.h"
#include "cl0080.h"
#include "cl2080.h"
#include "clc461.h"
#include "cl50a0.h"
#include "cl90f1.h"
#include "cl0070.h"
#include "cl0040.h"
#include "cl9067.h"
#include "cla06c.h"
#include "cl00c2.h"
#include "cl0070.h"

#include"nv-unix-nvos-params-wrappers.h"

#include <sys/ioctl.h>
#include <sys/mman.h>
#include <fcntl.h>

#include<stdint.h>
#include<assert.h>
#include"helpers.h"
#include<unistd.h>
#include <string.h> 
#include <dlfcn.h>

NvU8 uud[16] = {0x9f,0xa6,0xcc,0x3,0x56,0xa2,0x1f,0x6b,0x26,0x26,0x8,0x90,0xb,0xbd,0xb4,0x94}; 

// Treba ti init
// Treba ti context
// Mapiranje memorije 
// Treba ti command buffer
// Alociranje i kernel launch, to je sve  

NvHandle alloc_object(int fd , NvHandle hroot ,NvHandle hObjectParent,NvV32 hClass ,NvP64 pAllocParams){
  
  NVOS21_PARAMETERS object = {.hRoot = hroot,.hObjectParent = hObjectParent,.hClass =hClass,.pAllocParms = pAllocParams,.paramsSize = 0};
  int res = ioctl(fd, _IOC(_IOC_READ|_IOC_WRITE, 0x46, NV_ESC_RM_ALLOC, sizeof(object)), &object);

  //printf("%x %x \n" ,object.status ,res);
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
void *map_object(int mapping_fd, int control_fd, NvHandle root_, NvHandle device, NvHandle subDevice, NvHandle mappingObject , uint32_t mapFlags , uint32_t addrSpaceType ,uint32_t lenght, void* addr){

  NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS params ={ .hObject = mappingObject,.mapFlags = mapFlags};
  NVOS33_PARAMETERS p = {.hClient = root_, .hDevice = subDevice,.hMemory = mappingObject, .length=lenght,.flags=mapFlags};
  nv_ioctl_nvos33_parameters_with_fd map_params = {.params = p ,.fd  = mapping_fd}; // OVO NIJE OX4 ALI SAMO  TAKO RADI ????? HEX TE JE ZAJEBAO

  ctrl(control_fd, root_, root_, NV0000_CTRL_CMD_CLIENT_GET_ADDR_SPACE_TYPE, 0 ,&params , sizeof(params));
  int res_map = ioctl(control_fd, _IOC(_IOC_READ|_IOC_WRITE, 0x46, NV_ESC_RM_MAP_MEMORY, sizeof(map_params)), &map_params);
  void *res = mmap64(addr , lenght, PROT_READ|PROT_WRITE , MAP_SHARED|MAP_FIXED, mapping_fd, 0);

  ///printf("%x %x %x \n",map_params.params.status, p.status, res_map);
  assert(map_params.params.status == 0);assert(p.status == 0);assert(res_map == 0);
  return res;
}

int main(){ 

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
  void *big_map = mmap64((void*)0x200000000 ,0x100200000 , PROT_READ|PROT_WRITE , MAP_PRIVATE|MAP_ANONYMOUS ,-1,0); assert(big_map != NULL);
  /// INIT DONE ///

  /// CONTEXT BEGIN ///
  //register vaspace params
  UVM_REGISTER_GPU_VASPACE_PARAMS register_ = {.rmCtrlFd = control_fd , .hClient = root_ , .hVaSpace = o55};
  memcpy((void*)register_.gpuUuid.uuid , (void*)uud ,sizeof(register_.gpuUuid.uuid));
  int res =  ioctl(nv_uvm_fd, UVM_REGISTER_GPU_VASPACE, &register_); assert(res == 0);

  //BAR
  NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS p_= {.hObject =o54 , .mapFlags=0x80002 , .addrSpaceType = 0};
  ctrl(control_fd , root_ , root_ ,NV0000_CTRL_CMD_CLIENT_GET_ADDR_SPACE_TYPE,0, &p_  ,sizeof(p_));
  void *bar_start = rm_map_mem(control_fd , root_, o53, o54, 0,0x10000, NULL, p_.mapFlags);
  printf("BAR -> %p \n" ,bar_start);

  //
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
  void* nv_gas_ =  map_object(new_nv0 ,control_fd, root_, o52, o53, nv_0_object, 0xc0000, 0x0, 0x200000 , (void*)0x200200000); close(new_nv0);
  printf("/dev/nvidia0 -> %p\n" , nv_gas_);

  // UPDATE MAPPING INFO
  NVOS56_PARAMETERS update = {.hClient = root_ ,.hDevice = o53,.hMemory =nv_0_object ,.pOldCpuAddress = (void*)0xb02e0000,.pNewCpuAddress = (void*)0x200200000};
  int mapping_res = ioctl(control_fd, _IOC(_IOC_READ|_IOC_WRITE, 0x46, NV_ESC_RM_UPDATE_DEVICE_MAPPING_INFO, sizeof(update)), &update); 
  assert(mapping_res == 0); assert(update.status == 0);
  uvm_external_range(0x200200000 , 0x200000 ,nv_0_object, root_,control_fd , nv_uvm_fd);

  //MMAP NV_CTRLs
  NV_MEMORY_ALLOCATION_PARAMS nv_ctrl_mapping {   
    .owner = root_,
    .flags = 0xc001,
    .attr = 0x5a000000,
    .size = 0x3800000,
  };
  int new_ctrl = openat(AT_FDCWD, "/dev/nvidiactl", O_RDWR|O_CLOEXEC);
  NvHandle nv_crtl_object = alloc_object(control_fd, root_, o52, NV01_MEMORY_SYSTEM, (void*)&nv_ctrl_mapping);   
  void* nv_ctrl_gas =  map_object(new_ctrl ,control_fd, root_, o52, o53, nv_crtl_object, 0xc0000, 0x0, 0x3800000 , (void*)0x200400000); close(new_ctrl);
  printf("/dev/nvidiactrl -> %p\n" ,nv_ctrl_gas);
  uvm_external_range(0x200400000 , 0x3800000 ,nv_crtl_object, root_,control_fd , nv_uvm_fd);
  return 0;
}

/*
  c46f TURING_CHANNEL_GPFIFO_A cesto UVEK ima decu,
  TURING_DMA_COPY_A c5b5 NIKAD NEMA DECU
  TURING_COMPUTE_A c5c0 SAMO pri prvom objektu(TURING_CHANNEL_GPFIFO_A) ima decu, ovo (5c00008b 5c00008c 5c00008d 5c00008e) , decu su sva 79 NV01_EVENT_OS_EVENT


  Object 5c000017:c46f : children{
     		       5c000018 (c5c0) 5c000019 (c5b5)}


 /home/pa/ide_cuda/open-gpu-kernel-modules/src/nvidia/arch/nvalloc/unix/src/vbioscall.c FLAGOVI ZA MAPP
 NV2080_CTRL_CMD_GR_GET_INFO je potreban ! 
 In case we are trying to find memory allocated by a process running
 on a VM - the case where isGuestProcess is true, only consider the
 memory :
 1. which is allocated by the guest VM or by a process running in it.
 2. if the memory is not tagged with NVOS32_TYPE_UNUSED type.
    Windows KMD and Linux X driver makes dummy allocations which is
    done using NV01_MEMORY_LOCAL_USER class with rmAllocMemory()
    function.
    On VGX, while passing this allocation in RPC, we use the memory
    type NVOS32_TYPE_UNUSED. So while calculating the per process FB
    usage, only consider the allocation if memory type is not
    NVOS32_TYPE_UNUSED.
*/
/*
DEPRECATED_CONTEXT
/home/pa/ide_cuda/open-gpu-kernel-modules/src/nvidia/interface/deprecated/rmapi_deprecated_allocmemory.c
interesantan fajl
/home/pa/ide_cuda/open-gpu-kernel-modules/src/common/unix/nvidia-push/interface/nvidia-push-init.h
*/