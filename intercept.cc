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

#include "uvm_ioctl.h"
#include "clb0b5sw.h"
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
#include "helpers.h"
#include "uvm_linux_ioctl.h"
#include "cl0005.h"

// /home/pa/ide_cuda/open-gpu-kernel-modules/kernel-open/nvidia-uvm/
extern "C" {
int br= 0;
int (*my_ioctl)(int filedes, unsigned long request, void *argp) = NULL;

int ioctl(int filedes,  unsigned long request ,void *argp){
  int j = 0;
  int result = 0; 
  uint8_t type_ = (request >> 8) & 0xFF;
  uint8_t nr = request & 0xFF;
  uint16_t size = (request >> 16 ) & 0xFFF;

  uint32_t* work_token = NULL;
  uint32_t* classEngineID = NULL;
  uint32_t* classID = NULL;
  uint32_t* engineID = NULL;
  uint64_t* pChannelList = NULL;
  uint64_t* totalBufferSize = NULL;

  uint32_t* turing_size = NULL;
  uint32_t* turing_caps = NULL;

  uint32_t* grRouteInfo_flags= NULL;
  uint64_t* grRouteInfo_route = NULL;
  uint32_t* engineList = NULL;
  int* name =  NULL;

//printf("req = %lx \n",request);
  // UVM_REGISTER_CHANNEL_PARAMS
  if ((nr != 0 && type_ == 0) || request == 0x30000001){
    if (request == 0x30000001){get_uvm_ioct(request, argp);}
    else{get_uvm_ioct(nr, argp);}
  }

  br = br + 1;
  if (type_ == NV_IOCTL_MAGIC){
    if (nr ==  NV_ESC_CARD_INFO){
      printf("NV_ESC_CARD_INFO \n");
      nv_ioctl_card_info_t * p = (nv_ioctl_card_info_t*)argp;
      printf("\tp->valid %x \n" ,p->valid);
      printf("\tp->pci_info.domain %x \n" ,p->pci_info.domain);
      printf("\tp->pci_info.bus %x \n" ,p->pci_info.bus);
      printf("\tp->pci_info.slot %x \n" ,p->pci_info.slot);
      printf("\tp->pci_info.function %x \n" ,p->pci_info.function);
      printf("\tp->pci_info.vendor_id %x \n" ,p->pci_info.vendor_id);
      printf("\tp->pci_info.device_id %x \n" ,p->pci_info.device_id);
      printf("\tp->gpu_id %x \n" ,p->gpu_id);
      printf("\tp->interrupt_line %x \n" ,p->interrupt_line);
      printf("\tp->reg_address %llx \n" ,p->reg_address);
      printf("\tp->reg_size %llx \n" ,p->reg_size);
      printf("\tp->fb_address %llx \n" ,p->fb_address);
      printf("\tp->fb_size %llx \n" ,p->fb_size);
      printf("\tp->minor_number %x \n" ,p->minor_number);
      printf("\tp->dev_name %p  \n" ,p->dev_name);
    }
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
      goto jump;
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
      if(cm == 0xd04){printf("0xd04 JUMP\n"); goto jump;}
      if (cm == 0x20800145){printf("0x20800145 JUMP\n");goto jump;}
      if (cm == NV0000_CTRL_CMD_GPU_ATTACH_IDS){printf(" NV0000_CTRL_CMD_GPU_ATTACH_IDS JUMP\n");goto jump;}
      if (cm == NV2080_CTRL_CMD_GSP_GET_FEATURES){printf(" NV2080_CTRL_CMD_GSP_GET_FEATURES JUMP\n");goto jump;}
      if (cm == NV0000_CTRL_CMD_GPU_GET_MEMOP_ENABLE){printf(" NV0000_CTRL_CMD_GPU_GET_MEMOP_ENABLE JUMP\n");goto jump;}
      if (cm == NV0000_CTRL_CMD_GPU_ATTACH_IDS){printf(" NV0000_CTRL_CMD_GPU_ATTACH_IDS JUMP\n");goto jump;}
      if (cm ==NV0000_CTRL_CMD_GPU_GET_ID_INFO_V2){printf(" NV0000_CTRL_CMD_GPU_GET_ID_INFO_V2 JUMP\n");goto jump;}
      if (cm ==NV2080_CTRL_CMD_GPU_GET_INFO){printf(" NV2080_CTRL_CMD_GPU_GET_INFO JUMP\n");goto jump;}
      if (cm ==NV2080_CTRL_CMD_GR_GET_GPC_MASK){printf(" NV2080_CTRL_CMD_GR_GET_GPC_MASK JUMP\n");goto jump;}
      if (cm ==NV2080_CTRL_CMD_GR_GET_TPC_MASK){printf(" NV2080_CTRL_CMD_GR_GET_TPC_MASK JUMP\n");goto jump;}
      if (cm ==NVA06C_CTRL_CMD_SET_TIMESLICE){printf(" NVA06C_CTRL_CMD_SET_TIMESLICE JUMP\n");goto jump;}
      if (cm ==0x20803002){printf(" 0x20803002 JUMP\n");goto jump;}
      if (cm ==NV2080_CTRL_CMD_PERF_BOOST){printf(" NV2080_CTRL_CMD_PERF_BOOST JUMP\n");goto jump;}
      if (cm == NV2080_CTRL_CMD_BUS_GET_PCI_BAR_INFO){printf(" NV2080_CTRL_CMD_BUS_GET_PCI_BAR_INFO JUMP\n");goto jump;}
      if (cm == NV2080_CTRL_CMD_BUS_GET_INFO_V2){printf(" NV2080_CTRL_CMD_BUS_GET_INFO_V2 JUMP\n");goto jump;}
      if (cm == NV0080_CTRL_CMD_FB_GET_CAPS_V2){printf(" NV0080_CTRL_CMD_FB_GET_CAPS_V2 JUMP\n");goto jump;}
      if (cm == NV2080_CTRL_CMD_FB_GET_INFO_V2){printf(" NV2080_CTRL_CMD_FB_GET_INFO_V2 JUMP\n");goto jump;}// ovo je mozda bit  no
      if (cm == NV0000_CTRL_CMD_GPU_GET_ID_INFO){printf(" NV0000_CTRL_CMD_GPU_GET_ID_INFO JUMP\n");goto jump;} // ovo je mozda bitno
      if (cm == NV0080_CTRL_CMD_GPU_GET_VIRTUALIZATION_MODE){printf(" NV0080_CTRL_CMD_GPU_GET_VIRTUALIZATION_MODE JUMP\n");goto jump;} // ovo je mozda bitno


      //if (cm == NV2080_CTRL_CMD_MC_GET_ARCH_INFO){printf(" NV2080_CTRL_CMD_MC_GET_ARCH_INFO JUMP\n");goto jump;} // ovo je mozda bitno
      //if (cm == NV2080_CTRL_CMD_GR_GET_GLOBAL_SM_ORDER){printf(" NV2080_CTRL_CMD_GR_GET_GLOBAL_SM_ORDER JUMP\n");goto jump;} /// bitno
      //if (cm == NV2080_CTRL_CMD_GPU_GET_GID_INFO){printf(" NV2080_CTRL_CMD_GPU_GET_GID_INFO JUMP\n");goto jump;} imas
      //if (cm ==NV2080_CTRL_CMD_GR_GET_INFO){printf(" NV2080_CTRL_CMD_GR_GET_INFO JUMP\n");goto jump;} // POTREBAN JE imas
      //if (cm == NV2080_CTRL_CMD_GPU_GET_ENGINES_V2){printf(" NV2080_CTRL_CMD_GPU_GET_ENGINES_V2 JUMP\n");goto jump;} // bitan imas

      switch(cm){
        // interesantna su ovo dva
        case NV0000_CTRL_CMD_CLIENT_SET_INHERITED_SHARE_POLICY: {goto jump; printf("\t****NV0000_CTRL_CMD_CLIENT_SET_INHERITED_SHARE_POLICY\n"); break;}
        case NV2080_CTRL_CMD_GR_GET_GLOBAL_SM_ORDER:{ printf("\t****NV2080_CTRL_CMD_GR_GET_GLOBAL_SM_ORDER"); break;} 
        case NV00FD_CTRL_CMD_ATTACH_GPU:{ printf("\t****NV00FD_CTRL_CMD_ATTACH_GPU"); break;} 
        case NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION: { printf("\t****NV0000_CTRL_CMD_SYSTEM_GET_BUILD_VERSION"); break;}
        case NV0000_CTRL_CMD_SYNC_GPU_BOOST_GROUP_INFO: { printf("\t****NV0000_CTRL_CMD_SYNC_GPU_BOOST_GROUP_INFO"); break;}
        case NV0002_CTRL_CMD_UPDATE_CONTEXTDMA: { printf("\t****NV0002_CTRL_CMD_UPDATE_CONTEXTDMA"); break;}
        case NV2080_CTRL_CMD_GPU_GET_ACTIVE_PARTITION_IDS: { printf("\t****NV2080_CTRL_CMD_GPU_GET_ACTIVE_PARTITION_IDS"); break;}
        case NV0080_CTRL_CMD_GPU_GET_VIRTUALIZATION_MODE: { printf("\t****NV0080_CTRL_CMD_GPU_GET_VIRTUALIZATION_MODE"); break;}
        case NV0080_CTRL_CMD_GPU_GET_SPARSE_TEXTURE_COMPUTE_MODE: { printf("\t****NV0080_CTRL_CMD_GPU_GET_SPARSE_TEXTURE_COMPUTE_MODE"); break;}
        case NV2080_CTRL_CMD_FB_GET_INFO_V2: { printf("\t****NV2080_CTRL_CMD_FB_GET_INFO_V2"); break;}
        //case NV2080_CTRL_CMD_GPU_GET_INFO_V2: { printf("\t****NV2080_CTRL_CMD_GPU_GET_INFO_V2"); break;}
        case NV2080_CTRL_CMD_BUS_GET_INFO_V2: { printf("\t****NV2080_CTRL_CMD_BUS_GET_INFO_V2"); break;}
        case NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS: { printf("\t****NV2080_CTRL_CMD_BUS_GET_PCIE_SUPPORTED_GPU_ATOMICS"); break;}
        case NV2080_CTRL_CMD_GPU_GET_SIMULATION_INFO: { printf("\t****NV2080_CTRL_CMD_GPU_GET_SIMULATION_INFO"); break;}
        case NV0000_CTRL_CMD_GPU_GET_MEMOP_ENABLE: { printf("\t****NV0000_CTRL_CMD_GPU_GET_MEMOP_ENABLE"); break;}
        case NV2080_CTRL_CMD_GR_GET_TPC_MASK: { printf("\t****NV2080_CTRL_CMD_GR_GET_TPC_MASK"); break;}
        case NV2080_CTRL_CMD_GR_GET_CAPS_V2: { printf("\t****NV2080_CTRL_CMD_GR_GET_CAPS_V2"); break;}
        case NV2080_CTRL_CMD_CE_GET_ALL_CAPS: { printf("\t****NV2080_CTRL_CMD_CE_GET_ALL_CAPS"); break;}
        
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
        //case NV2080_CTRL_CMD_PERF_BOOST: { goto jump; ("\t****NV2080_CTRL_CMD_PERF_BOOST"); break;}
        case NV_CONF_COMPUTE_CTRL_CMD_SYSTEM_GET_CAPABILITIES: { printf("\t****NV_CONF_COMPUTE_CTRL_CMD_SYSTEM_GET_CAPABILITIES"); break;}
        
        case NV83DE_CTRL_CMD_DEBUG_SET_EXCEPTION_MASK: { printf("\t****NV83DE_CTRL_CMD_DEBUG_SET_EXCEPTION_MASK"); break;}
        case NV2080_CTRL_CMD_GR_SET_CTXSW_PREEMPTION_MODE: { printf("\t****NV2080_CTRL_CMD_GR_SET_CTXSW_PREEMPTION_MODE"); break;}
        case NVA06C_CTRL_CMD_SET_TIMESLICE: { printf("\t****NVA06C_CTRL_CMD_SET_TIMESLICE"); break;}
        
        case NV2080_CTRL_CMD_GR_GET_INFO: {
          printf("\tNV2080_CTRL_CMD_GR_GET_INFO\n"); 
          NV2080_CTRL_GR_GET_INFO_PARAMS *p_ = (NV2080_CTRL_GR_GET_INFO_PARAMS*)p->params;
          printf(" grInfoListSize = %x \n" ,p_->grInfoListSize);
          printf(" grInfoList = %p \n" ,p_->grInfoList);
          printf(" grRouteInfo.flags = %x \n" ,p_->grRouteInfo.flags);
          printf(" grRouteInfo.route = %llx \n" ,p_->grRouteInfo.route);
          uint64_t* list_ptr = (uint64_t*)p_->grInfoList;
          for(int i = 0 ; i < 0x38 ; i ++){ if (i % 8 ==  0){printf("\n\t");}printf("%02lx ", *(list_ptr + i));}printf("\n");
          grRouteInfo_flags = (uint32_t*)&p_->grRouteInfo.flags;
          grRouteInfo_route = (uint64_t*)&p_->grRouteInfo.route;
          break;
        }
        case NVA06C_CTRL_CMD_GPFIFO_SCHEDULE: {
          printf("\t NVA06C_CTRL_CMD_GPFIFO_SCHEDULE\n");
          NVA06F_CTRL_GPFIFO_SCHEDULE_PARAMS * p_ = (NVA06F_CTRL_GPFIFO_SCHEDULE_PARAMS*)p->params;
          printf("bEnable %x \n" , p_->bEnable);
          printf("bSkipSubmit %x \n" , p_->bSkipSubmit);
          break;
        }
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
          engineList = p_->engineList;
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
          name = (int*)p_->data;
          pretty_print(p_);
          break;
        }
        case NVC36F_CTRL_GET_CLASS_ENGINEID: {
          NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS *p_ = (NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS*)p->params;
          classEngineID = (uint32_t*)&p_->classEngineID;
          classID = (uint32_t*)&p_->classID;
          engineID = (uint32_t*)&p_->engineID;
          /// proveri ovo
          pretty_print(p_);
          break;
        }
        case NV2080_CTRL_CMD_GR_GET_CTX_BUFFER_SIZE: {
          NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS *p_ = (NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS*)p->params; // mozda KRAJ pisanja dorbela u mapiranu memoriju
          totalBufferSize = (uint64_t*)&p_->totalBufferSize;
          pretty_print(p_);
          break;
        }
        case NV0080_CTRL_CMD_FIFO_GET_CHANNELLIST: { 
          NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS *p_ = (NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS*)p->params;
          pChannelList = (uint64_t*)p_->pChannelList;
          pretty_print(p_);
          break;
        }
        case NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN: { 
          NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS *p_ = (NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS*)p->params; // get work submit token je nula, ali nvidiactrl se mapira blizu hipa gde je  prava vrednost 
          pretty_print(p_);
          work_token = (uint32_t*)(&p_->workSubmitToken);
          //for(uint32_t *ptr = (uint32_t*)0x200200000 ; ptr <(uint32_t*)(0x200400000) ; ptr ++){ if(*ptr !=0 ){printf("%p: %x\n " , ptr , *ptr); lol = 1;}}
          //munmap((void*)0x7ffff7f98000 ,0x10000);
          break;
        }
        case NV0000_CTRL_CMD_CLIENT_GET_ADDR_SPACE_TYPE: {
          NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS * p_ = (NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS*)p->params;
          pretty_print(p_); 
          break;
        }
      }
      printf("\n");
    }
    else if  (nr == NV_ESC_RM_ALLOC){  // 
      NVOS21_PARAMETERS *p = (NVOS21_PARAMETERS *)argp;
      //if (p->hClass == 0x79){
      //  for(uint32_t *ptr = (uint32_t*)0x200400000 ; ptr <(uint32_t*)(0x203c00000) ; ptr ++){ if(*ptr !=0 ){printf("%p: %x\n " , ptr , *ptr);}}
      //}
      printf("NV_ESC_RM_ALLOC ");
      printf("hRoot=%x, " , p->hRoot); 
      printf("pObjparent=%x, " , p->hObjectParent); 
      printf("pObjnew=%x, " , p->hObjectNew);
      printf("pallocparams=%p, " ,  p->pAllocParms);
      printf("psize=%x, " ,  p->paramsSize);
      printf("hclass=%x \n" ,  p->hClass);   
      //if (p->hClass == 0xc5b5){goto jump;}
      if (p->hClass == NV01_EVENT_OS_EVENT){
        NV0005_ALLOC_PARAMETERS *p_ = (NV0005_ALLOC_PARAMETERS*)p->pAllocParms;
        //p_->hParentClient = hParentClient;
        printf("\tNV0005_ALLOC_PARAMETERS \n");
        printf("\thParentClient %x \n" , p_->hParentClient);
        printf("\thSrcResource %x \n" , p_->hSrcResource);
        printf("\thClass %x \n" , p_->hClass);
        printf("\tnotifyIndex %x \n" , p_->notifyIndex);
        printf("\tdata %p \n" , p_->data);
        //for(uint32_t *ptr = (uint32_t*)0x200400000 ; ptr <(uint32_t*)(0x203c00000) ; ptr ++){ if(*ptr !=0 ){printf("%p: %x\n " , ptr , *ptr);}}
        //clear_nvctrl();
      }
      if (p->hClass == NV50_MEMORY_VIRTUAL || p->hClass == NV01_MEMORY_LOCAL_USER || p->hClass == NV01_MEMORY_SYSTEM) {
        printf("NV_MEMORY_ALLOCATION_PARAMS or NV01_MEMORY_LOCAL_USER or NV01_MEMORY_SYSTEM %x \n" , p->hClass);
        NV_MEMORY_ALLOCATION_PARAMS *p_ = (NV_MEMORY_ALLOCATION_PARAMS*)p->pAllocParms;
        //for(uint64_t * ptr = (uint64_t*)p->pAllocParms ; ptr < (uint64_t*)((uint64_t (p->pAllocParms)+0x200)); ptr++ ){printf("%p: %x \n" , ptr, *ptr);}
        printf("\towner %x \n" , p_->owner);
        printf("\ttype %x \n" , p_->type);
        printf("\tflags %x \n" , p_->flags);
        printf("\twidth %x \n" , p_->width);
        printf("\theight %x \n" , p_->height);
        printf("\tpitch %x \n" , p_->pitch);
        printf("\tattr %x \n" , p_->attr);
        printf("\tattr2 %x \n" , p_->attr2);
        printf("\tformat %x \n" , p_->format);
        printf("\tcomprCovg %x \n" , p_->comprCovg);
        printf("\tzcullCovg %x \n" , p_->zcullCovg);
        printf("\trangeLo %llx \n" , p_->rangeLo);
        printf("\trangeHi %llx \n" , p_->rangeHi);
        printf("\tsize %llx \n" , p_->size);
        printf("\talignment %llx \n" , p_->alignment);
        printf("\toffset %llx \n" , p_->offset);
        printf("\tlimit %llx \n" , p_->limit);
        printf("\taddress %p \n" , p_->address);
        printf("\tctagOffset %x \n" , p_->ctagOffset);
        printf("\thVASpace %x \n" , p_->hVASpace);
        printf("\tinternalflags %x \n" , p_->internalflags);
        printf("\ttag %x \n" , p_->tag);
        printf("\tnumaNode %x \n" , p_->numaNode);
      }
      // NV_MEMORY_ALLOCATION_PARAMS mozda ima veze nvDmaAllocUserD 5c000016 
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
      if (p->hClass == TURING_COMPUTE_A){ ///#####
        NV_GR_ALLOCATION_PARAMETERS *p_ = (NV_GR_ALLOCATION_PARAMETERS*)p->pAllocParms;
        printf("TURING_COMPUTE_A\n");
        printf("\tversion %x \n" , p_->version);
        printf("\tflags %x \n" , p_->flags);
        printf("\tsize %x \n" , p_->size);
        printf("\tcaps %x \n" , p_->caps);
        turing_size =  (uint32_t*)&p_->size;
        turing_caps = (uint32_t*)&p_->caps;
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
      if (p->hClass == TURING_CHANNEL_GPFIFO_A){ // #### 
        NV_CHANNEL_ALLOC_PARAMS * p_ = (NV_CHANNEL_ALLOC_PARAMS*)p->pAllocParms;
        pretty_print(p_);
      }
      if( p->hClass == TURING_DMA_COPY_A){ // c5b5
        NVB0B5_ALLOCATION_PARAMETERS *p_ = (NVB0B5_ALLOCATION_PARAMETERS*)p->pAllocParms;
        pretty_print(p_);
      }
    }
    //Nv01MemoryLocalUser 
    //NV_GR_ALLOCATION_PARAMETERS

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
  my_ioctl = reinterpret_cast<decltype(my_ioctl)>(dlsym(RTLD_NEXT, "ioctl"));
  result = my_ioctl(filedes, request, argp);

  if (name != NULL){printf("ime = %x-%x-%x-%x \n" , name[0] , name[1] , name[2], name[3]);}
  if(engineList != NULL){
    printf("\tengineList: ");
    for(uint32_t* ptr = engineList ; ptr < (uint32_t*)((uint64_t)engineList + 0x32); ptr++){if  (*ptr != 0 ) printf("%x " , *ptr);}printf("\n");}
  if (totalBufferSize !=  NULL){printf("totalBufferSize_ = %lx \n" , *totalBufferSize);}
  if (pChannelList !=  NULL){printf("pChannelList_ = %lx \n" , *pChannelList);}
  if (work_token != NULL){printf("WORK_TOKEN %x \n" ,*work_token);}
  if (classEngineID != NULL || classID != NULL || engineID != NULL){printf(" classEngineID_ %x classID_ %x engineID_ %x \n" , *classEngineID , *classID , *engineID);}
  
jump:
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