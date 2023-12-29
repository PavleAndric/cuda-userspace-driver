#define _GNU_SOURCE
#define _FCNTL_H

#include <stdint.h>
#include <dlfcn.h>
#include <unistd.h>
#include <stdio.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <bits/fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>

#include "nvos.h" 
#include "nv-ioctl.h"
#include "nv-ioctl-numa.h" 
#include "nv_escape.h"
#include "nvtypes.h"
#include "nv-unix-nvos-params-wrappers.h"

int (*my_ioctl)(int filedes, unsigned long request, void *argp) = NULL;
int ioctl(int filedes,  unsigned long request ,void *argp){

  uint8_t type_ = (request >> 8) & 0xFF;
  uint8_t nr = request & 0xFF;
  uint16_t size = (request >> 16 ) & 0xFFF;

  
  if (type_ == NV_IOCTL_MAGIC){
    printf("%d, 0x%x " , filedes , size);
    if (nr ==  NV_ESC_CARD_INFO){ printf("NV_ESC_CARD_INFO\n");}
    else if  (nr == NV_ESC_REGISTER_FD) {printf("NV_ESC_REGISTER_FD \n" );}
    else if  (nr == NV_IOCTL_BASE) {printf("NV_IOCTL_BASE \n");}
    else if  (nr == NV_ESC_ALLOC_OS_EVENT) { printf("NV_ESC_ALLOC_OS_EVENT\n");}
    // setting up shit -- -- -- 
    else if  (nr == NV_ESC_SYS_PARAMS) {
      nv_ioctl_sys_params_t *p = argp; 
      printf("NV_ESC_SYS_PARAMS\n");  
      printf("\t**** %llu \n" , p->memblock_size); //ovo je uvek 134217728
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
      NVOS54_PARAMETERS *p = argp;
      printf("NV_ESC_RM_CONTROL %x \n" , p->hObject); // flag is  always 0  ,Client is always the same
    }
    // ALLOC
    else if  (nr == NV_ESC_RM_ALLOC){ // #define NV_ESC_RM_ALLOC mislim da je ovaj bitan , i dinamitan
      
      NVOS64_PARAMETERS *p_ = argp; //int size_ = p_ -> paramsSize; ovo  je uvek nula
      NVOS21_PARAMETERS *p = (NVOS21_PARAMETERS *)argp;
      printf("NV_ESC_RM_ALLOC\n");
      printf("\t**** %x \n" , p->hObjectParent); 
      printf("\t**** %x \n" , p->hObjectNew);
      printf("\t**** %p \n" ,  p->pAllocParms);
      //if(p-> paramsSize){printf("\t****param_size_1= %d\n", p->paramsSize);} // ovo je cudno ovaj je uvek 0
      if(p_-> paramsSize){printf("\t****param_size_2= %d\n", p_->paramsSize);} // ovo je cudno // ovaj  je  na prvom  pozivu uvek  3
      if (p_->flags){printf("\t**** flag = %d  \n" , p_->flags);}
    }
    // FREE
    else if (nr == NV_ESC_RM_FREE){
      NVOS00_PARAMETERS *p = (NVOS00_PARAMETERS*) argp;
      printf("NV_ESC_RM_FREE %x %x  \n" , p->hObjectParent , p->hObjectOld);
    }
    else if  (nr == NV_ESC_RM_MAP_MEMORY){
      nv_ioctl_nvos33_parameters_with_fd *p = argp;
      printf("NV_ESC_RM_MAP_MEMORY \n");
      printf("\t**** %x \n" ,(p->params).hMemory);
    } 
    else if  (nr == NV_ESC_RM_UPDATE_DEVICE_MAPPING_INFO) {printf("NV_ESC_RM_UPDATE_DEVICE_MAPPING_INFO\n");} //  NV_ESC_RM_UPDATE_DEVICE_MAPPING_INFO  0x5E

    else if (nr == NV_ESC_RM_ALLOC_MEMORY){
      nv_ioctl_nvos02_parameters_with_fd * p = argp;
      
      //OVO SE UVEK POZIVA #define   NV01_MEMORY_SYSTEM_OS_DESCRIPTOR                         (0x00000071)  //pVidHeapParams->function = NVOS32_FUNCTION_ALLOC_OS_DESCRIPTOR;
      //pVidHeapParams = portMemAllocNonPaged(sizeof(NVOS32_PARAMETERS)); portMemAllocNonPaged je samo malloc
      printf("NV_ESC_RM_ALLOC_MEMORY %x %x %x %lld \n" , (p->params).hObjectParent , (p->params).hObjectNew , (p->params).hClass , (p->params).limit+1);  // je uvek 20 000  
    }
    else if  (nr == NV_ESC_RM_VID_HEAP_CONTROL){ //ioctl(9, _IOC(_IOC_NONE, 0, 0x49, 0), 0x7ffd3f8dd800) = 0 STA JE OVO
      NVOS32_PARAMETERS *p = argp;
      unsigned int f = p->function;
      printf("NV_ESC_RM_VID_HEAP_CONTROL %d \n" ,f);
      if (f == NVOS32_FUNCTION_ALLOC_SIZE){
        int size = p->data.AllocSize.size;  
        printf("\t**** %d \n", size);
      }
    } 
    else{printf("UNKNOWN ,%x %x %lx \n" , type_ , nr , request);}
  }
  
    /*if(nr == NV_ESC_RM_VID_HEAP_CONTROL-1){ //ioctl(9, _IOC(_IOC_NONE, 0, 0x49, 0), 0x7ffd3f8dd800) = 0 STA JE OVO
      NVOS32_PARAMETERS *p = argp;
      unsigned int f = p->function;
      printf("NV_ESC_RM_VID_HEAP_CONTROL %d \n" ,f);
      if (f == NVOS32_FUNCTION_ALLOC_SIZE){
        int size = p->data.AllocSize.size;  
        printf("\t**** %d \n", size);
      }*/
  
//else{printf("UNKNOWN_NOT_IN_MAGIC %lx \n" ,request); 
  
  my_ioctl = dlsym(RTLD_NEXT , "ioctl");
  int result = my_ioctl(filedes , request , argp);
  return result;  
  }
