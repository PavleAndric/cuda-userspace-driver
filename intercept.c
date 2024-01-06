#define _GNU_SOURCE
#define _FCNTL_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> 
#include <stdint.h>
#include <dlfcn.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <bits/fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/mman.h>
#include <sys/ptrace.h>
#include <sys/wait.h>

#include "nvos.h" 
#include "nv-ioctl.h"
#include "nv-ioctl-numa.h" 
#include "nv_escape.h"
#include "nvtypes.h"
#include "nv-unix-nvos-params-wrappers.h"
#include "ctrl00fd.h"
#include "ctrl0000system.h"
#include "ctrl0000client.h"
#include "ctrl0000gpu.h"
#include "ctrl0000syncgpuboost.h"
#include "ctrl0002.h"
#include "ctrl2080bus.h"
#include "ctrl2080gpu.h"
#include "ctrl0080gpu.h"
#include "ctrl2080fb.h"
#include "ctrl2080mc.h"
#include "ctrl0000gpu.h"
#include "ctrl2080ce.h"
#include "ctrl0080fb.h"
#include "ctrl2080rc.h"
#include "ctrl2080rc.h"
#include "ctrl2080nvlink.h"
#include "clc461.h"

//int open(const char *pathname, int flags);
void print_hex(const void *buf, size_t count) {
    const uint8_t *data = buf;
    for (size_t i = 0; i < count; ++i) {
        printf("%02X ", data[i]);
    }
    putchar('\n');
}

