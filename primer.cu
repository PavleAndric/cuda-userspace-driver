#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <assert.h>

#define N 100

void dump(){
	// dump nvidia0 0x200200000-0x200400000
	printf("IDE_GAS\n");
	uint32_t *ptr = (uint32_t*)0x200200000;
	printf("/dev/nvidia0\n");
	while (ptr != (uint32_t*)0x200400000){ 
		if (*ptr != 0){
			printf("%p %x\n ",ptr ,*ptr); 
		}
		ptr ++;
	}
}
int main()
{   
    int a[N], b[N], c[N] ,control[N];
    CUdeviceptr d_a, d_b, d_c;
    
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

		/*
    //dev/nvidia0
    munmap((void*)0x200200000 , 0x200000); mora            

    // /dev/nvidiactl 
    munmap((void*)0x200400000 , 0x203c00000-0x200400000);   mora
    munmap((void*)0x204a00000 , 0x204c00000-0x204a00000);   mora
    munmap((void*)0x205600000 , 0x205800000-0x205600000);   mora
    munmap((void*)0x204c00000 , 0x204e00000-0x204c00000);   // ne
    munmap((void*)0x204e00000 , 0x205000000-0x204e00000);   // ne
    munmap((void*)0x205200000 , 0x205400000-0x205200000);   // ne*/
			
		//mprotect((void*)0x200200000 ,0x200400000-0x200200000, PROT_READ);
    // dump nvidia0 0x200200000-0x200400000

		//mprotect((void*)0x204600000, 0x204800000-0x204600000, PROT_READ);

    printf("*************cuda_malloc_1*************\n");
    cuMemAlloc(&d_a, sizeof(int) * N);
    printf("*************cuda_malloc_2*************\n");
    cuMemAlloc(&d_b, sizeof(int) * N);
    printf("*************cuda_malloc_3*************\n");
    cuMemAlloc(&d_c, sizeof(int) * N);

    printf("*************cuda_memcpyHtod_1*************\n");
    cuMemcpyHtoD(d_a, a, sizeof(int) * N);
    printf("*************cuda_memcpyHtod_2*************\n");
    cuMemcpyHtoD(d_b, b, sizeof(int) * N);
    
    void *args[3] = {&d_a, &d_b, &d_c};
    printf("*************cuda_LacunhKernel*************\n");
    cuLaunchKernel(function, N, 1, 1, 1, 1, 1, 0, 0, args, 0);
    
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
		
		dump();
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