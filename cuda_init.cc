#include <stdio.h>
#include "nv_escape.h" 
#include "nvos.h" 
#include "nvtypes.h"
#include "uvm_ioctl.h"
#include "nvCpuUuid.h"
#include "uvm_linux_ioctl.h"
#include "nv-ioctl.h"

#include "ctrl/ctrl0000/ctrl0000gpu.h"
#include "ctrl/ctrl0000/ctrl0000client.h"
#include "ctrl/ctrl2080/ctrl2080rc.h"
#include "ctrl/ctrl2080/ctrl2080gsp.h"
#include "ctrl/ctrl2080/ctrl2080gpu.h"


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
#include "clcb33.h"

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
// Treba ti command buffer
// Mapiranje memorije 
// Alociranje i kernel launch, to je sve 
// NVOS21_PARAMETERS *pApi = data;

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
  return mmap64(NULL, 0x10000, PROT_READ|PROT_WRITE, MAP_SHARED, nv_0, 0); 
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

int main(){ 

  // ROOT
  int control_fd = open64( "/dev/nvidiactl", O_RDWR);
  int nv0_fd = open64("/dev/nvidia0", O_RDWR | O_CLOEXEC);
  int nv_uvm_fd = open64("/dev/nvidia-uvm", O_RDWR | O_CLOEXEC);

  nv_ioctl_card_info_t args = {0};
  int res_0 = ioctl(control_fd, _IOC(_IOC_READ|_IOC_WRITE, 0x46, 0xc8, sizeof(args)), &args);

  //ROOT
  NvHandle root_ = alloc_object(control_fd, 0, 0, NV01_ROOT_CLIENT, NULL);

  NV_CONFIDENTIAL_COMPUTE_ALLOC_PARAMS conf = {.hClient = root_};
  NvHandle confidential = alloc_object(control_fd, root_ ,root_, NV_CONFIDENTIAL_COMPUTE, &conf);
  init_uvm(nv_uvm_fd);
  //exit(1);

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

  second_uvm(nv_uvm_fd);
  //virtual
  NV_MEMORY_ALLOCATION_PARAMS romcina = {.owner = (NvU32)root_ , .flags = 0x8c415 ,.size= 0xfb000000,.offset = 0x5000000 ,.hVASpace=o56}; 
  NvHandle o58 = alloc_object(control_fd, root_ ,o52, NV50_MEMORY_VIRTUAL, &romcina);  
  /// INIT DONE ///

  // START_CONTEXT 
  NV2080_CTRL_GSP_GET_FEATURES_PARAMS gps_ = {.gspFeatures =  0 , .bValid = 0 , .bDefaultGspRmGpu =0,.firmwareVersion = {0}};
  ctrl(control_fd , root_, o53 ,NV2080_CTRL_CMD_GSP_GET_FEATURES , 0, &gps_ , sizeof(gps_));
  // register
  UVM_REGISTER_GPU_VASPACE_PARAMS register_ = {.rmCtrlFd = control_fd , .hClient = root_ , .hVaSpace = o55};
  memcpy((void*)register_.gpuUuid.uuid , (void*)uud ,sizeof(register_.gpuUuid.uuid));
  int res =  ioctl(nv_uvm_fd, UVM_REGISTER_GPU_VASPACE, &register_); //assert(res != 0);

  NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS p_= {.hObject =o54 , .mapFlags=0x80002 , .addrSpaceType = 0};
  ctrl(control_fd , root_ , root_ ,NV0000_CTRL_CMD_CLIENT_GET_ADDR_SPACE_TYPE,0, &p_  ,sizeof(p_));
  void *bar_start = rm_map_mem(control_fd , root_, o53, o54, 0,0x10000, NULL, p_.mapFlags);

  NV2080_CTRL_GPU_GET_GID_INFO_PARAMS gid = {0}; gid.flags = 0x2;
  ctrl(control_fd , root_, o53 ,NV2080_CTRL_CMD_GPU_GET_GID_INFO , 0, &gid , sizeof(gid));

  NV_CHANNEL_GROUP_ALLOCATION_PARAMETERS k_g = {.hObjectError = 0 , .hObjectEccError = 0  , .hVASpace= 0 , .engineType = 1};
  NvHandle kepler_group =  alloc_object(control_fd, root_ ,o52, KEPLER_CHANNEL_GROUP_A, &k_g);  

  NV_CTXSHARE_ALLOCATION_PARAMETERS f_c  = {.hVASpace = o55 , .flags = 1 ,.subctxId = 0}; 
  NvHandle fermi_context =  alloc_object(control_fd, root_ ,kepler_group, FERMI_CONTEXT_SHARE_A, &f_c); 

  //KEPLER_CHANNEL_GROUP_A  //0x0000a06c
  //FERMI_CONTEXT_SHARE_A // 0x00009067
  //Nv01MemoryLocalUser dummy_obj = {0};dummy_obj.Reserved00[0] = root_;
  //NvHandle first_ = alloc_object(control_fd, root_, o52 ,0x40, (void*)&dummy_obj);
  return 0;
}