int br = 0;
int (*my_ioctl)(int filedes, unsigned long request, void *argp) = NULL;
int ioctl(int filedes,  unsigned long request ,void *argp){
  
  uint8_t type_ = (request >> 8) & 0xFF;
  uint8_t nr = request & 0xFF;
  uint16_t size = (request >> 16 ) & 0xFFF;

  br = br + 1;
  if (type_ == NV_IOCTL_MAGIC){
    printf("br=%d fd=%d, size=0x%x ", br, filedes , size);
    if (nr ==  NV_ESC_CARD_INFO){ printf("NV_ESC_CARD_INFO\n");}
    else if  (nr == NV_ESC_REGISTER_FD) {printf("NV_ESC_REGISTER_FD \n" );}
    else if  (nr == NV_ESC_ALLOC_OS_EVENT) { printf("NV_ESC_ALLOC_OS_EVENT\n");}
    // setting up shit -- -- -- 
    else if  (nr == NV_ESC_SYS_PARAMS) {
      nv_ioctl_sys_params_t *p = argp; 
      printf("NV_ESC_SYS_PARAMS\n");  
      printf("\t**** block_size=%llx \n" , p->memblock_size); //ovo je uvek 134217728
    }
    else if  (nr == NV_ESC_NUMA_INFO){
      nv_ioctl_numa_info_t *p = argp;
      printf("NV_ESC_NUMA_INFO\n"); // ovo je beskorisno
      printf("\t**** %" PRIu64 "\n", p->memblock_size);
      printf("\t**** %" PRIu64 "\n", p->numa_mem_addr);
      printf("\t**** %" PRIu64 "\n", p->numa_mem_size);
    } 
    // -- -- -- -- -- -- -- -- -
    else if  (nr == NV_ESC_RM_CONTROL) { 
      NVOS54_PARAMETERS *p = argp; //#define RS_CLIENT_HANDLE_BASE 0xC1D00000 // Client handles must start at this base value
      unsigned cm  = p->cmd; 
      //br=41 fd=8, size=0x20 NV_ESC_RM_CONTROL paramzie=16, params=0x7ffc5c447290, hObj=5c000003 sizeof(NV00FD_CTRL_ATTACH_GPU_PARAMS) ima jos jedan ovo  je 16 
      printf("NV_ESC_RM_CONTROL paramzie=%d, params=%p, hObj=%x\n" ,p->paramsSize ,p->params, p->hObject); // flag is  always 0  ,Client is always the same
      /*
      switch(cm){
        case NV00FD_CTRL_CMD_ATTACH_GPU:{ printf("\t****NV00FD_CTRL_CMD_ATTACH_GPU\n"); break;} // odje mozes da kastujes // NV00FD_CTRL_ATTACH_GPU_PARAMS *pAttachGpuParams = pKernelParams;
        case NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION: { printf("\t****NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION\n"); break;}
        case NV0000_CTRL_CMD_CLIENT_SET_INHERITED_SHARE_POLICY: { printf("\t****NV0000_CTRL_CMD_CLIENT_SET_INHERITED_SHARE_POLICY\n"); break;}
        case NV0000_CTRL_CMD_GPU_GET_PROBED_IDS: { printf("\t****NV0000_CTRL_CMD_GPU_GET_PROBED_IDS\n"); break;}
        case NV0000_CTRL_CMD_SYNC_GPU_BOOST_GROUP_INFO: { printf("\t****NV0000_CTRL_CMD_SYNC_GPU_BOOST_GROUP_INFO\n"); break;}
        case NV0000_CTRL_CMD_GPU_ATTACH_IDS: { printf("\t****NV0000_CTRL_CMD_GPU_ATTACH_IDS\n"); break;}
        case NV0000_CTRL_CMD_GPU_GET_ID_INFO_V2: { printf("\t****NV0000_CTRL_CMD_GPU_GET_ID_INFO_V2\n"); break;}
        case NV0002_CTRL_CMD_UPDATE_CONTEXTDMA: { printf("\t****NV0002_CTRL_CMD_UPDATE_CONTEXTDMA\n"); break;}
        case NV2080_CTRL_CMD_GPU_GET_ACTIVE_PARTITION_IDS: { printf("\t****NV2080_CTRL_CMD_GPU_GET_ACTIVE_PARTITION_IDS\n"); break;}
        case NV2080_CTRL_CMD_GPU_GET_GID_INFO: { printf("\t****NV2080_CTRL_CMD_GPU_GET_GID_INFO\n"); break;}
        case NV0080_CTRL_CMD_GPU_GET_VIRTUALIZATION_MODE: { printf("\t****NV0080_CTRL_CMD_GPU_GET_VIRTUALIZATION_MODE\n"); break;}
        case NV0080_CTRL_CMD_GPU_GET_SPARSE_TEXTURE_COMPUTE_MODE: { printf("\t****NV0080_CTRL_CMD_GPU_GET_SPARSE_TEXTURE_COMPUTE_MODE\n"); break;}
        case NV2080_CTRL_CMD_BUS_GET_PCI_INFO: { printf("\t****NV2080_CTRL_CMD_BUS_GET_PCI_INFO\n"); break;}
        case NV2080_CTRL_CMD_FB_GET_INFO_V2: { printf("\t****NV2080_CTRL_CMD_FB_GET_INFO_V2\n"); break;}
        case NV2080_CTRL_CMD_GPU_GET_INFO_V2: { printf("\t****NV2080_CTRL_CMD_GPU_GET_INFO_V2\n"); break;}
        case NV2080_CTRL_CMD_MC_GET_ARCH_INFO: { printf("\t****NV2080_CTRL_CMD_MC_GET_ARCH_INFO\n"); break;} // his command returns chip architecture information from the * master control engine in the specified GPU.
        case NV2080_CTRL_CMD_BUS_GET_INFO_V2: { printf("\t****NV2080_CTRL_CMD_BUS_GET_INFO_V2\n"); break;}
        case NV2080_CTRL_CMD_BUS_GET_PCI_BAR_INFO: { printf("\t****NV2080_CTRL_CMD_BUS_GET_PCI_BAR_INFO\n"); break;}
        case NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS: { printf("\t****NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS\n"); break;}
        case NV2080_CTRL_CMD_GPU_GET_SIMULATION_INFO: { printf("\t****NV2080_CTRL_CMD_GPU_GET_SIMULATION_INFO\n"); break;}
        case NV0000_CTRL_CMD_GPU_GET_MEMOP_ENABLE: { printf("\t****NV0000_CTRL_CMD_GPU_GET_MEMOP_ENABLE\n"); break;}
        case NV2080_CTRL_CMD_GPU_GET_ENGINES_V2: { printf("\t****NV2080_CTRL_CMD_GPU_GET_ENGINES_V2\n"); break;}
        case NV2080_CTRL_CMD_GR_GET_TPC_MASK: { printf("\t****NV2080_CTRL_CMD_GR_GET_TPC_MASK\n"); break;}
        case NV2080_CTRL_CMD_GR_GET_CAPS_V2: { printf("\t****NV2080_CTRL_CMD_GR_GET_CAPS_V2\n"); break;}
        case NV2080_CTRL_CMD_CE_GET_ALL_CAPS: { printf("\t****NV2080_CTRL_CMD_CE_GET_ALL_CAPS\n"); break;}
        case NV2080_CTRL_CMD_GR_GET_INFO: { printf("\t****NV2080_CTRL_CMD_GR_GET_INFO\n"); break;}
        case NV2080_CTRL_CMD_GR_GET_GPC_MASK: { printf("\t****NV2080_CTRL_CMD_GR_GET_GPC_MASK\n"); break;}
        case NV2080_CTRL_CMD_GR_GET_GLOBAL_SM_ORDER: { printf("\t****NV2080_CTRL_CMD_GR_GET_GLOBAL_SM_ORDER\n"); break;}
        case NV0080_CTRL_CMD_FB_GET_CAPS_V2: { printf("\t****NV0080_CTRL_CMD_FB_GET_CAPS_V2\n"); break;}
        case NV2080_CTRL_CMD_GPU_QUERY_ECC_STATUS: { printf("\t****NV2080_CTRL_CMD_GPU_QUERY_ECC_STATUS\n"); break;}
        case NV2080_CTRL_CMD_GPU_GET_SHORT_NAME_STRING: { printf("\t****NV2080_CTRL_CMD_GPU_GET_SHORT_NAME_STRING\n"); break;}
        case NV2080_CTRL_CMD_GPU_GET_NAME_STRING: { printf("\t****NV2080_CTRL_CMD_GPU_GET_NAME_STRING\n"); break;}
        case NV2080_CTRL_CMD_GPU_QUERY_COMPUTE_MODE_RULES: { printf("\t****NV2080_CTRL_CMD_GPU_QUERY_COMPUTE_MODE_RULES\n"); break;}
        case NV0000_CTRL_CMD_SYSTEM_GET_FABRIC_STATUS: { printf("\t****NV0000_CTRL_CMD_SYSTEM_GET_FABRIC_STATUS\n"); break;}
        case NV2080_CTRL_CMD_RC_RELEASE_WATCHDOG_REQUESTS: { printf("\t****NV2080_CTRL_CMD_RC_RELEASE_WATCHDOG_REQUESTS\n"); break;}
        case NV2080_CTRL_CMD_RC_SOFT_DISABLE_WATCHDOG: { printf("\t****NV2080_CTRL_CMD_RC_SOFT_DISABLE_WATCHDOG\n"); break;}
        case NV2080_CTRL_CMD_BUS_GET_C2C_INFO: { printf("\t****NV2080_CTRL_CMD_BUS_GET_C2C_INFO\n"); break;}
        case NV2080_CTRL_CMD_NVLINK_GET_NVLINK_STATUS: { printf("\t****NV2080_CTRL_CMD_NVLINK_GET_NVLINK_STATUS\n"); break;}
      }*/
    }
    
    // ALLOC
    else if  (nr == NV_ESC_RM_ALLOC){ // #define NV_ESC_RM_ALLOC mislim da je ovaj bitan , i dinamitan
      
      NVOS64_PARAMETERS *p_ = argp; //int size_ = p_ -> paramsSize; ovo  je uvek nula
      NVOS21_PARAMETERS *p = (NVOS21_PARAMETERS *)argp;
      printf("NV_ESC_RM_ALLOC\n");
      printf("\t**** pObjparent %x \n" , p->hObjectParent); 
      printf("\t**** pObjnew %x \n" , p->hObjectNew);
      printf("\t**** pallocparams %p \n" ,  p->pAllocParms);
      printf("\t**** hclass %x \n" ,  p->hClass);  //home/pa/ide_cuda/open-gpu-kernel-modules/src/common/sdk/nvidia/inc/class/clc461.h
      printf("\t**** pRightsRequested %p\n" ,  p_->pRightsRequested); // ovo je cudno

      
      //if(p-> paramsSize){printf("\t****param_size_1= %d\n", p->paramsSize);} // ovo je cudno ovaj je uvek 0
      //if(p_-> paramsSize){printf("\t****param_size_2= %d\n", p_->paramsSize);} // ovo je cudno // ovaj  je  na prvom  pozivu uvek  3
      if (p_->flags){printf("\t**** flag FINN serialization  = %d  \n" , p_->flags);}
    }
    // FREE
    else if (nr == NV_ESC_RM_FREE){
      NVOS00_PARAMETERS *p = (NVOS00_PARAMETERS*) argp;
      printf("NV_ESC_RM_FREE %x %x  \n" , p->hObjectParent , p->hObjectOld);
    }
    else if  (nr == NV_ESC_RM_MAP_MEMORY){
      nv_ioctl_nvos33_parameters_with_fd *p = argp;
      printf("NV_ESC_RM_MAP_MEMORY\n");
      printf("\t****hmem %x  \n",(p->params).hMemory);
      printf("\t****len is size %lld\n",(p->params).length);
      printf("\t****offset %llx\n",(p->params).offset);
      printf("\t****flags %x  \n",(p->params).flags);
      printf("\t****linaddr %p \n",(p->params).pLinearAddress);
      printf("\t****hDevice %x  \n",(p->params).hDevice); // 
      printf("\t****hClient %x  \n",(p->params).hClient); // 
      printf("\t****status %d\n",(p->params).status);   // NV_OK je 0
    } 
    else if  (nr == NV_ESC_RM_UPDATE_DEVICE_MAPPING_INFO) {printf("NV_ESC_RM_UPDATE_DEVICE_MAPPING_INFO\n");} //  NV_ESC_RM_UPDATE_DEVICE_MAPPING_INFO  0x5E
    else if (nr == NV_ESC_RM_ALLOC_MEMORY){
      nv_ioctl_nvos02_parameters_with_fd * p = argp;
      //OVO SE UVEK POZIVA #define   NV01_MEMORY_SYSTEM_OS_DESCRIPTOR                         (0x00000071)  //pVidHeapParams->function = NVOS32_FUNCTION_ALLOC_OS_DESCRIPTOR;
      //pVidHeapParams = portMemAllocNonPaged(sizeof(NVOS32_PARAMETERS)); portMemAllocNonPaged je samo malloc
      printf("NV_ESC_RM_ALLOC_MEMORY hobjparent=%x hobjnew=%x hclass=%x limit=%lld pMemory=%p\n" , (p->params).hObjectParent , (p->params).hObjectNew , (p->params).hClass ,(p->params).limit+1 ,(p->params).pMemory);  // je uvek 20 000  
    }
    //else{printf("UNKNOWN ,%x %x %lx \n" , type_ , nr , request);}
  }
  my_ioctl = dlsym(RTLD_NEXT , "ioctl");
  int result = my_ioctl(filedes , request , argp);
  return result;  
}

