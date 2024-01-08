#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <assert.h>
#include <inttypes.h>

#define N 124

/*
200000000-200200000 r--p 00000000 00:00 0 
200200000-200400000 rw-s 00000000 00:05 1020                             /dev/nvidia0
200400000-203c00000 rw-s 00000000 00:05 1019                             /dev/nvidiactl
203c00000-204a00000 ---p 00000000 00:00 0 
204a00000-204c00000 rw-s 00000000 00:05 1019                             /dev/nvidiactl
205400000-205600000 ---p 00000000 00:00 0 
205600000-205800000 rw-s 00000000 00:05 1019                             /dev/nvidiactl
205800000-205a00000 ---p 00000000 00:00 0 
205a00000-205c00000 rw-s 00000000 00:01 180536                           /dev/zero (deleted)
*/

void dump_large(){

  uint32_t *base = (uint32_t*)0x200200000;

  while (base != (uint32_t*)0x200400000){ // 0x200400000 // 0x205800000 OVO
    //if (base != NULL)
    if (base == (uint32_t*)0x200400000){ printf("/dev/nvidiact 1 \n");}
    if (base == (uint32_t*)0x204c00000){ printf("/dev/nvidiact 3 \n"); base = (uint32_t*)0x205600000;}
    if (base == (uint32_t*)0x203c00000){ printf("/dev/nvidiact 2 \n"); base = (uint32_t*)0x204a00000;}
    if (*base != 0){
      uint32_t *bonus = (uint32_t*)(0x200000000 + *base);
      printf("ptr: (%p %x) bonus(%p" , base, *base , bonus);
      if (*bonus != 0) {printf(" %x" , *bonus);}
      printf(")\n");
    } 
    base ++;
  }
}
int main()
{   
    int a[N], b[N], c[N] ,control[N];
    CUdeviceptr d_a, d_b, d_c;
    //unsigned long long cigan = 0xB00B00; 
    for (int i = 0; i < N; ++i)
    {
        a[i] = i;
        b[i] = i;
        control[i] = i + i;
    }
    char buf[1500];
    pid_t pid = getpid();
    char path[100];

    sprintf(path , "/proc/%d/maps" , pid);

    printf("*************cuda_init*************\n");
    cuInit(0); // MMAP 0x200000000-300200000 uvek ! ! ! 
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
    //munmap((void*)0x200200000 , 0x200000); mora            

    // dev/nvidia-uvm
    munmap((void*)0x205000000 , 0x205200000-0x205000000);   // ne

    // /dev/nvidiactl 
    //munmap((void*)0x200400000 , 0x203c00000-0x200400000);   // mora
    //munmap((void*)0x204a00000 , 0x204c00000-0x204a00000);   // mora 
    //munmap((void*)0x205600000 , 0x205800000-0x205600000);   // mora
    munmap((void*)0x204c00000 , 0x204e00000-0x204c00000);   // ne
    munmap((void*)0x204e00000 , 0x205000000-0x204e00000);   // ne
    munmap((void*)0x205200000 , 0x205400000-0x205200000);   // ne

    // ???
    //munmap((void*)0x205c00000 , 0x300200000-0x205c00000);   // ne
    //munmap((void*)0x200000000 , 0x200200000-0x200000000);   // ne

		//mprotect((void*)0x204600000, 0x204800000-0x204600000, PROT_READ);
		mprotect((void*)0x200000000, 0x200200000-0x200000000, PROT_READ); // init

    
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
    void *lmao = (void*)(0xb00000b);
    printf("_____%llx_____  \n" ,d_a);
    printf("_____%llx_____  \n" ,d_b);
    printf("_____%llx_____  \n" ,d_c);
    //sleep(1000000);
    void *args[4] = {&d_a, &d_b, &d_c};
  
    printf("*************cuda_LacunhKernel*************\n");
    //munmap((void*)0x205600000 , 0x205800000-0x205600000);   //  0x205607f7c seg fault
    //munmap((void*)0x204a00000 , 0x204c00000-0x204a00000);   //  0x204a0fff0 seg fault ptr:(0x204a0fff0 69)
    //munmap((void*)0x200400000 , 0x203c00000-0x200400000);     //  0x200434424

    cuLaunchKernel(function, N, 1, 1, 1, 1, 1, 0, 0, args, 0); 
    /*
    printf("*************cuda_memcpyDtoh*************\n");
    cuMemcpyDtoH(c, d_c, sizeof(int) * N);
    for(int i = 0 ; i < N ; i ++){assert(c[i] == control[i]);}
    // Free device memory
    printf("*************cuda_Free_1*************\n");
    cuMemFree(d_a);
    printf("*************cuda_Free_2*************\n");
    cuMemFree(d_b);
    printf("*************cuda_Free_3*************\n");
    cuMemFree(d_c);
    
		printf(":D :D :D\n");
    FILE *f = fopen(path, "r");
		while (fgets(buf, sizeof(buf), f) != NULL){printf("%s", buf);}
		printf("\n");
		fclose(f);
    //dump_large();

    printf("***** read\n");
    */
    uint32_t *ptr = (uint32_t*)0x200400000;
    while (ptr != (uint32_t*)0x203c00000) { if (*ptr != 0) printf("%p: %8x\n", ptr, *ptr); ++ptr; }
    
    return 0;
}

/*
0x7f719c7de000 /dev/zero
0x7f719c7de000 /dev/nvidiactl
0x205000000 /dev/nvidia-uvm
0x205000000 /dev/nvidia-uvm
0x7f7196600000 /dev/nvidiactl
0x7f7196600000 /dev/zero
0x7f7196600000 /dev/nvidiactl
0x7f7196600000 /dev/zero
0x7f7196600000 /dev/nvidiactl
0x7f7196600000 /dev/zero
0x7f7196800000 /dev/zero
0x7f7196800000 /dev/zero
0x7f7196800000 /dev/zero
0x7f7196800000 /dev/zero
0x7f7196800000 /dev/zero
0x7f7196800000 /dev/zero
0x7f719c5de000 /dev/zero
0x7f719c5de000 /dev/zero
0x205a00000 /dev/zero
0x205a00000 /dev/zero
0x205a00000 /dev/zero
0x7f7197200000 /dev/nvidiactl
0x7f7197200000 /dev/zero
0x7f7197200000 /dev/nvidiactl
0x7f7197200000 /dev/zero
0x7f7197200000 /dev/nvidiactl
0x7f7197200000 /dev/zero
*/