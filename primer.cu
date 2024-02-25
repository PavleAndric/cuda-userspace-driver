#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <assert.h>
#include "helpers.h"

#define N 32
int main()
{   
    int a[N], b[N],c[N],control[N];
    CUdeviceptr d_a, d_b, d_c;
    CUfunction function;
    CUmodule module;

    for (int i = 0; i < N; ++i){a[i] = i; b[i] = i;}

    printf("*************cuda_init*************\n");
    cuInit(0);
    printf("*************end_cudainit*************\n");
    mprotect((void*)0x200000000 , 0x300200000-0x200000000 , PROT_READ | PROT_WRITE);

    CUdevice device;
    cuDeviceGet(&device , 0);
    printf("DEVICE = %p -> %x \n" , &device , device);

		printf("*************cuda_create_contex_start*************\n");
    CUcontext context;
    cuCtxCreate(&context, 0, device);
    printf("*************cuda_create_contex_ende*************\n");
    mprotect((void*)0x7fffcc000000 , 0x7fffce400000-0x7fffcc000000 , PROT_READ | PROT_WRITE);

    printf("*************cuda_malloc_1*************\n");
    cuMemAlloc(&d_a, sizeof(int) * N);
    printf("*************cuda_malloc_2*************\n");
    cuMemAlloc(&d_b, sizeof(int) * N);
    printf("*************cuda_malloc_3*************\n");
    cuMemAlloc(&d_c, sizeof(int) * N);

    clear_nvctrl(); memset((void*)0x200200000 , 0x0 , 0x200000); 
    printf("*************cuda_module_load*************\n");
    int res_1 = cuModuleLoad(&module, "kernel.ptx");
    assert(res_1 == 0);

    int res_2 = cuModuleGetFunction(&function, module, "kernel");
    assert(res_2 == 0);

    printf("*************cuCopyHosttoDevice*************\n");
    cuMemcpyHtoD(d_a, a, sizeof(int)*N);
    printf("*************cuCopyHosttoDevice*************\n");
    cuMemcpyHtoD(d_b, a, sizeof(int)*N);

    printf("*************KERNEL_LAUNNCH*************\n");
    void *args[3] = { &d_a, &d_b, &d_c};
    clear_nvctrl(); memset((void*)0x200200000 , 0x0 , 0x200000); 

    int res_3 = cuLaunchKernel(function, 1, 1, 1, N, 1, 1, 0, 0, args, 0);
    assert(res_3 == 0);

    dump_small((void*)0x200400000 ,(void*)0x203c00000);
    for(uint32_t *ptr = (uint32_t*)0x200200000 ; ptr <(uint32_t*)0x200400000 ; ptr ++){ if(*ptr){printf("%p: %x\n " , ptr , *ptr);}}


    printf("*************DEVICE_TO_HOST*************\n");
    cuMemcpyDtoH(c, d_c, sizeof(int) * N);
    for(int i  = 0 ; i < N ; i++){printf("%x " ,c[i]);}printf("\n");

    return 0;
}

//for(uint32_t *ptr = (uint32_t*)0x200400000 ; ptr <(uint32_t*)0x203c00000 ; ptr ++){ if(*ptr){printf("%p: %x\n " , ptr , *ptr);}}
//printf("NV_0\n");
//for(uint32_t *ptr = (uint32_t*)0x200200000 ; ptr <(uint32_t*)0x200400000 ; ptr ++){ if(*ptr){printf("%p: %x\n " , ptr , *ptr);}}

//munmap((void*)0x200000000, 0x200200000-0x200000000);
//munmap((void*)0x205200000, 0x205400000-0x205200000);   // ne
//munmap((void*)0x205000000 , 0x205200000-0x205000000);  // ne
//munmap((void*)0x204c00000, 0x204e00000-0x204c00000);   // ne
//munmap((void*)0x204e00000, 0x205000000-0x204e00000);   // ne



//dump_small((void*)0x200400000 ,(void*)0x203c00000);
//for(uint32_t *ptr = (uint32_t*)0x200200000 ; ptr <(uint32_t*)0x200400000 ; ptr ++){ if(*ptr){printf("%p: %x\n " , ptr , *ptr);}}
//clear_nvctrl(); memset((void*)0x200200000 , 0x0 , 0x200000); 


//munmap((void*)0x200400000 , 0x203c00000-0x200400000);   // mora
//munmap((void*)0x204a00000 , 0x204c00000-0x204a00000);   // mora 
//munmap((void*)0x205600000 , 0x205800000-0x205600000);   // mora
    