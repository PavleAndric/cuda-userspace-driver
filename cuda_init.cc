#include <stdio.h>
#include "nv_escape.h" 
#include "nvos.h" 
#include "nvtypes.h"
#include "clcb33.h"
#include "ctrl/ctrl0000/ctrl0000gpu.h"
#include "ctrl/ctrl0000/ctrl0000client.h"
#include "ctrl/ctrl2080/ctrl2080rc.h"
#include "ctrl/ctrl2080/ctrl2080gsp.h"
#include "ctrl/ctrl2080/ctrl2080gpu.h"

#include "cl0080.h"
#include "cl2080.h"
#include "clc461.h"
#include "cl50a0.h"
#include "cl90f1.h"
#include "cl0070.h"
#include "cl0040.h"
#include "cl9067.h"
#include "cla06c.h"

#include"nv-unix-nvos-params-wrappers.h"

#include <sys/ioctl.h>
#include <sys/mman.h>
#include <fcntl.h>

#include<stdint.h>
#include<assert.h>
#include"helpers.h"
#include<unistd.h>
#include <string.h> 

// Treba ti init
// Treba ti command buffer
// Mapiranje memorije 
// Alociranje i kernel launch, to je sve 
// NVOS21_PARAMETERS *pApi = data;

NvHandle alloc_object(int fd , NvHandle hroot ,NvHandle hObjectParent,NvV32 hClass ,NvP64 pAllocParams){
  
  NVOS21_PARAMETERS object = {.hRoot = hroot,.hObjectParent = hObjectParent,.hClass =hClass,.pAllocParms = pAllocParams,.paramsSize = 0};
  int res = ioctl(fd, _IOC(_IOC_READ|_IOC_WRITE, 0x46, NV_ESC_RM_ALLOC, sizeof(object)), &object);

  printf("%x %x \n" ,object.status ,res);
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

  //virtual
  NV_MEMORY_ALLOCATION_PARAMS romcina = {.owner = (NvU32)root_ , .flags = 0x8c415 ,.size= 0xfb000000,.offset = 0x5000000 ,.hVASpace=o56}; 
  NvHandle o58 = alloc_object(control_fd, root_ ,o52, NV50_MEMORY_VIRTUAL, &romcina);  

  NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS p_= {.hObject =o54 , .mapFlags=0x80002 , .addrSpaceType = 0};
  ctrl(control_fd , root_ , root_ ,NV0000_CTRL_CMD_CLIENT_GET_ADDR_SPACE_TYPE,0, &p_  ,sizeof(p_));
  void *bar_start = rm_map_mem(control_fd , root_, o53, o54, 0,0x10000, NULL, p_.mapFlags);

  NV2080_CTRL_GSP_GET_FEATURES_PARAMS gps_ = {.gspFeatures =  0 , .bValid = 0 , .bDefaultGspRmGpu =0,.firmwareVersion = {0}};
  ctrl(control_fd , root_, o53 ,NV2080_CTRL_CMD_GSP_GET_FEATURES , 0, &gps_ , sizeof(gps_));

  NV2080_CTRL_GPU_GET_GID_INFO_PARAMS gid = {0}; gid.flags = 0x2;
  ctrl(control_fd , root_, o53 ,NV2080_CTRL_CMD_GPU_GET_GID_INFO , 0, &gid , sizeof(gid));
  //ctrl(control_fd , root_, o53 ,0x20800145 , 0, NULL , 0);

  NV_CHANNEL_GROUP_ALLOCATION_PARAMETERS k_g = {.hObjectError = 0 , .hObjectEccError = 0  , .hVASpace= 0 , .engineType = 1};
  NvHandle kepler_group =  alloc_object(control_fd, root_ ,o52, KEPLER_CHANNEL_GROUP_A, &k_g);  
  
  NV_CTXSHARE_ALLOCATION_PARAMETERS f_c  = {.hVASpace = o55 , .flags = 1 ,.subctxId = 0}; // NV_CTXSHARE_ALLOCATION_PARAMETERS f_c  = {.hVASpace = o55 , .flags = 1 ,.subctxId = 0x0};
  NvHandle fermi_context =  alloc_object(control_fd, root_ ,kepler_group, FERMI_CONTEXT_SHARE_A, &f_c); 

  //KEPLER_CHANNEL_GROUP_A  //0x0000a06c
  //FERMI_CONTEXT_SHARE_A // 0x00009067


  //Nv01MemoryLocalUser dummy_obj = {0};
  //NvHandle first_ = alloc_object(control_fd, root_, o52 ,0x40, (void*)&dummy_obj);
  return 0;
}

/*uint64_t r = (uint64_t)bar_start + 0x10000;
for(uint64_t *ptr = (uint64_t*)bar_start; ptr < (uint64_t*)(r);  ++ptr){if(*ptr){printf("%p :%lx \n" , ptr , *ptr) ;}}*/
/*
DEPRECATED_CONTEXT
/home/pa/ide_cuda/open-gpu-kernel-modules/src/nvidia/interface/deprecated/rmapi_deprecated_allocmemory.c

interesantan fajl
/home/pa/ide_cuda/open-gpu-kernel-modules/src/common/unix/nvidia-push/interface/nvidia-push-init.h

# on  od tebe vec hoce da imas objekat
void
RmDeprecatedAllocMemory
(
    DEPRECATED_CONTEXT *pContext,
    NVOS02_PARAMETERS  *pArgs
)
{
    NV_STATUS status = NV_OK;
    NvU32     i;

    // traverse through the table to match the hClass
    for (i = 0; i < rmAllocMemoryTableSize; i++)
    {
        if (pArgs->hClass == rmAllocMemoryTable[i].hclass)
        {
            break;
        }
    }

    // check that we have a valid handler
    if (i == rmAllocMemoryTableSize)
    {
        status = NV_ERR_INVALID_CLASS;
        goto done;
    }

    // call the function in rmAllocMemoryTable corresponding to hClass
    status = rmAllocMemoryTable[i].pFunc(pContext,
                                         pArgs->hRoot,
                                         pArgs->hObjectParent,
                                         pArgs->hObjectNew,
                                         pArgs->hClass,
                                         pArgs->flags,
                                         &pArgs->pMemory,
                                         &pArgs->limit);

done:
    pArgs->status = status;
}


typedef struct
{
    NvHandle    hRoot;
    NvHandle    hObjectParent;
    NvHandle    hObjectNew;
    NvV32       hClass;
    NvV32       flags;
    NvP64       pMemory NV_ALIGN_BYTES(8);
    NvU64       limit NV_ALIGN_BYTES(8);
    NvV32       status;
} NVOS02_PARAMETERS;
*/