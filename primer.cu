#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <assert.h>
#include <inttypes.h>
#include "clc597.h"
#include "clc5c0.h"
#define N 512

//0x2004349c4:     hex(298) -> 12a
//0x200434bfc:     hex(298) -> 12a

// #define N 615
//0x2004353ac:     hex(615) -> 267
//0x2004355e4:     hex(615) -> 267

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

// ovi su cudni
/*0x200400260: 2001255d | type:20000000  size:1  subc:1 mthd:174 
0x200400268: 2001255e | type:20000000  size:1  subc:1 mthd:178 
0x200400270: 2001255f | type:20000000  size:1  subc:1 mthd:17C 
0x200400278: 20012557 | type:20000000  size:1  subc:1 mthd:15C 
0x200400280: 20012558 | type:20000000  size:1  subc:1 mthd:160 
0x200400288: 20012559 | type:20000000  size:1  subc:1 mthd:164 */

void dump_small(){

  //200400000-203c00000 rw-s 00000000 00:05 1019                             /dev/nvidiactl
  //200400000-200436000 ovo je opseg u kojem zivi funkcija, moze  munmap 
  // 0x200433f84-0x2004354e4
  // 0x200433000-0x200436000
  // 0x200435000-0x200436000
  uint32_t *ptr = (uint32_t*)0x200435214; // 0x200433f84 ovde se pojavljuje prvi argument funckije 
  while (ptr != (uint32_t*)0x200436000) { // 0x2004354e4 ,ovo je opseg u kome sve radi
     if (*ptr != 0){
    
      int ide_gas = *ptr;
      int type =  ide_gas & 0xF0000000;
      int size = (ide_gas & 0x0FFF0000) >> 16;
      int subc = (ide_gas & 0x0000FF00) >> 13;
      int mthd = (ide_gas & 0x000000FF) << 2;
      if ((*ptr > 0x20000000 && *ptr < 0x30000000) ||(*ptr > 0x60000000 && *ptr < 0x70000000) ){
        printf("%p: %8x | type:%X  size:%X  subc:%X mthd:%X " ,ptr, *ptr, type, size, subc , mthd);
        //NVC5C0
        if (mthd == NVC5C0_SET_OBJECT) {printf("NVC5C0_SET_OBJECT\n");}
        else if  (mthd == NVC5C0_NO_OPERATION) {printf("NVC5C0_NO_OPERATION\n");}
        else if  (mthd == NVC5C0_SET_SHADER_SHARED_MEMORY_WINDOW_A) {printf("NVC5C0_SET_SHADER_SHARED_MEMORY_WINDOW_A\n");}
        else if  (mthd == NVC5C0_SET_SHADER_SHARED_MEMORY_WINDOW_B) {printf("NVC5C0_SET_SHADER_SHARED_MEMORY_WINDOW_B\n");}
        else if  (mthd == NVC5C0_SET_SPA_VERSION) {printf("NVC5C0_SET_SPA_VERSION\n");}
        else if  (mthd == NVC5C0_SET_CWD_REF_COUNTER) {printf("NVC5C0_SET_CWD_REF_COUNTER\n");}
        else if  (mthd == NVC5C0_SET_RESERVED_SW_METHOD07) {printf("NVC5C0_SET_RESERVED_SW_METHOD07\n");}
        else if  (mthd == NVC5C0_SET_RESERVED_SW_METHOD10) {printf("NVC5C0_SET_RESERVED_SW_METHOD10\n");}
        else if  (mthd == NVC5C0_SET_RESERVED_SW_METHOD09) {printf("NVC5C0_SET_RESERVED_SW_METHOD09\n");}
        else if  (mthd == NVC5C0_SET_VALID_SPAN_OVERFLOW_AREA_A) {printf("NVC5C0_SET_VALID_SPAN_OVERFLOW_AREA_A\n");}
        else if  (mthd == NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_C) {printf("NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_C\n");}
        else if  (mthd == NVC5C0_INVALIDATE_SKED_CACHES) {printf("NVC5C0_INVALIDATE_SKED_CACHES\n");}
        else if  (mthd == NVC5C0_LAUNCH_DMA) {printf("NVC5C0_LAUNCH_DMA\n");}
        else if  (mthd == NVC5C0_OFFSET_OUT_UPPER) { printf("NVC5C0_OFFSET_OUT_UPPER\n");}
        else if  (mthd == NVC5C0_LINE_LENGTH_IN) {printf("NVC5C0_LINE_LENGTH_IN\n");}
        else if  (mthd == NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_A) {printf("NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_A\n");}
        else if  (mthd == NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_B) {printf("NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_B\n");}
        else if  (mthd == NVC5C0_SET_INLINE_QMD_ADDRESS_A) {printf("NVC5C0_SET_INLINE_QMD_ADDRESS_A\n");}
        // NVC597
        else if  (mthd == NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE) {printf("NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE\n");}
        else if  (mthd == NVC597_SET_STREAM_OUT_BUFFER_LOAD_WRITE_POINTER(0)) {printf("NVC597_SET_STREAM_OUT_BUFFER_LOAD_WRITE_POINTER\n");}
        else if  (mthd == NVC597_SET_L1_CONFIGURATION) {printf("NVC597_SET_L1_CONFIGURATION\n");}
        else if  (mthd == NVC597_SET_ROOT_TABLE_VISIBILITY(0)) {printf("NVC597_SET_L1_CONFIGURATION\n");}
        // TYPE 6
        else if  (mthd == NVC597_LOAD_INLINE_DATA) { printf("NVC597_LOAD_INLINE_DATA\n");}
      }
      for (int j = 0 ; j < size; j ++){
        ptr++;
        if (j != 0 && j % 4 == 0){printf("\n");}
        printf("%08x " , *ptr); 
      }
      if (size != 0){
        printf("\n");
      }
    }
    ++ptr;
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
    printf("_____%llx_____%p  \n" ,d_a , &d_a);
    printf("_____%llx_____%p  \n" ,d_b, &d_b);
    printf("_____%llx_____%p  \n" ,d_c, &d_c);
    void *args[3] = {&d_a, &d_b, &d_c};
  
    printf("*************cuda_LacunhKernel*************\n");
    //munmap((void*)0x205600000 , 0x205800000-0x205600000);   //  0x205607f7c seg fault
    //munmap((void*)0x204a00000 , 0x204c00000-0x204a00000);   //  0x204a0fff0 seg fault ptr:(0x204a0fff0 69)
    //munmap((void*)0x200400000 , 0x203c00000-0x200400000);   //2  0x200434424
    
    // 200400000-200436000 rw-s 00000000 00:05 1019 /dev/nvidiactl OPSEG U KOJEM ZIVI KERNEL
    int gas = munmap((void*)0x200436000 , 0x202c00000-0x200436000); // je potrebno za kopuju 0x202c00000
    int gas_2 = munmap((void*)0x200400000 , 0x200435000-0x200400000); // 0x200433000-0x200400000 = 12288(decimal)
    // nvidia0
    int gas_3 = munmap((void*)0x200230000, 0x200400000-0x200230000);

    /*uint32_t *romBase = (uint32_t*)0x20043549c;
    uint32_t *rom1 = (uint32_t*)0x200435478;
    uint32_t *rom2 = (uint32_t*)0x20043548c;
    uint32_t *romXD = (uint32_t*)0x200435490;
    uint32_t *rom3 = (uint32_t*)0x20043549c;
    uint32_t *rom4 = (uint32_t*)0x2004354a8;
    uint32_t *rom5 = (uint32_t*)0x2004354ac;
    uint32_t *rom6 = (uint32_t*)0x2004354b0;
    uint32_t *rom7 = (uint32_t*)0x2004354b4;
    printf("%x %x %x %x %x %x %x %x %x \n", *romBase, *rom1, *rom2, *romXD, *rom3, *rom4, *rom5, *rom6, *rom7);*/
    
    // munmap((void*)0x7fc676400000, 0x7fc676600000-0x7fc676400000);

    //0x7fc676400000-0x7fc676600000
    cuLaunchKernel(function, 16, 32, 1, 1, 1, 1, 0, 0, args, 0);
    uint32_t *rom = (uint32_t*)0x205607f7c;

    printf("%x lmao \n " , *rom);
    //cuLaunchKernel(function, N, 1, 1, 1, 1, 1, 0, 0, args, 0); 
    printf("*************cuda_memcpyDtoh************* %p\n" , c);
    printf("%x \n " , *rom);
    cuMemcpyDtoH(c, d_c, sizeof(int) * N); // 0x202c00020 //for(int i = 0 ; i < N ; i ++){ assert(c[i] == control[i]); }
    dump_small();
    /*for(int i = 0 ; i < N ; i ++ ){
      printf("%d" , c[i]);
      if (i % 64 == 0 && i != 0){
        printf("\n");
      }
    } printf("\n");*/
    
    /* // Free device memory
    printf("*************cuda_Free_1*************\n");
    cuMemFree(d_a);
    printf("*************cuda_Free_2*************\n");
    cuMemFree(d_b);
    printf("*************cuda_Free_3*************\n");
    cuMemFree(d_c);
		printf(":D :D :D\n"); */
    /*
    FILE *f = fopen(path, "r");
		while (fgets(buf, sizeof(buf), f) != NULL){printf("%s", buf);}
		printf("\n");
		fclose(f);*/
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