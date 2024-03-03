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
    int a[N], b[N],c[N];
    CUdeviceptr d_a, d_b, d_c , d_d;

    for (int i = 0; i < N; ++i){a[i] = i; b[i] = i;}

    cuInit(0);
    mprotect((void*)0x200000000 , 0x300200000-0x200000000 , PROT_READ | PROT_WRITE);

    CUdevice device;
    cuDeviceGet(&device , 0);

    CUcontext context;
    cuCtxCreate(&context, 0, device);

    cuMemAlloc(&d_a, sizeof(int) * N);
    cuMemAlloc(&d_b, sizeof(int) * N);
    cuMemAlloc(&d_c, sizeof(int) * N);

    cuMemAlloc(&d_d, sizeof(int) * 0x1000000);

    cuMemcpyHtoD(d_a, a, sizeof(int)*N);
    cuMemcpyHtoD(d_b, b, sizeof(int)*N);

    CUmodule module;
    CUfunction function;
    printf("da = %lx db = %lx dc = %lx\n" ,(uint64_t)d_a , (uint64_t)d_b ,(uint64_t)d_c);

    cuMemcpyDtoH(b, d_a, sizeof(int) * N);

    int res = cuModuleLoad(&module, "kernel.cubin");
    printf("res = %x\n" , res);
    assert(res == 0);

    munmap((void*)0x7fffcf577000 , 0x7fffe0000000-0x7fffcf577000);
    munmap((void*)0x7fffcc000000 , 0x7fffce400000-0x7fffcc000000);
    
    int res_2 = cuModuleGetFunction(&function, module, "kernel"); assert(res_2 == 0);
    clear_nvctrl();
    munmap((void*)205600000 , 205800000-205600000);

    void *args[3] = { &d_a, &d_a, &d_c};
    int res_3 = cuLaunchKernel(function, 1, 1, 1, N, 1, 1, 0, 0, args, 0);
    assert(res_3 == 0);

    cuMemcpyDtoH(c, d_c, sizeof(int) * N);
    return 0;
}
//p $_siginfo._sifields._sigfault.si_addr
