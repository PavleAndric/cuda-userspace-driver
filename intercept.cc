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
#include <string.h>

#include "cl0070.h" 
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
#include"ctrl2080mc.h"
#include "ctrl0002.h"
#include "ctrl2080bus.h"
#include "ctrl2080gpu.h"
#include "ctrl0080gpu.h"
#include "ctrl2080fb.h"
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
#include "clc5b5.h"
#include "clc46f.h"
#include "cl0080.h"
#include "cl003e.h"
#include"cl2080.h"
#include "py/pprint.h"
#include"ctrl2080gpu.h"
#include"ctrl2080bus.h"
#include"cl0040.h"
#include"uvm_ioctl.h" // uvm ioctl
#include"cl90f1.h"
#include"cl50a0.h"
#include"rmapi_deprecated.h"
#include"cla06c.h"
#include"cl9067.h"


// /home/pa/ide_cuda/open-gpu-kernel-modules/kernel-open/nvidia-uvm/
extern "C" {
int br= 0;
int (*my_ioctl)(int filedes, unsigned long request, void *argp) = NULL;
int ioctl(int filedes,  unsigned long request ,void *argp){

  uint8_t type_ = (request >> 8) & 0xFF;
  uint8_t nr = request & 0xFF;
  uint16_t size = (request >> 16 ) & 0xFFF;

  //UVM IOCTL CALLS  
  //if (nr != 0 && type_ == 0){get_uvm_ioct(nr, argp);}
  
  br = br + 1;
  if (type_ == NV_IOCTL_MAGIC){
    if (nr ==  NV_ESC_CARD_INFO){ printf("NV_ESC_CARD_INFO\n");}
    else if  (nr == NV_ESC_REGISTER_FD) {printf("NV_ESC_REGISTER_FD \n" );
    nv_ioctl_register_fd *p = (nv_ioctl_register_fd*)argp;
    printf("\tctl_fd = %x\n" , p->ctl_fd);
    }
    else if  (nr == NV_ESC_ALLOC_OS_EVENT) {
      printf("NV_ESC_ALLOC_OS_EVENT ");
      nv_ioctl_alloc_os_event *p = (nv_ioctl_alloc_os_event*)argp; 
      printf("\thClient=%x " , p->hClient);
      printf("\thDevice=%x " , p->hDevice);
      printf("\tfd=%x " , p->fd);
      printf("\tstatus=%x " , p->Status);
      printf("\n");
    }
    else if  (nr == NV_ESC_SYS_PARAMS) {
      nv_ioctl_sys_params_t *p = (nv_ioctl_sys_params_t*)argp; 
      printf("NV_ESC_SYS_PARAMS\n");  
      printf("\t**** block_size=%llx \n" , p->memblock_size); //ovo je uvek 134217728
    }
    else if  (nr == NV_ESC_NUMA_INFO){
      nv_ioctl_numa_info_t *p = (nv_ioctl_numa_info_t*)argp;
      printf("NV_ESC_NUMA_INFO\n"); 

      
      printf("\t**** nid = %x\n", p->nid);
      printf("\t**** %" PRIu64 "\n", p->memblock_size);
      printf("\t**** %" PRIu64 "\n", p->numa_mem_addr);
      printf("\t**** %" PRIu64 "\n", p->numa_mem_size);
    } 
    // -- -- -- -- -- -- -- -- -
    else if  (nr == NV_ESC_RM_CONTROL) { 
      NVOS54_PARAMETERS *p = (NVOS54_PARAMETERS*)argp;
      unsigned cm  = p->cmd; 
      printf("NV_ESC_RM_CONTROL, paramzie=%x, params=%p, hObject=%x, cmd=%x ",p->paramsSize ,p->params, p->hObject ,cm); 
      switch(cm){
        
        // interesantna su ovo dva
        case NV2080_CTRL_CMD_GR_GET_GLOBAL_SM_ORDER:{ printf("\t****NV2080_CTRL_CMD_GR_GET_GLOBAL_SM_ORDER"); break;} 
        case NV00FD_CTRL_CMD_ATTACH_GPU:{ printf("\t****NV00FD_CTRL_CMD_ATTACH_GPU"); break;} 
        case NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION: { printf("\t****NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION"); break;}
        case NV0000_CTRL_CMD_CLIENT_SET_INHERITED_SHARE_POLICY: { printf("\t****NV0000_CTRL_CMD_CLIENT_SET_INHERITED_SHARE_POLICY\n"); break;}
        case NV0000_CTRL_CMD_SYNC_GPU_BOOST_GROUP_INFO: { printf("\t****NV0000_CTRL_CMD_SYNC_GPU_BOOST_GROUP_INFO"); break;}
        //case NV0000_CTRL_CMD_GPU_GET_ID_INFO_V2: { printf("\t****NV0000_CTRL_CMD_GPU_GET_ID_INFO_V2"); break;}
        case NV0002_CTRL_CMD_UPDATE_CONTEXTDMA: { printf("\t****NV0002_CTRL_CMD_UPDATE_CONTEXTDMA"); break;}
        case NV2080_CTRL_CMD_GPU_GET_ACTIVE_PARTITION_IDS: { printf("\t****NV2080_CTRL_CMD_GPU_GET_ACTIVE_PARTITION_IDS"); break;}
        case NV0080_CTRL_CMD_GPU_GET_VIRTUALIZATION_MODE: { printf("\t****NV0080_CTRL_CMD_GPU_GET_VIRTUALIZATION_MODE"); break;}
        case NV0080_CTRL_CMD_GPU_GET_SPARSE_TEXTURE_COMPUTE_MODE: { printf("\t****NV0080_CTRL_CMD_GPU_GET_SPARSE_TEXTURE_COMPUTE_MODE"); break;}
        case NV2080_CTRL_CMD_FB_GET_INFO_V2: { printf("\t****NV2080_CTRL_CMD_FB_GET_INFO_V2"); break;}
        case NV2080_CTRL_CMD_GPU_GET_INFO_V2: { printf("\t****NV2080_CTRL_CMD_GPU_GET_INFO_V2"); break;}
        case NV2080_CTRL_CMD_BUS_GET_INFO_V2: { printf("\t****NV2080_CTRL_CMD_BUS_GET_INFO_V2"); break;}
        case NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS: { printf("\t****NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS"); break;}
        case NV2080_CTRL_CMD_GPU_GET_SIMULATION_INFO: { printf("\t****NV2080_CTRL_CMD_GPU_GET_SIMULATION_INFO"); break;}
        case NV0000_CTRL_CMD_GPU_GET_MEMOP_ENABLE: { printf("\t****NV0000_CTRL_CMD_GPU_GET_MEMOP_ENABLE"); break;}
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
        
        case NV0080_CTRL_CMD_GPU_GET_NUM_SUBDEVICES: { printf("\t****NV0080_CTRL_CMD_GPU_GET_NUM_SUBDEVICES"); break;}
        case NV2080_CTRL_CMD_PERF_BOOST: { printf("\t****NV2080_CTRL_CMD_PERF_BOOST"); break;}
        case NV_CONF_COMPUTE_CTRL_CMD_SYSTEM_GET_CAPABILITIES: { printf("\t****NV_CONF_COMPUTE_CTRL_CMD_SYSTEM_GET_CAPABILITIES"); break;}
        case NVA06C_CTRL_CMD_GPFIFO_SCHEDULE: { printf("\t****NVA06C_CTRL_CMD_GPFIFO_SCHEDULE"); break;}
        
        case NV83DE_CTRL_CMD_DEBUG_SET_EXCEPTION_MASK: { printf("\t****NV83DE_CTRL_CMD_DEBUG_SET_EXCEPTION_MASK"); break;}
        case NV2080_CTRL_CMD_GR_SET_CTXSW_PREEMPTION_MODE: { printf("\t****NV2080_CTRL_CMD_GR_SET_CTXSW_PREEMPTION_MODE"); break;}
        case NVA06C_CTRL_CMD_SET_TIMESLICE: { printf("\t****NVA06C_CTRL_CMD_SET_TIMESLICE"); break;}
        /*
        case NV2080_CTRL_CMD_NVLINK_GET_NVLINK_STATUS: { 
          printf("\t****NV2080_CTRL_CMD_NVLINK_GET_NVLINK_STATUS"); 
          NV2080_CTRL_CMD_NVLINK_GET_NVLINK_STATUS_PARAMS* p_ = (NV2080_CTRL_CMD_NVLINK_GET_NVLINK_STATUS_PARAMS*)p->params;
          printf("enabledLinkMask %x \n" ,p_->enabledLinkMask);
          printf("bSublinkStateInst %x \n" ,p_->bSublinkStateInst);
          for(int i = 0; i < 32 ; i ++){
            printf("p_->linkInfo[%d].linkState= %x "  ,i,p_->linkInfo[i].linkState);
            printf("p_->linkInfo[%d].rxSublinkStatus= %x "  ,i,p_->linkInfo[i].rxSublinkStatus);
            printf("p_->linkInfo[%d].txSublinkStatus= %x "  ,i,p_->linkInfo[i].txSublinkStatus);
            printf("p_->linkInfo[%d].bLaneReversal= %x "  ,i,p_->linkInfo[i].bLaneReversal);
            printf("p_->linkInfo[%d].nvlinkVersion= %x "  ,i,p_->linkInfo[i].nvlinkVersion);
            printf("p_->linkInfo[%d].phyVersion= %x "  ,i,p_->linkInfo[i].phyVersion); // phyVersion
            printf("\n");
            printf("p_->linkInfo[%d].nvlinkLinkClockKHz= %x "  ,i,p_->linkInfo[i].nvlinkLinkClockKHz); 
            printf("p_->linkInfo[%d].nvlinkCommonClockSpeedKHz= %x "  ,i,p_->linkInfo[i].nvlinkCommonClockSpeedKHz); 
            printf("p_->linkInfo[%d].nvlinkRefClkSpeedKHz= %x "  ,i,p_->linkInfo[i].nvlinkRefClkSpeedKHz); 
            printf("\n");
          }
          break;
        }*/

        case NV0080_CTRL_CMD_HOST_GET_CAPS_V2:{
          NV0080_CTRL_HOST_GET_CAPS_V2_PARAMS * p_ = (NV0080_CTRL_HOST_GET_CAPS_V2_PARAMS*)p->params;
          pretty_print(p_);break;
        }
        case NV2080_CTRL_CMD_GSP_GET_FEATURES: {
          NV2080_CTRL_GSP_GET_FEATURES_PARAMS * p_ = (NV2080_CTRL_GSP_GET_FEATURES_PARAMS*)p->params;
          pretty_print(p_);break;
        }
        case NV2080_CTRL_CMD_BUS_GET_PCI_INFO: {
          NV2080_CTRL_BUS_GET_PCI_INFO_PARAMS * p_ = (NV2080_CTRL_BUS_GET_PCI_INFO_PARAMS*)p->params;
          pretty_print(p_);break;
        }
        //ROOT METODS
        case NV0000_CTRL_CMD_GPU_ATTACH_IDS: {
          NV0000_CTRL_GPU_ATTACH_IDS_PARAMS * p_ = (NV0000_CTRL_GPU_ATTACH_IDS_PARAMS*)p->params;  
          pretty_print(p_);break;
        }
        case NV0000_CTRL_CMD_GPU_GET_ID_INFO_V2:{
          NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS * p_ = (NV0000_CTRL_GPU_GET_ID_INFO_V2_PARAMS*)p->params;  
          pretty_print(p_);break;
        }
        case NV0000_CTRL_CMD_GPU_GET_PROBED_IDS:{
          NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS * p_ = (NV0000_CTRL_GPU_GET_PROBED_IDS_PARAMS*)p->params;  
          pretty_print(p_);break;

        }
        case NV0000_CTRL_CMD_GPU_GET_ID_INFO:{
          NV0000_CTRL_GPU_GET_ID_INFO_PARAMS * p_ = (NV0000_CTRL_GPU_GET_ID_INFO_PARAMS*)p->params;  
          pretty_print(p_);break;
        }
        case NV0000_CTRL_CMD_GPU_GET_ATTACHED_IDS:{
          NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS * p_ = (NV0000_CTRL_GPU_GET_ATTACHED_IDS_PARAMS*)p->params;  
          pretty_print(p_);break;
        }
        //
        case NV0080_CTRL_CMD_GPU_GET_CLASSLIST_V2: {
          NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS * p_ = (NV0080_CTRL_GPU_GET_CLASSLIST_V2_PARAMS*)p->params;  
          pretty_print(p_);break;
        }
        case NV2080_CTRL_CMD_BUS_GET_PCI_BAR_INFO:{ 
          NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS * p_ = (NV2080_CTRL_BUS_GET_PCI_BAR_INFO_PARAMS*)p->params;  
          pretty_print(p_);break;
        }
        case NV2080_CTRL_CMD_GPU_GET_ENGINES_V2:{   
          NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS * p_ = (NV2080_CTRL_GPU_GET_ENGINES_V2_PARAMS*)p->params;  
          pretty_print(p_);break;
        }
        case NV2080_CTRL_CMD_MC_GET_ARCH_INFO:{
          NV2080_CTRL_MC_GET_ARCH_INFO_PARAMS *p_ = (NV2080_CTRL_MC_GET_ARCH_INFO_PARAMS*)p->params;
          pretty_print(p_);break;
        }
        case NV2080_CTRL_CMD_MC_SERVICE_INTERRUPTS:{
          NV2080_CTRL_MC_SERVICE_INTERRUPTS_PARAMS *p_ = (NV2080_CTRL_MC_SERVICE_INTERRUPTS_PARAMS*)p->params;
          pretty_print(p_); break;
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
      printf("NV_ESC_RM_ALLOC ");
      printf("hRoot=%x, " , p->hRoot); 
      printf("pObjparent=%x, " , p->hObjectParent); 
      printf("pObjnew=%x, " , p->hObjectNew);
      printf("pallocparams=%p, " ,  p->pAllocParms);
      printf("psize=%x, " ,  p->paramsSize);
      printf("hclass=%x \n" ,  p->hClass); 
      // NV0000_CTRL_SYSTEM_GET_BUILD_VERSION_V2_PARAMS_MESSAGE_ID 3e informacije o drajveru 3eu
      // NV0073_CTRL_DFP_GET_INFO_PARAMS_MESSAGE_ID 40u
      // NV0000_CTRL_GPU_QUERY_DRAIN_STATE_PARAMS_MESSAGE_ID 79u
      // NV0000_ALLOC_PARAMETERS 00
      // NV_CONFIDENTIAL_COMPUTE cb33
      // NV0080_ALLOC_PARAMETERS_MESSAGE_ID 80
      // FERMI_VASPACE_A 90f1

      if (p->hClass == NV50_MEMORY_VIRTUAL){
        NV_MEMORY_ALLOCATION_PARAMS *p_ = (NV_MEMORY_ALLOCATION_PARAMS*)p->pAllocParms;
        printf("owner %x \n" , p_->owner);
        printf("type %x \n" , p_->type);
        printf("flags %x \n" , p_->flags);
        printf("width %x \n" , p_->width);
        printf("height %x \n" , p_->height);
        printf("pitch %x \n" , p_->pitch);
        printf("attr %x \n" , p_->attr);
        printf("attr2 %x \n" , p_->attr2);
        printf("format %x \n" , p_->format);
        printf("comprCovg %x \n" , p_->comprCovg);
        printf("zcullCovg %x \n" , p_->zcullCovg);
        printf("rangeLo %llx \n" , p_->rangeLo);
        printf("rangeHi %llx \n" , p_->rangeHi);
        printf("size %llx \n" , p_->size);
        printf("alignment %llx \n" , p_->alignment);
        printf("offset %llx \n" , p_->offset);
        printf("limit %llx \n" , p_->limit);
        printf("address %p \n" , p_->address);
        printf("ctagOffset %x \n" , p_->ctagOffset);
        printf("hVASpace %x \n" , p_->hVASpace);
        printf("internalflags %x \n" , p_->internalflags);
        printf("tag %x \n" , p_->tag);
        printf("numaNode %x \n" , p_->numaNode);
      }
      /*
      if (p->hClass == 0x40){
        uint32_t *ptr =  (uint32_t*)p->pAllocParms;
        for(int i = 0 ; i < 0x7c0; i ++){
          if (*ptr){printf("%d , %x\n" , i , *ptr); i++;}
          ptr++;
        } 
      }
      */
      if (p->hClass == FERMI_CONTEXT_SHARE_A){ 
        NV_CTXSHARE_ALLOCATION_PARAMETERS *p_ = (NV_CTXSHARE_ALLOCATION_PARAMETERS*)p->pAllocParms;
        printf("NV_CTXSHARE_ALLOCATION_PARAMETERS\n");
        printf("\thVASpace = %x \n" ,p_->hVASpace);
        printf("\tflags = %x \n" ,p_->flags);
        printf("\tsubctxId = %x \n" ,p_->subctxId);
      }

      if (p->hClass == KEPLER_CHANNEL_GROUP_A){
        NV_CHANNEL_GROUP_ALLOCATION_PARAMETERS *p_ = (NV_CHANNEL_GROUP_ALLOCATION_PARAMETERS*)p->pAllocParms;
        printf("NV_CHANNEL_GROUP_ALLOCATION_PARAMETERS\n");
        printf("\thObjectError = %x \n" ,p_->hObjectError);
        printf("\thObjectEccError = %x \n" ,p_->hObjectEccError);
        printf("\thVASpace = %x \n" ,p_->hVASpace);
        printf("\tengineType = %x \n" ,p_->engineType);
        printf("\tbIsCallingContextVgpuPlugin = %x \n" ,p_->bIsCallingContextVgpuPlugin);
      }
      
      if (p->hClass == FERMI_VASPACE_A){
        NV_VASPACE_ALLOCATION_PARAMETERS *p_ = (NV_VASPACE_ALLOCATION_PARAMETERS*)p->pAllocParms;
        printf("FERMI: index = %x , flags = %x , vaSize = %llx, vaStartInternal = %llx, vaLimitInternal = %llx, bigPageSize=%x,vaBase = %llx\n" , p_->index , p_->flags, p_->vaSize, p_->vaStartInternal , p_->vaLimitInternal , p_->bigPageSize , p_->vaBase);
      }
      //ovo je zanimljivo zato sto ima istu memoriju  kao i nvidia0 u strace-u, pri mappiranju
      if (p->hClass == NV0080_ALLOC_PARAMETERS_MESSAGE_ID){
        struct NV0080_ALLOC_PARAMETERS * p_ = (struct NV0080_ALLOC_PARAMETERS*)p->pAllocParms; // mozda ovo i jeste nvidia0
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
    //Nv01MemoryLocalUser 

    else if (nr == NV_ESC_RM_FREE){
      NVOS00_PARAMETERS *p = (NVOS00_PARAMETERS*) argp;
      printf("NV_ESC_RM_FREE,%x,%x\n" , p->hObjectParent , p->hObjectOld);
    }
    else if  (nr == NV_ESC_RM_MAP_MEMORY){
      nv_ioctl_nvos33_parameters_with_fd *p = (nv_ioctl_nvos33_parameters_with_fd*)argp;
      printf("NV_ESC_RM_MAP_MEMORY, fd=%x " ,p->fd);
      printf("hDevice=%x, ",(p->params).hDevice); // 
      printf("len=%llx, ",(p->params).length);
      printf("offset=%llx, ",(p->params).offset);
      printf("flags=%x, ",(p->params).flags);
      printf("linaddr=%p, ",(p->params).pLinearAddress);
      printf("hmem_=%x,",(p->params).hMemory);
      printf("hClient=%x, ",(p->params).hClient); // 
      printf("status__=%x \n",(p->params).status);   // NV_OK je 0
      if (p->params.hMemory == (NvHandle)0x5c000012){
        for(uint32_t *ptr = (uint32_t*)0x200200000 ; ptr <(uint32_t*)0x200400000 ; ptr ++){ 
          if(*ptr){printf("%p: %x\n " , ptr , *ptr);}}}
    } 
    else if  (nr == NV_ESC_RM_UPDATE_DEVICE_MAPPING_INFO) {
      printf("NV_ESC_RM_UPDATE_DEVICE_MAPPING_INFO\n");
      NVOS56_PARAMETERS *p  = (NVOS56_PARAMETERS*)argp;
      printf("\t****hClient %x \n" , p->hClient);
      printf("\t****hDevice %x \n" , p->hDevice);
      printf("\t****hMemory %x \n" , p->hMemory);
      printf("\t****pOldCpuAddress %p\n" , p->pOldCpuAddress);
      printf("\t****pNewCpuAddress %p \n" , p->pNewCpuAddress); 
      printf("\t****status %x \n" , p->status); 
    }   
    else if (nr == NV_ESC_RM_ALLOC_MEMORY){ // ovo je zero deleted  
      nv_ioctl_nvos02_parameters_with_fd * p = (nv_ioctl_nvos02_parameters_with_fd*)argp;
      printf("NV_ESC_RM_ALLOC_MEMORY, pObjparent=%x, pObjnew=%x, hclass=%x, limit=%lld, pMemory=%p\n" , (p->params).hObjectParent , (p->params).hObjectNew , (p->params).hClass ,(p->params).limit+1 ,(p->params).pMemory);  // je uvek 20 000  

    }
  }
  int result = 0; 
  //NV_ESC_RM_CONTROL flag=0, paramzie=8c4, params=0x7fffffff9ae0, hObject=c1d036e5, cmd=a04 	****NV0000_CTRL_CMD_SYNC_GPU_BOOST_GROUP_INFO

  my_ioctl = reinterpret_cast<decltype(my_ioctl)>(dlsym(RTLD_NEXT, "ioctl"));
  result = my_ioctl(filedes, request, argp);
  return result;  
  }
}

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
  printf("\t****result_: %p-0x%lx len = 0x%lx\n" , result , (uint64_t)length + (uint64_t)result , (uint64_t)length);
  return result;  
  }