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

#include "nvos.h" 
#include "uvm_ioctl.h"
#include "nv-ioctl.h"
#include "nv-ioctl-numa.h" 
#include "uvm_linux_ioctl.h"
#include "nv_escape.h"
#include "nvtypes.h"
#include "nv-unix-nvos-params-wrappers.h"

#include"class/clc597.h"
#include"class/clc5c0.h"
#include"class/clc461.h"
#include"class/clc5b5.h"
#include"class/clc46f.h"
#include"class/cl0080.h"
#include"class/cl003e.h"
#include"class/cl2080.h"
#include"class/cl90f1.h"
#include"class/cl50a0.h"
#include"class/cl0040.h"
#include"class/cla06c.h"
#include"class/cl9067.h"
#include"class/cl0005.h"
#include"class/clb0b5sw.h"
#include"class/cl0070.h" 

#include"ctrl/ctrla06f/ctrla06fgpfifo.h"
#include"ctrl/ctrl83de/ctrl83dedebug.h" 

#include"ctrl/ctrl0000/ctrl0000client.h"
#include"ctrl/ctrl0000/ctrl0000system.h"
#include"ctrl/ctrl0000/ctrl0000syncgpuboost.h"
#include"ctrl/ctrl0000/ctrl0000gpu.h"

#include"ctrl/ctrl2080/ctrl2080mc.h"
#include"ctrl/ctrl2080/ctrl2080fb.h"
#include"ctrl/ctrl2080/ctrl2080ce.h"
#include"ctrl/ctrl2080/ctrl2080rc.h"
#include"ctrl/ctrl2080/ctrl2080nvlink.h"
#include"ctrl/ctrl2080/ctrl2080gsp.h"
#include"ctrl/ctrl2080/ctrl2080gpu.h"
#include"ctrl/ctrl2080/ctrl2080bus.h"
#include"ctrl/ctrl2080/ctrl2080perf.h" 

#include"ctrl/ctrl0080/ctrl0080gpu.h"
#include"ctrl/ctrl0080/ctrl0080fb.h"
#include"ctrl/ctrl0080/ctrl0080fifo.h"
#include"ctrl/ctrl0080/ctrl0080host.h"

#include"ctrl/ctrl00fd.h"
#include"ctrl/ctrl0002.h"
#include"ctrl/ctrlc36f.h"
#include"ctrl/ctrla06c.h"
#include"ctrl/ctrlcb33.h" 

#include "../autogen/radi_pprint.h"


// openpilot/selfdrive/modeld/thnee/thneed_qcom2.cc interesantno
extern "C" {
int br= 0;
int (*my_ioctl)(int filedes, unsigned long request, void *argp) = NULL;

int ioctl(int filedes,  unsigned long request ,void *argp){
  int result = 0; 
  uint8_t type_ = (request >> 8) & 0xFF;
  uint8_t nr = request & 0xFF;
  uint16_t size = (request >> 16 ) & 0xFFF;

  my_ioctl = reinterpret_cast<decltype(my_ioctl)>(dlsym(RTLD_NEXT, "ioctl"));
  result = my_ioctl(filedes, request, argp);

  if ((nr != 0 && type_ == 0) || request == 0x30000001){
    if (request == 0x30000001){get_uvm_ioctl(request, argp);}
    else{get_uvm_ioctl(nr, argp);}
  }
  // TODO: fix clang_parse to parse sub structs 
  if (type_ == NV_IOCTL_MAGIC){
    if  (nr == NV_ESC_RM_CONTROL) { 
      NVOS54_PARAMETERS *p = (NVOS54_PARAMETERS*)argp;
      printf("NV_ESC_RM_CONTROL, paramzie=%x, params=%p, hObject=%x, cmd=%x \n",p->paramsSize ,p->params, p->hObject, p->cmd); 
      get_command((uint32_t)p->cmd, p->params);
    }
    else if  (nr == NV_ESC_RM_ALLOC){
      NVOS21_PARAMETERS *p = (NVOS21_PARAMETERS *)argp;
      printf("NV_ESC_RM_ALLOC, hRoot=%x, pObjparent=%x, pObjnew=%x, pallocparams=%p, psize=%x, hclass=%x\n",p->hRoot,p->hObjectParent, p->hObjectNew, p->pAllocParms, p->paramsSize, p->hClass);
      get_alloc(p->hClass,p->pAllocParms);
    }

    else if (nr ==  NV_ESC_CARD_INFO) {nv_ioctl_card_info_t *p = (nv_ioctl_card_info_t*)argp; pretty_print(p);}
    else if (nr == NV_ESC_REGISTER_FD) {nv_ioctl_register_fd *p = (nv_ioctl_register_fd*)argp;pretty_print(p);}
    else if (nr == NV_ESC_ALLOC_OS_EVENT) {nv_ioctl_alloc_os_event *p = (nv_ioctl_alloc_os_event*)argp; pretty_print(p);}
    else if (nr == NV_ESC_SYS_PARAMS) {nv_ioctl_sys_params_t *p = (nv_ioctl_sys_params_t*)argp; pretty_print(p); }
    else if (nr == NV_ESC_NUMA_INFO){nv_ioctl_numa_info_t *p = (nv_ioctl_numa_info_t*)argp;pretty_print(p);}
    else if (nr == NV_ESC_RM_FREE){NVOS00_PARAMETERS *p = (NVOS00_PARAMETERS*) argp;pretty_print(p); }
    else if (nr == NV_ESC_RM_MAP_MEMORY){nv_ioctl_nvos33_parameters_with_fd *p = (nv_ioctl_nvos33_parameters_with_fd*)argp;pretty_print(&p->params); } //FIX THIS
    else if (nr == NV_ESC_RM_UPDATE_DEVICE_MAPPING_INFO) {NVOS56_PARAMETERS *p  = (NVOS56_PARAMETERS*)argp;pretty_print(p);}
    else if (nr == NV_ESC_RM_ALLOC_MEMORY){ nv_ioctl_nvos02_parameters_with_fd * p = (nv_ioctl_nvos02_parameters_with_fd*)argp;pretty_print(p);}
    }
    return result; 
  }
}
void *(*my_mmap)(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
  printf("MMAP\n");
  void *result = 0x0;
  printf("\taddr_: %p\n" , addr);
  printf("\tlen_: %zx\n" ,length);
  printf("\tprot %d \n" , prot);
  printf("\tflags: %x \n" ,flags);
  printf("\tfd_: %d  \n" ,fd);
  printf("\toffset: %lx \n" ,offset);
  my_mmap = reinterpret_cast<decltype(my_mmap)>(dlsym(RTLD_NEXT, "mmap"));
  result = my_mmap(addr, length, prot, flags, fd, offset); // PROT_READ | PROT_WRITE
  printf("\tresult_: %p-0x%lx len = 0x%lx\n" , result , (uint64_t)length + (uint64_t)result , (uint64_t)length);
  return result;  
}