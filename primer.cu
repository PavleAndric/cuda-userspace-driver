#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <assert.h>
#include "helpers.h"

#define N 10
int main()
{   
    int a[N], b[N],c[N],control[N];
    CUdeviceptr d_a, d_b, d_c , d_d;

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
    uint64_t *door_bell = (uint64_t*)0x7ffff7fab090;
    cuMemAlloc(&d_d, sizeof(int) * 0x1000000);

    map(getpid());
    exit(1);

    printf("*************cuCopyHosttoDevice*************\n");
    cuMemcpyHtoD(d_a, a, sizeof(int)*N);
    cuMemcpyHtoD(d_b, b, sizeof(int)*N);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("*************cuda_module_load*************\n");
    CUmodule module;
    CUfunction function;
    printf("da = %lx db = %lx dc = %lx\n" ,(uint64_t)d_a , (uint64_t)d_b ,(uint64_t)d_c);

    cuMemcpyDtoH(b, d_a, sizeof(int) * N);

    int res = cuModuleLoad(&module, "kernel.cubin");
    printf("res = %x\n" , res);
    assert(res == 0);

    munmap((void*)0x7fffcf577000 , 0x7fffe0000000-0x7fffcf577000);
    munmap((void*)0x7fffcc000000 , 0x7fffce400000-0x7fffcc000000);
    
    printf("*************FUNCTION*************\n");
    int res_2 = cuModuleGetFunction(&function, module, "kernel"); assert(res_2 == 0);  // p $_siginfo._sifields._sigfault.si_addr
    clear_nvctrl();
    munmap((void*)205600000 , 205800000-205600000);

    printf("*************KERNEL_LAUNNCH*************\n");
    void *args[3] = { &d_a, &d_a, &d_c};
    int res_3 = cuLaunchKernel(function, 1, 1, 1, N, 1, 1, 0, 0, args, 0);
    assert(res_3 == 0);

    printf("*************DEVICE_TO_HOST*************\n");
    cuMemcpyDtoH(c, d_c, sizeof(int) * N);

    return 0;
}