/*uint64_t r = (uint64_t)bar_start + 0x10000;
for(uint64_t *ptr = (uint64_t*)bar_start; ptr < (uint64_t*)(r);  ++ptr){if(*ptr){printf("%p :%lx \n" , ptr , *ptr) ;}}*/

/*

NV0000_CTRL_GPU_GET_DEVICE_IDS_PARAMS p = {0};
  ctrl(control_fd,root_, root_, NV0000_CTRL_CMD_GPU_GET_DEVICE_IDS,0, &p, sizeof(p));


//CONFIDENTIAL
  
DEPRECATED_CONTEXT
/home/pa/ide_cuda/open-gpu-kernel-modules/src/nvidia/interface/deprecated/rmapi_deprecated_allocmemory.c

interesantan fajl
/home/pa/ide_cuda/open-gpu-kernel-modules/src/common/unix/nvidia-push/interface/nvidia-push-init.h


//NV0000_CTRL_GPU_ATTACH_IDS_PARAMS p_0 = {0};
//p_0.gpuIds[0] = 0x100;p_0.gpuIds[1] = 0xffffffff;
//ctrl(control_fd , root_, root_ ,NV0000_CTRL_CMD_GPU_ATTACH_IDS , 0, &p_0 , sizeof(p_0));

# on  od tebe vec hoce da imas objekat
void
RmDeprecatedAllocMemory
void pretty_print( UVM_MAP_EXTERNAL_ALLOCATION_PARAMS* p_){
  printf("UVM_MAP_EXTERNAL_ALLOCATION_PARAMS\n");
    printf("	base                %llx\n",p_->base) ;
    printf("	length              %llx\n",p_->length) ;
    printf("	offset              %llx\n",p_->offset) ;
    printf("	perGpuAttributes    %p\n",p_->perGpuAttributes);
    for(int i = 0; i < 32; i++){
      printf("perGpuAttributes[%d]\n" , i);
      for(int j = 0 ; j < 16 ; j ++){
      if(j % 8 == 0)printf("\n");
        printf("uud[%02d][%02d] = %x " ,i,j,p_->perGpuAttributes[i].gpuUuid.uuid[j]);
      }printf("\n");
      printf("p_->perGpuAttributes[%d].gpuMappingType = %x\n" ,i,p_->perGpuAttributes[i].gpuMappingType);
      printf("p_->perGpuAttributes[%d].gpuCachingType = %x\n" ,i,p_->perGpuAttributes[i].gpuCachingType);
      printf("p_->perGpuAttributes[%d].gpuFormatType = %x\n" ,i,p_->perGpuAttributes[i].gpuFormatType);
      printf("p_->perGpuAttributes[%d].gpuElementBits = %x\n" ,i,p_->perGpuAttributes[i].gpuElementBits);
      printf("p_->perGpuAttributes[%d].gpuCompressionType = %x\n" ,i,p_->perGpuAttributes[i].gpuCompressionType);
    }
    printf("	gpuAttributesCount  %llx\n",p_->gpuAttributesCount) ;
    printf("	rmCtrlFd            %lx\n",(uint64_t)(p_->rmCtrlFd) );
    printf("	hClient             %x\n",p_->hClient) ;
    printf("	hMemory             %x\n",p_->hMemory) ;
    printf("	rmStatus            %lx\n",(uint64_t)(p_->rmStatus) );
}
*/