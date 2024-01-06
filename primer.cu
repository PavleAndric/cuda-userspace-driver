#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

#define N 100

int main()
{   
    int a[N], b[N], c[N];
    CUdeviceptr d_a, d_b, d_c;

    for (int i = 0; i < N; ++i)
    {
        a[i] = N - i;
        b[i] = i * i;
    }
    char buf[1500];
    pid_t pid = getpid();
    char path[100];
    sprintf(path , "/proc/%d/maps" , pid);

    printf("*************cuda_init*************\n");
    cuInit(0); // MMAP 0x200000000
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
    return 0;
}
