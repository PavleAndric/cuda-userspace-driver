#include<stdio.h>
#include <cuda.h>
#include "helpers.h"
#include <unistd.h>
#include <sys/mman.h>
#include"novu.h"

#define N 5

int main(){

  pid_t pid = getpid();
  int a[N], b[N],control[N];
  int c[N];
  CUdeviceptr d_a, d_b, d_c;

  for (int i = 0; i < N; ++i)
  {
      a[i] = i;
      control[i] = i + i;
  }
  //void *args[3] = {&d_a, &d_b, &d_c};
  printf("*************cuda_init*************\n");
  cuInit(0);

  CUdevice device;
  cuDeviceGet(&device, 0);
  CUcontext context;
  cuCtxCreate(&context, 0, device);

  CUmodule module;
  const char *module_file = "kernel.ptx";
  cuModuleLoad(&module, module_file);

  CUfunction function;
  const char *kernel_name = "kernel";
  cuModuleGetFunction(&function, module, kernel_name);

  //map(pid);

  mprotect((void*)0x7ffff7fab000, 0x7ffff7fbb000-0x7ffff7fab000 , PROT_READ | PROT_WRITE);
  memset((void*)0x7ffff7fab000 , 0x10, 0x10000);

  uint64_t *ptr = (uint64_t*)0x7ffff7fab090; // ovo je uvek nula  , libcuda prectra , mozda je  doorbell ?
  *ptr = 0xFFFFFF;


  cuMemAlloc(&d_a, sizeof(int) * N); //  MEMALLOC
  clear_nvctrl();
  cuMemcpyHtoD(d_a, a, sizeof(int) * N); // COPY TO GPU
  cuMemcpyDtoH(b , d_a , sizeof(int)*N); // FROM GPU  TO HOST 


  dump_small((void*)0x200400000, (void*)0x203c00000);

  printf("***DUMP %p \n" , &b);
  printf("%p " ,&b);
  hexdump((void*)&b , 0x7);
  printf("%p " ,&a);
  hexdump((void*)&a , 0x7);

  struct nouveau_pushbuf push_buf;
  push_buf.cur =  (uint32_t*)0x200434054;
  
  return 0;
}
/*


00007f0e 7e 220000
00007f0f 84 220000
00007fd4 8e 220000

BEGIN_NVC0(push, NVE4_CP(UPLOAD_DST_ADDRESS_HIGH), 2);
PUSH_DATAh(push, address + NVC0_CB_AUX_MP_INFO);
PUSH_DATA (push, address + NVC0_CB_AUX_MP_INFO);
BEGIN_NVC0(push, NVE4_CP(UPLOAD_LINE_LENGTH_IN), 2);
PUSH_DATA (push, 3 * 4);
PUSH_DATA (push, 0x1);
BEGIN_1IC0(push, NVE4_CP(UPLOAD_EXEC), 1 + 3);
PUSH_DATA (push, NVE4_COMPUTE_UPLOAD_EXEC_LINEAR | (0x20 << 1));


*************cuda_init*************
0x200434054: 20022062 | type:20000000  size:2  subc:1 mthd:188 NVC5C0_OFFSET_OUT_UPPER

 0000: 00007fff cda00000 
 0x200434060: 20022060 | type:20000000  size:2  subc:1 mthd:180 NVC5C0_LINE_LENGTH_IN

 0000: 00000014 00000001 
 0x20043406c: 2001206c | type:20000000  size:1  subc:1 mthd:1B0 NVC5C0_LAUNCH_DMA

 0000: 00000041 
 0x200434074: 6005206d | type:60000000  size:5  subc:1 mthd:1B4 NVC597_LOAD_INLINE_DATA

 0000: 00000000 00000001 00000002 00000003 
 0128: 00000004 
 0x20043408c: 200426c0 | type:20000000  size:4  subc:1 mthd:300 NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE

 0000: 00000002 04a0fff0 00000068 00000000 
 0x202c00020: 20050017 | type:20000000  size:5  subc:0 mthd:5C 
 0000: 04a0fff0 00000002 00000068 00000000 
 0128: 00001003 
 0x202c00038: 20048100 | type:20000000  size:4  subc:4 mthd:0 NVC5C0_SET_OBJECT

 0000: 00007fff cda00000 00007fff ce700000 
 0x202c0004c: 20018106 | type:20000000  size:1  subc:4 mthd:18 
 0000: 00000014 
 0x202c00054: 200180c0 | type:20000000  size:1  subc:4 mthd:300 NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE

 0000: 00000182 
 0x202c0005c: 20038090 | type:20000000  size:3  subc:4 mthd:240 NVC597_SET_L1_CONFIGURATION

 0000: 00000002 04a0ff30 00000002 
 0x202c0006c: 200180c0 | type:20000000  size:1  subc:4 mthd:300 NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE

*/