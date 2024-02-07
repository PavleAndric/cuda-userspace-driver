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
    CUdeviceptr d_a, d_b, d_c;
    for (int i = 0; i < N; ++i){a[i] = i; b[i] = i;control[i] = i + i;}

    printf("*************cuda_init*************\n");
    cuInit(0);
    printf("*************end_cudainit*************\n");

    mprotect((void*)0x200000000 , 0x300200000-0x200000000 , PROT_READ | PROT_WRITE);
    
    printf("*************cuda_device_get*************\n");
    CUdevice device;
    cuDeviceGet(&device, 0);

    printf("*************cuda_create_contex_start*************\n");
    CUcontext context;
    cuCtxCreate(&context, 0, device);
    printf("*************cuda_create_contex_ende*************\n");
    
    //map(getpid());
    //dump_dumb((void*)0x200400000 ,(void*)0x203c00000);
    //dump_dumb((void*)0x7fffce400000 ,(void*)0x7fffe2ff3000);
    //dump_dumb((void*)0x7fffe2fdf000 ,(void*)0x7fffe2ff3000); // ovde nema nista
    //dump_dumb((void*)0x7fffce400000 ,(void*)0x7fffcea00000); // ovde nema nista
    //dump_dumb((void*)0x7fffcf000000 ,(void*)0x7fffcf577000); // ovde nema nista

    printf("*************cuda_malloc_1*************\n");
    cuMemAlloc(&d_a, sizeof(int) * N);

    printf("d_a = %p  \n" ,(uint64_t*)d_a );

    dump_dumb((void*)0x7fffe2fef000 ,(void*)0x7fffe2ff0000);  

    // OVDE SE NALAZE VREDNOSTI ZVONCA 0x7fff...018 zvonce 
    //munmap((void*)0x7fffe2fdf000, 0x7fffe2fe0000-0x7fffe2fdf000); // SEG 0x7fffe2fdf000 seg na cuMemcpyHtoD 
    //munmap((void*)0x7fffe2fe7000, 0x7fffe2fe8000-0x7fffe2fe7000); // SEG 0x7fffe2fe7000 seg na cuMemcpyHtoD
    //munmap((void*)0x7fffe2feb000, 0x7fffe2fec000-0x7fffe2feb000); // SEG 0x7fffe2feb000 seg na cuMemcpyHtoD
    //munmap((void*)0x7fffe2fef000, 0x7fffe2ff0000-0x7fffe2fef000); // SEG 0x7fffe2fef000 seg na cuMemcpyHtoD
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
    //map(getpid());
    /*
    printf("*************cuda_module_load*************\n");
    CUmodule module;
    const char *module_file = "kernel.ptx";
    cuModuleLoad(&module, module_file);
    */

    //dev/nvidia0
    //dev/nvidia-uvm
    munmap((void*)0x205000000 , 0x205200000-0x205000000);   // ne

    //dev/nvidiactl 
    //munmap((void*)0x200400000 , 0x203c00000-0x200400000);   // mora
    //munmap((void*)0x204a00000 , 0x204c00000-0x204a00000);   // mora 
    //munmap((void*)0x205600000 , 0x205800000-0x205600000);   // mora
    munmap((void*)0x200000000, 0x200200000-0x200000000);
    munmap((void*)0x204c00000, 0x204e00000-0x204c00000);   // ne
    munmap((void*)0x204e00000, 0x205000000-0x204e00000);   // ne
    munmap((void*)0x205200000, 0x205400000-0x205200000);   // ne

    /*CUfunction function;
    const char *kernel_name = "kernel";
    cuModuleGetFunction(&function, module, kernel_name);*/


    //memset((void*)c , 0x0 ,512);
    
    clear_nvctrl();
    printf("*************cuCopyHosttoDevice*************\n");
    cuMemcpyHtoD(d_a, a, sizeof(int)*N);

    /*
###

    p $_siginfo._sifields._sigfault.si_addr

    printf("*************cuda_malloc_2*************\n");
    cuMemAlloc(&d_b, sizeof(int) * N);
    printf("*************cuda_malloc_3*************\n");
    cuMemAlloc(&d_c, sizeof(int) * N);

    printf("*************cuda_memcpyHtod_1*************\n");
    cuMemcpyHtoD(d_a, a, sizeof(int) * N);
    printf("*************cuda_memcpyHtod_2*************\n");
    cuMemcpyHtoD(d_b, b, sizeof(int) * N);

    printf("_____%llx_____  \n" ,d_a);
    printf("_____%llx_____  \n" ,d_b);
    printf("_____%llx_____  \n" ,d_c);

    munmap((void*)0x203c00000 , 0x204a00000-0x203c00000); // nista
    munmap((void*)0x204c10000 , 0x204c10000-0x204a00000); // nista
    munmap((void*)0x205400000 , 0x205600000-0x205400000); // nista
    munmap((void*)0x205800000 , 0x205a00000-0x205800000); // nista

    clear_nvctrl();
    void *args[3] = {&d_a, &d_b, &d_c};
    
    printf("*************cuda_LacunhKernel*************\n");
    cuLaunchKernel(function, 32, 16, 1, 1, 1, 1, 0, 0, args, 0);
    //dump_small((void*)0x200400000 , (void*)0x203c00000); 
###
    */
    
    //dump_small((void*)0x200400000 , (void*)0x203c00000);

    printf("*************cuda_memcpyDtoh*************\n");
    cuMemcpyDtoH(c, d_a, sizeof(int) * N);
    hexdump((void*)c , 0x20);

    // Free device memory
    printf("*************cuda_Free_1*************\n");
    cuMemFree(d_a);
    
    //printf("CONTEXXXXXXXXXXXXX FREEEEEEEEEEEEEEEEEEEEEEEEEEEEEe\n");
    //cuCtxDestroy(context);
    return 0;
}
// p $_siginfo._sifields._sigfault.si_addr

/*
0x7fffe2feb010 : 1550 
0x7fffe2feb014 : 74e4c9c0 
0x7fffe2feb018 : 90017        #door bell value
0x7fffe2feb01c : ffff0000 

*/