int (*my_openat)(int dirfd, const char *pathname, int flags);
int openat(int dirfd, const char *pathname, int flags){

  printf("OPENAT OPENAT !!! : dirfd: %d path: %s flags: %d \n" ,dirfd , pathname , flags);
  my_openat = dlsym(RTLD_NEXT , "openat");
  int result = my_openat(dirfd, pathname , flags);
  return result;  
}

int (*my_open)(const char *pathname, int flags, mode_t mode);
int open(const char *pathname , int flags , mode_t mode){

  printf("OPEN OPEN !!! : path: %s flags: %d mode: %d \n" ,pathname , flags , mode);
  my_open = dlsym(RTLD_NEXT , "open");
  int result = my_open(pathname, flags , mode);
  return result;  
}

ssize_t (*my_write)(int fd, const void *buf, size_t count);
ssize_t write(int fd, const void *buf, size_t count) {
    printf("WRITE WRITE!!! fd: %d, count: %zu buf:%p \n", fd, count , buf);
    //printf("Content of buf: ");
    //print_hex(buf, count);
    my_write = dlsym(RTLD_NEXT, "write");
    ssize_t result = my_write(fd, buf, count);
    return result;
}
ssize_t (*my_read)(int fd, const void *buf, size_t count);
ssize_t read(int fd, void *buf, size_t count) {
  printf("READ READ!!! fd: %d, count: %zu buf: %p\n", fd, count , buf);
  my_read = dlsym(RTLD_NEXT, "read");
  ssize_t result = my_read(fd, buf, count);
  //printf("Content read from buf: ");
  //print_hex(buf, result);

  return result;
}

