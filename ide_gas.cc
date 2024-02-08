#include<stdio.h>
#include<cuda.h>
#include<unistd.h>
#include<sys/mman.h>

#include"structs.h"
#include"helpers.h"
#include"novu.h"

#define N 10

void dump_dump(){
  printf("--dumping--\n");
  for(uint32_t *ide_gas  = (uint32_t*)0x200400000;  ide_gas <(uint32_t*)0x203c00000 ; ide_gas ++ ){
    if (*ide_gas != 0){printf("%p %x \n",ide_gas, *ide_gas);}
  }
}


int main(){

  pid_t pid = getpid();
  int a[N], b[N], c[N], control[N];
  CUdeviceptr d_a, d_b, d_c;

  for (int i = 0; i < N; ++i){a[i] = i;}
  printf("*************cuda_init*************\n");
  cuInit(0);

  CUdevice device;
  cuDeviceGet(&device, 0);
  CUcontext context;
  cuCtxCreate(&context, 0, device);

  uint64_t *door_bell = (uint64_t*)0x7ffff7fab090; // ovo je uvek nula  , libcuda prectra , mozda je  doorbell ? // *((int*)0x7ffff7fab090)
  mprotect((void*)0x7ffff7fab000, 0x7ffff7fbb000-0x7ffff7fab000 , PROT_READ | PROT_WRITE);
  
  struct nouveau_pushbuf push_buf = {.cur = (uint32_t*)0x200434054};
  nouveau_pushbuf *push =  &push_buf;
  
  cuMemAlloc(&d_a, sizeof(int) * N);
  memset((void*)&b ,0x0 , 0x20);

  cuMemcpyHtoD(d_a, a, sizeof(int)*N);   
  clear_nvctrl();

  hexdump((void*)0x7fffce700000 , 0x16);

  push->cur = (uint32_t*)0x202c00020;
  PUSH_DATA(push ,0x20048100);  // BEGIN_NVC0(push ,0x4, NVC5C0_SET_OBJECT, 0x4); 
  PUSH_DATAh(push ,0x7fffcda00000); // %llx -> d_a
  PUSH_DATAl(push ,0x7fffcda00000);
  PUSH_DATAh(push ,0x7fffce700000);
  PUSH_DATAl(push ,0x7fffce700000);
  PUSH_DATA(push ,0x20018106);  // METHOD 18 
  PUSH_DATA(push  , 0x28);
  BEGIN_NVC0(push ,0x4, NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE, 0x1);
  PUSH_DATA(push , 0x182);
  PUSH_DATA(push , 0x20038090); // BEGIN_NVC0(push ,0x4, NVC597_SET_L1_CONFIGURATION, 0x3);
  PUSH_DATA(push , 0x2);
  PUSH_DATA(push , 0x04a0ff30);
  PUSH_DATA(push , 0x2);
  BEGIN_NVC0(push ,0x4, NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE, 0x1);
  PUSH_DATA(push , 0x14);

  //map(pid);
  //*((uint32_t*)0x200226040)= 0x2c0005c; 
  //*((uint32_t*)0x200226044)= 0x2c0005c; 
  *((uint32_t*)0x200224008)= 0x2c00020; 
  *((uint32_t*)0x20022400c)= 0x3e02;    
  //*((uint32_t*)0x200226088) = 0x2;

  *((uint32_t*)0x20022608c) = 0x2; //*((uint32_t*)0x204a0ff30) = 0x2; 
  *door_bell = 0x90017; 
  //mmap(NULL, 65536, PROT_WRITE, MAP_SHARED, 14, 0) = 0x7ffff7fab000

  sleep(1);
  
  hexdump((void*)0x7fffce700000 , 0x16);

  return 0;
}