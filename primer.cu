#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <assert.h>
#include "helpers.h"
#include "structs.h"

#define N 512
int main()
{   
    int a[N], b[N],c[N],control[N];
    CUdeviceptr d_a; //, d_b, d_c;
    for (int i = 0; i < N; ++i){a[i] = i; b[i] = i ;control[i] = i + i;}

    printf("*************cuda_init*************\n");
    cuInit(0);
    printf("*************end_cudainit*************\n");

    mprotect((void*)0x200000000 , 0x300200000-0x200000000 , PROT_READ | PROT_WRITE);

    //map(getpid());
    //for(uint32_t *ptr = (uint32_t*)0x200000000 ; ptr <(uint32_t*)0x300200000 ; ptr ++){ if(*ptr){printf("%p: %x\n " , ptr , *ptr);}}
    //for(uint32_t *ptr = (uint32_t*)0x7ffff5600000 ; ptr <(uint32_t*)0x7ffff5e00000 ; ptr ++){ if(*ptr){printf("%p: %x\n " , ptr , *ptr);}}
    
    CUdevice device;
    cuDeviceGet(&device , 0);
    printf("&device = %p device = %x\n" , &device , device);
    
		printf("*************cuda_create_contex_start*************\n");
    CUcontext context;
    cuCtxCreate(&context, 0, device);
    printf("*************cuda_create_contex_ende*************\n");
    
    mprotect((void*)0x7fffcc000000 , 0x7fffce400000-0x7fffcc000000 , PROT_READ | PROT_WRITE);

    printf("*************cuda_malloc_1*************\n"); // izglead da za malloc  ne treba BAR adresa, ne slama se akd se odmapira BAR
    cuMemAlloc(&d_a, sizeof(int) * N); // ovo je 5c000091 objekat 
		printf("d_a = %p  %p \n" ,(uint64_t*)d_a , &d_a );


    munmap((void*)0x7fffea000000, 0x7ffff0000000-0x7fffea000000);
    munmap((void*)0x7fffce400000, 0x7fffce600000-0x7fffce400000);
    munmap((void*)0x7fffcf000000, 0x7fffcf200000-0x7fffcf000000);
    munmap((void*)0x7fffcf400000, 0x7fffcf577000-0x7fffcf400000);
    munmap((void*)0x7fffe2fe0000, 0x7fffe2fe1000-0x7fffe2fe0000);
    munmap((void*)0x7fffe2fe1000, 0x7fffe2fe2000-0x7fffe2fe1000);
    munmap((void*)0x7fffe2fe2000, 0x7fffe2fe3000-0x7fffe2fe2000);
    munmap((void*)0x7fffe2fe3000, 0x7fffe2fe4000-0x7fffe2fe3000);
    munmap((void*)0x7fffe2fe4000, 0x7fffe2fe5000-0x7fffe2fe4000);
    munmap((void*)0x7fffe2fe5000, 0x7fffe2fe6000-0x7fffe2fe5000);
    munmap((void*)0x7fffe2fe6000, 0x7fffe2fe7000-0x7fffe2fe6000);
    munmap((void*)0x7fffe2fe8000, 0x7fffe2fe9000-0x7fffe2fe8000);
    munmap((void*)0x7fffe2fe9000, 0x7fffe2fea000-0x7fffe2fe9000);
    munmap((void*)0x7fffe2fea000, 0x7fffe2feb000-0x7fffe2fea000);
    munmap((void*)0x7fffe2fec000, 0x7fffe2fed000-0x7fffe2fec000);
    munmap((void*)0x7fffe2fed000, 0x7fffe2fee000-0x7fffe2fed000);
    munmap((void*)0x7fffe2fee000, 0x7fffe2fef000-0x7fffe2fee000);
    munmap((void*)0x7fffe2ff0000, 0x7fffe2ff1000-0x7fffe2ff0000);
    munmap((void*)0x7fffe2ff1000, 0x7fffe2ff2000-0x7fffe2ff1000);
    munmap((void*)0x7fffe2ff2000, 0x7fffe2ff3000-0x7fffe2ff2000);
    /*
    printf("*************cuda_module_load*************\n");
    CUmodule module;
    const char *module_file = "kernel.ptx";
    cuModuleLoad(&module, module_file);
    */

    //munmap((void*)0x200400000 , 0x203c00000-0x200400000);   // mora
    //munmap((void*)0x204a00000 , 0x204c00000-0x204a00000);   // mora 
    //munmap((void*)0x205600000 , 0x205800000-0x205600000);   // mora
    munmap((void*)0x200000000, 0x200200000-0x200000000);
    munmap((void*)0x205200000, 0x205400000-0x205200000);   // ne
    munmap((void*)0x205000000 , 0x205200000-0x205000000);  // ne
    munmap((void*)0x204c00000, 0x204e00000-0x204c00000);   // ne
    munmap((void*)0x204e00000, 0x205000000-0x204e00000);   // ne


    //memset((void*)0x200200000 , 0x0 , 0x400000); // clear command buffer 
    //clear_nvctrl();
    
    //map(getpid());
    //CINI SE DA OVO NIJE BITNO
    //memset((void*)0x7fffe2fdf000 , 0x100, 0x1000);
    //memset((void*)0x7fffe2fe7000 , 0x100, 0x1000);
    //memset((void*)0x7fffe2feb000 , 0x100, 0x1000);
    //memset((void*)0x7fffe2fef000 , 0x100, 0x1000);

    //munmap((void*)0x7ffff7fab000 , 0x10000);
    printf("*************cuCopyHosttoDevice*************\n"); 
    cuMemcpyHtoD(d_a, a, sizeof(int)*N);

    printf("*************cuda_memcpyDtoh*************\n");
    cuMemcpyDtoH(c, d_a, sizeof(int) * N);
    printf("DUMP  C \n");
    hexdump((void*)c , 0x10);

    // Free device memory
    printf("*************cuda_Free_1*************\n");
    cuMemFree(d_a);

    //for(uint32_t *ptr = (uint32_t*)0x7fffe2fdf000 ; ptr <(uint32_t*)0x7fffe2fe0000 ; ptr ++){ if(*ptr){printf("%p: %x\n " , ptr , *ptr);}}
    //printf("DOOR_BELLS = %x %x %x %x \n" , *((uint32_t*)(0x7fffe2fdf000 + 0x18)) , *((uint32_t*)(0x7fffe2fe7000 + 0x18)) ,  *((uint32_t*)(0x7fffe2feb000 + 0x18)) , *((uint32_t*)(0x7fffe2fef000 + 0x18)));
    //cuCtxDestroy(context);
    return 0;
}
/*

printf("CONTEXXXXXXXXXXXXX FREEEEEEEEEEEEEEEEEEEEEEEEEEEEEe\n");

p $_siginfo._sifields._sigfault.si_addr
for(uint32_t *ptr = (uint32_t*)0x7fffe2fdf000 ; ptr <(uint32_t*)0x7fffe2fe0000 ; ptr ++){ if(*ptr){printf("%p: %x\n " , ptr , *ptr);}} // odredjene BAR adrese

7fffe2fdf000-7fffe2fe0000 rw-s 00000000 00:05 1029 0x1000
7fffe2fe7000-7fffe2fe8000 rw-s 00000000 00:05 1029 0x1000
7fffe2feb000-7fffe2fec000 rw-s 00000000 00:05 1029 0x1000
7fffe2fef000-7fffe2ff0000 rw-s 00000000 00:05 1029 0x1000

Za 5c000016:
  alokacija objekta
  NV_ESC_RM_MAP_MEMORY objekta
  parvi se c46f
  NV_ESC_RM_CONTROL 5c000002 NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS
  NV0000_CTRL_CLIENT_GET_ADDR_SPACE_TYPE_PARAMS
  parvi se c5c0 koje je c46f parent
  NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS c5c0
  parvi se c5b5 kome je c46f parent
  NV906F_CTRL_GET_CLASS_ENGINEID_PARAMS
  c5c0 poziva  NVC36F_CTRL_CMD_GPFIFO_GET_WORK_SUBMIT_TOKEN_PARAMS
  sub device pozvia NV2080_CTRL_GR_GET_CTX_BUFFER_SIZE_PARAMS gde je c5c0 arg 
  KRAJ


svu su deca 5c000002 svi nvidia ctrl fd
// 7fffe2fdf000-7fffe2fe0000
PRVI NV_ESC_RM_MAP_MEMORY, fd=10 hDevice=5c000002, len=1000, offset=0, flags=c0000, linaddr=(nil), hmem_=5c000016,hClient=c1d04d15, status__=0 
//7fffe2fe7000-7fffe2fe8000
DRUGI NV_ESC_RM_MAP_MEMORY, fd=12 hDevice=5c000002, len=1000, offset=0, flags=c0000, linaddr=(nil), hmem_=5c00003c,hClient=c1d04d15, status__=0 
//7fffe2feb000-7fffe2fec000
TRECI NV_ESC_RM_MAP_MEMORY, fd=14 hDevice=5c000002, len=1000, offset=0, flags=c0000, linaddr=(nil), hmem_=5c00004a,hClient=c1d04d15, status__=0
//7fffe2fef000-7fffe2ff0000
CETVRTI NV_ESC_RM_MAP_MEMORY, fd=16 hDevice=5c000002, len=1000, offset=0, flags=c0000, linaddr=(nil), hmem_=5c000058,hClient=c1d04d15, status__=0 
*/
/*
0x7fffe2feb010 : 1550 
0x7fffe2feb014 : 74e4c9c0 
0x7fffe2feb018 : 90017        #door bell value
0x7fffe2feb01c : ffff0000 
*/