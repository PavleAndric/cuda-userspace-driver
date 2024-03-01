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



    map(getpid()); // 0x205607000
    exit(1);
    

    munmap((void*)0x7fffcf577000 , 0x7fffe0000000-0x7fffcf577000);
    munmap((void*)0x7fffcc000000 , 0x7fffce400000-0x7fffcc000000);

    //7fffcfe3b300 ovo je programska adresa, nema nista 0x7fffcf577000 <= 0x7fffcfe3b300 <= 0x7fffe0000000 ovo  odmapiram i sve radi
    //7fffce220000 7fffcc000000-7fffce400000 , ovde  nema nista ? 
    //7fffce010000 7fffcc000000-7fffce400000 , ovde  nema nista ?
    //7fffeb000000  7fffea000000-7ffff0000000 ---p 00000000 00:00 0 nema nista 
    //7fffed000000  7fffea000000-7ffff0000000
    //7fffce220160  7fffea000000-7ffff0000000 7fffcc000000-7fffce400000 
    
    printf("*************FUNCTION*************\n");
    int res_2 = cuModuleGetFunction(&function, module, "kernel"); assert(res_2 == 0);  // p $_siginfo._sifields._sigfault.si_addr


    clear_nvctrl();
    munmap((void*)205600000 , 205800000-205600000);
    //munmap((void*)205400000 , 205600000-205400000);

    printf("*************KERNEL_LAUNNCH*************\n");
    void *args[3] = { &d_a, &d_a, &d_c};
    int res_3 = cuLaunchKernel(function, 1, 1, 1, N, 1, 1, 0, 0, args, 0);
    assert(res_3 == 0);
    //dump_small((void*)0x200400000 ,(void*)0x203c00000);

    printf("*************DEVICE_TO_HOST*************\n");
    cuMemcpyDtoH(c, d_c, sizeof(int) * N);

    dump_small((void*)0x200400000 ,(void*)0x203c00000);
    hexdump((void*)c , 0x20);
    //for(int i  = 0 ; i < N ; i++){printf("%x " ,c[i]);}printf("\n");
    return 0;
}


//dump_small((void*)0x200400000 ,(void*)0x203c00000);
//7fffcc000000-7fffce400000  ove adrese su zanimljive ovde se nalazi offset out  upper, ovde nema nista 
// 7fff ce220000
// 7fff ce220160 sta je ovo
// 7fff ce221860