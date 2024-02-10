#include <stdio.h>
//nv
#include "nv_escape.h" 
#include "nvos.h" 
#include "nvtypes.h"
#include "clcb33.h"
#include "ctrl/ctrl0000/ctrl0000gpu.h"
#include "ctrl/ctrl0000/ctrl0000client.h"
#include "cl0080.h"
#include "cl2080.h"
#include "clc461.h"

#include "nv-unix-nvos-params-wrappers.h"

// sys 
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <fcntl.h>


#include<stdint.h>
#include<assert.h>
#include"helpers.h"
#include <unistd.h>


// Treba ti init
// Treba ti command buffer
// Mapiranje memorije 
// Alociranje i kernel launch, to je sve 
// NVOS21_PARAMETERS *pApi = data;


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
  return mmap64(NULL, 0x10000, PROT_READ|PROT_WRITE, MAP_SHARED, nv_0, 0); 
}

int main(){ 

  // ROOT
  int control_fd = open64( "/dev/nvidiactl", O_RDWR);
  int nv0_fd = open64("/dev/nvidia0", O_RDWR | O_CLOEXEC);

  NvHandle root_ = alloc_object(control_fd, 0, 0, NV01_ROOT_CLIENT,NULL);

  NV0000_CTRL_GPU_GET_DEVICE_IDS_PARAMS p = {0};
  ctrl(control_fd,root_, root_, NV0000_CTRL_CMD_GPU_GET_DEVICE_IDS,0, &p, sizeof(p));
  
  //sub 
  NV0080_ALLOC_PARAMETERS p_80 = {.deviceId=0x0,.hClientShare=root_,.hTargetClient=0,.hTargetDevice=0,.flags=0,.vaSpaceSize=0,.vaStartInternal=0,.vaLimitInternal=0,.vaMode=0x2};
  NvHandle o52 = alloc_object(control_fd, root_ ,root_, NV01_DEVICE_0, &p_80);

  NV2080_ALLOC_PARAMETERS p_2080 = {.subDeviceId = 0x0};
  NvHandle o53 = alloc_object(control_fd, root_ ,o52, NV20_SUBDEVICE_0, &p_2080);

  NvHandle o54 = alloc_object(control_fd, root_ ,o53, TURING_USERMODE_A, NULL); 

  NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS p_= {.hObject =o54 , .mapFlags=0x80002 , .addrSpaceType = 0};
  ctrl(control_fd , root_ , root_ ,NV0000_CTRL_CMD_CLIENT_GET_ADDR_SPACE_TYPE,0, &p_  ,sizeof(p_));
  
  void *res = rm_map_mem(control_fd , root_, o53, o54, 0,0x10000, NULL, p_.mapFlags);

  uint64_t r = (uint64_t)res + 0x10000;
  for(uint64_t *ptr = (uint64_t*)res; ptr < (uint64_t*)(r);  ++ptr){if(*ptr){printf("%p :%lx \n" , ptr , *ptr) ;}}
  map(getpid());
  return 0;
}