void *(*my_mmap)(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
  printf("MMAP MMAP !!!\n");
  printf("\t****addr: %p\n" , addr);
  printf("\t****len: %zd alloc_size: %f mb\n" , length , length / 1e6);
  printf("\t****prot %d \n" , prot);
  printf("\t****flags: %x \n" ,flags);
  printf("\t****fd: %d  \n" ,fd);
  printf("\t****offset: %lx \n" ,offset);
  my_mmap = dlsym(RTLD_NEXT, "mmap");
  void *result = my_mmap(addr, length, prot, flags, fd, offset); // PROT_READ | PROT_WRITE
  pid_t pid = getpid();
  printf("\t****result:  %p\n" , result);
  return result;
}

/*
*************cuda_init*************
br=1 fd=8, size=0x8 NV_ESC_SYS_PARAMS // ovo  je vrv djubre
	**** block_size=8000000 
br=2 fd=8, size=0x900 NV_ESC_CARD_INFO // ovo je djubre
br=3 fd=8, size=0x20 NV_ESC_RM_ALLOC
	**** pObjparent 0 
	**** pObjnew 0 
	**** pallocparams (nil) 
	**** hclass 0 
	**** pRightsRequested (nil)
	**** flag FINN serialization  = 32764  
br=4 fd=8, size=0x20 NV_ESC_RM_CONTROL paramzie=40, params=0x7ffc5c4491e0, hObj=c1d00124



pa@pa-IdeaPad-Gaming-3-15IMH05:/proc/48042$ sudo cat syscall 
230 0x0 0x0 0x7fffb0096360 0x7fffb0096360 0x0 0x7fffb0096270 0x7fffb00962d0 0x7f6a676e57f8
['0x5614ed16f000', '0x5614ed174088', '0x5614ed7da000', '0x7fffe6eba2a7', '0x7fffe6eba2b0', '0x7fffe6eba2b0', '0x7fffe6ebafef']

*/