#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <assert.h>
#include "helpers.h"

#define N 512
int main()
{   
    int a[N], b[N],control[N];
    int c[N];
    CUdeviceptr d_a, d_b, d_c;
    for (int i = 0; i < N; ++i)
    {
        a[i] = i;
        b[i] = i;
        control[i] = i + i;
    }

    printf("*************cuda_init*************\n");
    cuInit(0);
    printf("*************end_cudainit*************\n");
    //uint32_t *door =(uint32_t *)0x204a0fff0;

    printf("*************cuda_device_get*************\n");
    CUdevice device;
    cuDeviceGet(&device, 0);
    printf("*************cuda_create_contex*************\n");
    CUcontext context;
    cuCtxCreate(&context, 0, device);
      
    printf("*************cuda_module_load*************\n");
    CUmodule module;
    const char *module_file = "kernel.ptx";
    cuModuleLoad(&module, module_file);

    CUfunction function;
    const char *kernel_name = "kernel";
    cuModuleGetFunction(&function, module, kernel_name);

    //dev/nvidia0
    //dev/nvidia-uvm
    munmap((void*)0x205000000 , 0x205200000-0x205000000);   // ne

    //dev/nvidiactl 
    //munmap((void*)0x200400000 , 0x203c00000-0x200400000);   // mora
    //munmap((void*)0x204a00000 , 0x204c00000-0x204a00000);   // mora 
    //munmap((void*)0x205600000 , 0x205800000-0x205600000);   // mora
    munmap((void*)0x204c00000 , 0x204e00000-0x204c00000);   // ne
    munmap((void*)0x204e00000 , 0x205000000-0x204e00000);   // ne
    munmap((void*)0x205200000 , 0x205400000-0x205200000);   // ne

		mprotect((void*)0x200000000, 0x200200000-0x200000000, PROT_READ );


    printf("*************cuda_malloc_1*************\n");
    cuMemAlloc(&d_a, sizeof(int) * N);
    printf("*************cuda_malloc_2*************\n");
    cuMemAlloc(&d_b, sizeof(int) * N);
    printf("*************cuda_malloc_3*************\n");
    cuMemAlloc(&d_c, sizeof(int) * N);

    //printf("DESINGER %llx %p\n" , d_a , &d_a);
    printf("*************cuda_memcpyHtod_1*************\n");
    cuMemcpyHtoD(d_a, a, sizeof(int) * N);
    printf("*************cuda_memcpyHtod_2*************\n");
    cuMemcpyHtoD(d_b, b, sizeof(int) * N);

    //unsigned int * romcina = (unsigned int *)0xB0000B;
    printf("_____%llx_____  \n" ,d_a);
    printf("_____%llx_____  \n" ,d_b);
    printf("_____%llx_____  \n" ,d_c);
    void *args[3] = {&d_a, &d_b, &d_c};
  
    //munmap((void*)0x200436000 , 0x202c00000-0x200436000); 
    //munmap((void*)0x200400000 , 0x200435000-0x200400000); 
    //munmap((void*)0x200230000, 0x200400000-0x200230000);

    munmap((void*)0x203c00000 , 0x204a00000-0x203c00000); // nista
    munmap((void*)0x204c10000 , 0x204c10000-0x204a00000); // nista
    munmap((void*)0x205400000 , 0x205600000-0x205400000); // nista
    munmap((void*)0x205800000 , 0x205a00000-0x205800000); // nista

    uint64_t region = gas(getpid()) + 0x177000 ;
    
    /*mprotect((void*)region, region+0xa89000, PROT_READ | PROT_WRITE);
    uint64_t *p_addr = (uint64_t*)((region & 0xFFFFFF000000) | 0xe3b300); p_addr = NULL; 
    uint64_t *ne_znam = (uint64_t*)((region & 0xFFFFFF000000) | 0xfffdc0);
    printf("IDE_GAS %p %x \n" ,ne_znam  , *ne_znam);
    uint32_t *ptr = (uint32_t*)0x205607f7c; // insteresantan ? 
    // map(getpid());*/
    
    memset((void*)0x200400000 ,0x0 , 0x203c00000-0x200400000);

    printf("*************cuda_LacunhKernel*************\n");
    cuLaunchKernel(function, 32, 16, 1, 1, 1, 1, 0, 0, args, 0);
    dump_small((void*)0x200400000 , (void*)0x203c00000); // 0x20043529c

    //dump_small((void*)0x7ffff7fab000 , (void*)0x203c00000); // 0x20043529c

    printf("*************cuda_memcpyDtoh*************\n");
    cuMemcpyDtoH(c, d_c, sizeof(int) * N);
    for(int i = 0 ; i < N ; i ++){ assert(c[i] == control[i]); }

    /* // Free device memory
    printf("*************cuda_Free_1*************\n");
    cuMemFree(d_a);
    printf("*************cuda_Free_2*************\n");
    cuMemFree(d_b);
    printf("*************cuda_Free_3*************\n");
    cuMemFree(d_c);
		printf(":D :D :D\n"); */
    
    return 0;
}
// p $_siginfo._sifields._sigfault.si_addr

// 0x200200348 , 0x200200348 4350c4 , 4350c4 , 4350c4
// 0x20020208c
// 0x200224008
// 0x200224008

// 0x204a0fff0

/*
0x7fa6f5e3b300

7fa6f2000000-7fa6f4400000 ---p 00000000 00:00 0 
7fa6f4400000-7fa6f4600000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f4600000-7fa6f4800000 rw-s 00000000 00:01 166935                     /dev/zero (deleted)
7fa6f4800000-7fa6f4a00000 rw-s 00000000 00:01 166936                     /dev/zero (deleted)
7fa6f4a00000-7fa6f5000000 ---p 00000000 00:00 0 
7fa6f5000000-7fa6f5200000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f5200000-7fa6f5400000 rw-s 00000000 00:01 166939                     /dev/zero (deleted)
7fa6f5400000-7fa6f5577000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f5577000-7fa6f6000000 ---p 00000000 00:00 0  //////////////////////////// OVDE  JE  0x7fa6f5e3b300
7fa6f6fbc000-7fa6f6fbd000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fbd000-7fa6f6fbe000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fbe000-7fa6f6fbf000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fbf000-7fa6f6fc0000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fc0000-7fa6f6fc1000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fc1000-7fa6f6fc2000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fc2000-7fa6f6fc3000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fc3000-7fa6f6fc4000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fc4000-7fa6f6fc5000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fc5000-7fa6f6fc6000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fc6000-7fa6f6fc7000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fc7000-7fa6f6fc8000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fc8000-7fa6f6fc9000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fc9000-7fa6f6fca000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fca000-7fa6f6fcb000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fcb000-7fa6f6fcc000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fcc000-7fa6f6fcd000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fcd000-7fa6f6fce000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fce000-7fa6f6fcf000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fcf000-7fa6f6fd0000 rw-s 00000000 00:05 1006                       /dev/nvidiactl
7fa6f6fd0000-7fa6f7fde000 ---p 00000000 00:00 0 
7fa6f7fde000-7fa6f87de000 rw-p 00000000 00:00 0 
7fa6f87de000-7fa6f87df000 ---p 00000000 00:00 0 
7fa6f87df000-7fa6f8fdf000 rw-p 00000000 00:00 0 
7fa6f8fdf000-7fa700000000 ---p 00000000 00:00 0


*/
