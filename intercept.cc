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
#include "ctrl0080fifo.h"
#include "ctrl0080host.h"
#include "ctrlc36f.h"
#include "ctrla06c.h"
#include "ctrl2080gsp.h"
#include "ctrlcb33.h"
#include "ctrl2080perf.h"
#include "ctrl2080perf.h"
#include "ctrl83dedebug.h"
#include "ctrl2080mc.h"
#include "clc5b5.h"
#include "clc46f.h"
#include "cl0080.h"
#include "cl0040.h"
#include "cl003e.h"
#include"cl2080.h"
#include "py/pprint.h"
#include"ctrl2080gpu.h"
#include"ctrl2080bus.h"

extern "C" {
int br= 0;
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
    else if  (nr == NV_ESC_SYS_PARAMS) {
      nv_ioctl_sys_params_t *p = (nv_ioctl_sys_params_t*)argp; 
      printf("NV_ESC_SYS_PARAMS\n");  
      printf("\t**** block_size=%llx \n" , p->memblock_size); //ovo je uvek 134217728
    }
    else if  (nr == NV_ESC_NUMA_INFO){
      nv_ioctl_numa_info_t *p = (nv_ioctl_numa_info_t*)argp;
      printf("NV_ESC_NUMA_INFO\n"); 
      printf("\t**** %" PRIu64 "\n", p->memblock_size);
      printf("\t**** %" PRIu64 "\n", p->numa_mem_addr);
      printf("\t**** %" PRIu64 "\n", p->numa_mem_size);
    } 
    // -- -- -- -- -- -- -- -- -
    else if  (nr == NV_ESC_RM_CONTROL) { 
      NVOS54_PARAMETERS *p = (NVOS54_PARAMETERS*)argp;
      unsigned cm  = p->cmd; 
      printf("NV_ESC_RM_CONTROL paramzie=%x, params=%p, hObj=%x cmd=%x :" ,p->paramsSize ,p->params, p->hObject ,cm); 
      switch(cm){
        case NV00FD_CTRL_CMD_ATTACH_GPU:{ printf("\t****NV00FD_CTRL_CMD_ATTACH_GPU"); break;} 
        case NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION: { printf("\t****NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION"); break;}
        case NV0000_CTRL_CMD_CLIENT_SET_INHERITED_SHARE_POLICY: { printf("\t****NV0000_CTRL_CMD_CLIENT_SET_INHERITED_SHARE_POLICY\n"); break;}
        case NV0000_CTRL_CMD_GPU_GET_PROBED_IDS: { printf("\t****NV0000_CTRL_CMD_GPU_GET_PROBED_IDS"); break;}
        case NV0000_CTRL_CMD_SYNC_GPU_BOOST_GROUP_INFO: { printf("\t****NV0000_CTRL_CMD_SYNC_GPU_BOOST_GROUP_INFO"); break;}
        case NV0000_CTRL_CMD_GPU_ATTACH_IDS: { printf("\t****NV0000_CTRL_CMD_GPU_ATTACH_IDS"); break;}
        case NV0000_CTRL_CMD_GPU_GET_ID_INFO_V2: { printf("\t****NV0000_CTRL_CMD_GPU_GET_ID_INFO_V2"); break;}
        case NV0002_CTRL_CMD_UPDATE_CONTEXTDMA: { printf("\t****NV0002_CTRL_CMD_UPDATE_CONTEXTDMA"); break;}
        case NV2080_CTRL_CMD_GPU_GET_ACTIVE_PARTITION_IDS: { printf("\t****NV2080_CTRL_CMD_GPU_GET_ACTIVE_PARTITION_IDS"); break;}
        case NV0080_CTRL_CMD_GPU_GET_VIRTUALIZATION_MODE: { printf("\t****NV0080_CTRL_CMD_GPU_GET_VIRTUALIZATION_MODE"); break;}
        case NV0080_CTRL_CMD_GPU_GET_SPARSE_TEXTURE_COMPUTE_MODE: { printf("\t****NV0080_CTRL_CMD_GPU_GET_SPARSE_TEXTURE_COMPUTE_MODE"); break;}
        case NV2080_CTRL_CMD_BUS_GET_PCI_INFO: { printf("\t****NV2080_CTRL_CMD_BUS_GET_PCI_INFO"); break;}
        case NV2080_CTRL_CMD_FB_GET_INFO_V2: { printf("\t****NV2080_CTRL_CMD_FB_GET_INFO_V2"); break;}
        case NV2080_CTRL_CMD_GPU_GET_INFO_V2: { printf("\t****NV2080_CTRL_CMD_GPU_GET_INFO_V2"); break;}
        case NV2080_CTRL_CMD_BUS_GET_INFO_V2: { printf("\t****NV2080_CTRL_CMD_BUS_GET_INFO_V2"); break;}
        case NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS: { printf("\t****NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS"); break;}
        case NV2080_CTRL_CMD_GPU_GET_SIMULATION_INFO: { printf("\t****NV2080_CTRL_CMD_GPU_GET_SIMULATION_INFO"); break;}
        case NV0000_CTRL_CMD_GPU_GET_MEMOP_ENABLE: { printf("\t****NV0000_CTRL_CMD_GPU_GET_MEMOP_ENABLE"); break;}
        case NV2080_CTRL_CMD_GPU_GET_ENGINES_V2: { printf("\t****NV2080_CTRL_CMD_GPU_GET_ENGINES_V2"); break;}
        case NV2080_CTRL_CMD_GR_GET_TPC_MASK: { printf("\t****NV2080_CTRL_CMD_GR_GET_TPC_MASK"); break;}
        case NV2080_CTRL_CMD_GR_GET_CAPS_V2: { printf("\t****NV2080_CTRL_CMD_GR_GET_CAPS_V2"); break;}
        case NV2080_CTRL_CMD_CE_GET_ALL_CAPS: { printf("\t****NV2080_CTRL_CMD_CE_GET_ALL_CAPS"); break;}
        case NV2080_CTRL_CMD_GR_GET_INFO: { printf("\t****NV2080_CTRL_CMD_GR_GET_INFO"); break;}
        case NV2080_CTRL_CMD_GR_GET_GPC_MASK: { printf("\t****NV2080_CTRL_CMD_GR_GET_GPC_MASK"); break;}
        case NV0080_CTRL_CMD_FB_GET_CAPS_V2: { printf("\t****NV0080_CTRL_CMD_FB_GET_CAPS_V2"); break;}
        case NV2080_CTRL_CMD_GPU_QUERY_ECC_STATUS: { printf("\t****NV2080_CTRL_CMD_GPU_QUERY_ECC_STATUS"); break;}
        case NV2080_CTRL_CMD_GPU_GET_SHORT_NAME_STRING: { printf("\t****NV2080_CTRL_CMD_GPU_GET_SHORT_NAME_STRING"); break;}
        case NV2080_CTRL_CMD_GPU_GET_NAME_STRING: { printf("\t****NV2080_CTRL_CMD_GPU_GET_NAME_STRING"); break;}
        case NV2080_CTRL_CMD_GPU_QUERY_COMPUTE_MODE_RULES: { printf("\t****NV2080_CTRL_CMD_GPU_QUERY_COMPUTE_MODE_RULES"); break;}
        case NV0000_CTRL_CMD_SYSTEM_GET_FABRIC_STATUS: { printf("\t****NV0000_CTRL_CMD_SYSTEM_GET_FABRIC_STATUS"); break;}
        case NV2080_CTRL_CMD_RC_RELEASE_WATCHDOG_REQUESTS: { printf("\t****NV2080_CTRL_CMD_RC_RELEASE_WATCHDOG_REQUESTS"); break;}
        case NV2080_CTRL_CMD_RC_SOFT_DISABLE_WATCHDOG: { printf("\t****NV2080_CTRL_CMD_RC_SOFT_DISABLE_WATCHDOG"); break;}
        case NV2080_CTRL_CMD_BUS_GET_C2C_INFO: { printf("\t****NV2080_CTRL_CMD_BUS_GET_C2C_INFO"); break;}
        case NV2080_CTRL_CMD_NVLINK_GET_NVLINK_STATUS: { printf("\t****NV2080_CTRL_CMD_NVLINK_GET_NVLINK_STATUS"); break;}
        case NV0080_CTRL_CMD_HOST_GET_CAPS_V2: { printf("\t****NV0080_CTRL_CMD_HOST_GET_CAPS_V2"); break;}
        case NV0080_CTRL_CMD_GPU_GET_CLASSLIST_V2: { printf("\t****NV0080_CTRL_CMD_GPU_GET_CLASSLIST_V2"); break;}
        case NV0080_CTRL_CMD_GPU_GET_NUM_SUBDEVICES: { printf("\t****NV0080_CTRL_CMD_GPU_GET_NUM_SUBDEVICES"); break;}
        case NV2080_CTRL_CMD_PERF_BOOST: { printf("\t****NV2080_CTRL_CMD_PERF_BOOST"); break;}
        case NV_CONF_COMPUTE_CTRL_CMD_SYSTEM_GET_CAPABILITIES: { printf("\t****NV_CONF_COMPUTE_CTRL_CMD_SYSTEM_GET_CAPABILITIES"); break;}
        case NVA06C_CTRL_CMD_GPFIFO_SCHEDULE: { printf("\t****NVA06C_CTRL_CMD_GPFIFO_SCHEDULE"); break;}
        case NV2080_CTRL_CMD_GSP_GET_FEATURES: { printf("\t****NV2080_CTRL_CMD_GSP_GET_FEATURES"); break;}
        case NV0000_CTRL_CMD_GPU_GET_ATTACHED_IDS: { printf("\t****NV0000_CTRL_CMD_GPU_GET_ATTACHED_IDS"); break;}
        case NV0000_CTRL_CMD_GPU_GET_ID_INFO: { printf("\t****NV0000_CTRL_CMD_GPU_GET_ID_INFO"); break;}
        case NV83DE_CTRL_CMD_DEBUG_SET_EXCEPTION_MASK: { printf("\t****NV83DE_CTRL_CMD_DEBUG_SET_EXCEPTION_MASK"); break;}
        case NV2080_CTRL_CMD_GR_SET_CTXSW_PREEMPTION_MODE: { printf("\t****NV2080_CTRL_CMD_GR_SET_CTXSW_PREEMPTION_MODE"); break;}
        case NVA06C_CTRL_CMD_SET_TIMESLICE: { printf("\t****NVA06C_CTRL_CMD_SET_TIMESLICE"); break;}


        case NV2080_CTRL_CMD_BUS_GET_PCI_BAR_INFO: {
            printf("\t****NV2080_CTRL_CMD_BUS_GET_PCI_BAR_INFO\n"); 
            NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS *p_ = (NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS*)p->params;

            printf("pciBarCount = %x " ,p_->pciBarCount);
            printf("pciBarInfo.flags = %x " ,p_->pciBarInfo->flags );
            printf("pciBarInfo.barSize = %x " ,p_->pciBarInfo->barSize );
            printf("pciBarInfo.barSizeBytes = %llx " ,p_->pciBarInfo->barSizeBytes );
            printf("pciBarInfo.barOffset = %llx " ,p_->pciBarInfo->barOffset );
           break;
        }

        case NV2080_CTRL_CMD_GPU_GET_GID_INFO: { 
          NV2080_CTRL_GPU_GET_GID_INFO_PARAMS *p_ = (NV2080_CTRL_GPU_GET_GID_INFO_PARAMS*)p->params;
          pretty_print(p_);
          break;
        }
        case NVC36F_CTRL_GET_CLASS_ENGINEID: {
          NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS *p_ = (NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS*)p->params;
          pretty_print(p_);
          break;
        }
        case NV2080_CTRL_CMD_GR_GET_CTX_BUFFER_SIZE: {
          NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS *p_ = (NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS*)p->params;
          pretty_print(p_);
          break;
        }
        case NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN: { 
          NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS *p_ = (NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS*)p->params;
          pretty_print(p_);
          break;
        }
        case NV0080_CTRL_CMD_FIFO_GET_CHANNELLIST: { 
          NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS *p_ = (NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS*)p->params;
          pretty_print(p_);
          /*for(int i = 0 ; i < 100 ; i ++){
            if  (((uint32_t*)p_->pChannelHandleList)[i] != 0)
            {printf("%08x " , ((uint32_t*)p_->pChannelHandleList)[i]);}
          }*/
        }
        case NV0000_CTRL_CMD_CLIENT_GET_ADDR_SPACE_TYPE: {
          NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS * p_ = (NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS*)p->params;
          pretty_print(p_); // mapFlags=/home/pa/ide_cuda/open-gpu-kernel-modules/src/nvidia/arch/nvalloc/unix/src/vbioscall.c 
          break;
        }
      }
      printf("\n");
    }
    else if  (nr == NV_ESC_RM_ALLOC){ 
      NVOS21_PARAMETERS *p = (NVOS21_PARAMETERS *)argp;
      printf("NV_ESC_RM_ALLOC\n");
      printf("\t**** pObjparent %x \n" , p->hObjectParent); 
      printf("\t**** pObjnew %x \n" , p->hObjectNew);
      printf("\t**** pallocparams_ %p \n" ,  p->pAllocParms);
      printf("\t**** hclass__lol %x \n" ,  p->hClass); 
      // NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_V2_PARAMS_MESSAGE_ID 3e informacije o drajveru 3eu
      // NV0073_CTRL_DFP_GET_INFO_PARAMS_MESSAGE_ID 40u
      // NV0000_CTRL_GPU_QUERY_DRAIN_STATE_PARAMS_MESSAGE_ID 79u

      if (p->hClass == NV0080_ALLOC_PARAMETERS_MESSAGE_ID){
        struct NV0080_ALLOC_PARAMETERS * p_ = (struct NV0080_ALLOC_PARAMETERS*)p->pAllocParms;  
        pretty_print(p_);
      }
      if (p->hClass == NV2080_ALLOC_PARAMETERS_MESSAGE_ID){
        struct NV2080_ALLOC_PARAMETERS * p_ = (struct NV2080_ALLOC_PARAMETERS*)p->pAllocParms;  
        pretty_print(p_);
      }
      if (p->hClass == TURING_CHANNEL_GPFIFO_A){
        struct Nvc46fControl_struct *p_ = (struct Nvc46fControl_struct*)p->pAllocParms;
        pretty_print(p_);
      }
      if( p->hClass == TURING_DMA_COPY_A){ // c5b5
        struct _clc5b5_tag0 *p_ = (struct _clc5b5_tag0*)p->pAllocParms;
        pretty_print(p_);
      }
    }
    else if (nr == NV_ESC_RM_FREE){
      NVOS00_PARAMETERS *p = (NVOS00_PARAMETERS*) argp;
      printf("NV_ESC_RM_FREE %x %x  \n" , p->hObjectParent , p->hObjectOld);
    }
    else if  (nr == NV_ESC_RM_MAP_MEMORY){
      nv_ioctl_nvos33_parameters_with_fd *p = (nv_ioctl_nvos33_parameters_with_fd*)argp;
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
    else if  (nr == NV_ESC_RM_UPDATE_DEVICE_MAPPING_INFO) {printf("NV_ESC_RM_UPDATE_DEVICE_MAPPING_INFO\n");} //  
    else if (nr == NV_ESC_RM_ALLOC_MEMORY){
      nv_ioctl_nvos02_parameters_with_fd * p = (nv_ioctl_nvos02_parameters_with_fd*)argp;
      printf("NV_ESC_RM_ALLOC_MEMORY hobjparent=%x hobjnew=%x hclass=%x limit=%lld pMemory=%p\n" , (p->params).hObjectParent , (p->params).hObjectNew , (p->params).hClass ,(p->params).limit+1 ,(p->params).pMemory);  // je uvek 20 000  
    }
  }

  my_ioctl = reinterpret_cast<decltype(my_ioctl)>(dlsym(RTLD_NEXT, "ioctl"));
  int result = my_ioctl(filedes, request, argp);
  return result;  
}
/*
void *(*my_mmap)(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
  printf("MMAP MMAP !!!\n");
  void *result = 0x0;
  printf("\t****addr_: %p\n" , addr);
  printf("\t****len_: %zx\n" ,length);
  printf("\t****prot %d \n" , prot);
  printf("\t****flags: %x \n" ,flags);
  printf("\t****fd_: %d  \n" ,fd);
  printf("\t****offset: %lx \n" ,offset);
  my_mmap = reinterpret_cast<decltype(my_mmap)>(dlsym(RTLD_NEXT, "mmap"));
  result = my_mmap(addr, length, prot, flags, fd, offset); // PROT_READ | PROT_WRITE
  printf("\t****result_:  %p\n" , result);
  return result;  
  }
  */
}