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
    // dev/nvidia-uvm
    munmap((void*)0x205000000 , 0x205200000-0x205000000);   // ne

    // /dev/nvidiactl 
    //munmap((void*)0x200400000 , 0x203c00000-0x200400000);   // mora
    //munmap((void*)0x204a00000 , 0x204c00000-0x204a00000);   // mora 
    //munmap((void*)0x205600000 , 0x205800000-0x205600000);   // mora
    munmap((void*)0x204c00000 , 0x204e00000-0x204c00000);   // ne
    munmap((void*)0x204e00000 , 0x205000000-0x204e00000);   // ne
    munmap((void*)0x205200000 , 0x205400000-0x205200000);   // ne

		mprotect((void*)0x200000000, 0x200200000-0x200000000, PROT_READ);

    
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
  
    printf("*************cuda_LacunhKernel*************\n");
    munmap((void*)0x200436000 , 0x202c00000-0x200436000); 
    munmap((void*)0x200400000 , 0x200435000-0x200400000); 
    munmap((void*)0x200230000, 0x200400000-0x200230000);
    uint64_t rom = gas();
    uint64_t *ptr = (uint64_t*)rom;
    uint64_t *ptr_2 = (uint64_t*)((uint64_t)ptr + 0x10000);
    uint64_t *ptr_3 = (uint64_t*)((uint64_t)ptr + 0x90);
    printf("NVIDIA0 END | START %p-%p , SEG: %p , %x\n" , ptr ,ptr_2 , ptr_3, *ptr_3);

    // END | START 0x7ffff7fab000-0x7ffff7fbb000 SEG 0x7ffff7fab090
    /*while (ptr < ptr_2){
      if (*ptr != 0){printf("%p:%lx\n" , ptr , *ptr);}
      ptr++; 
    }*/
    int gas = munmap((void*)(rom+0x1000) , (uint64_t)ptr_2-(rom+0x1000));printf("unmap=%d \n" , gas); // 0x10000  //17ad09 0e8bf37de0,  17ad09 1304ea0000 , 17ad09 157dfdedc0
    cuLaunchKernel(function, 32, 16, 1, 1, 1, 1, 0, 0, args, 0);
    printf("SEG AFTER %p %x \n" , ptr_3, *ptr_3);

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
//  p $_siginfo._sifields._sigfault.si_addr