/*
static void* (*real_malloc)(size_t)=NULL;
static void mtrace_init(void)
{
    real_malloc = dlsym(RTLD_NEXT, "malloc");
    if (NULL == real_malloc) {
        fprintf(stderr, "Error in `dlsym`: %s\n", dlerror());
    }
}

void *malloc(size_t size)
{
    if(real_malloc==NULL) {
        mtrace_init();
    }

    void *p = NULL;
    fprintf(stderr, "malloc(%ld) = ", size);
    p = real_malloc(size);
    fprintf(stderr, "%p\n", p);
    return p;
}*/
/*
//4194304 cu  malloc
/home/pa/ide_cuda/open-gpu-kernel-modules/src/nvidia/inc/kernel/rmapi/rmapi.h MEMORY MAPPING

HEAP_CONTROL
6. NVOS32_FUNCTION_ALLOC_TILED_PITCH_HEIGHT
3. NVOS32_FUNCTION_FREE
16. NVOS32_FUNCTION_RELEASE_COMPR
15. NVOS32_FUNCTION_REACQUIRE_COMPR
5. NVOS32_FUNCTION_INFO
11. NVOS32_FUNCTION_DUMP
14. NVOS32_FUNCTION_ALLOC_SIZE_RANGE
18. NVOS32_FUNCTION_GET_MEM_ALIGNMENT
19. NVOS32_FUNCTION_HW_ALLOC
20. NVOS32_FUNCTION_HW_FREE
27. NVOS32_FUNCTION_ALLOC_OS_DESCRIPTOR

typedef struct
{
    NvHandle hClient;
    NvHandle hObject;
    NvV32    cmd;
    NvU32    flags;
    NvP64    params NV_ALIGN_BYTES(8);
    NvU32    paramsSize;
    NvV32    status;
} NVOS54_PARAMETERS;*/
/*
typedef struct
{
    NvHandle hObjectParent;
    NvHandle hSubDevice;
    NvHandle hObjectNew;
    NvV32    hClass;
    NvV32    flags;
    NvU32    selector;
    NvHandle hMemory;
    NvU64    offset NV_ALIGN_BYTES(8);
    NvU64    limit NV_ALIGN_BYTES(8);
    NvV32    status;
} NVOS39_PARAMETERS;*/