#include<stdio.h>
#include<cuda.h>
#include<unistd.h>
#include<sys/mman.h>
#include"structs.h"

#include"helpers.h"
#include"novu.h"

#define N 10000

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

  for (int i = 0; i < N; ++i){a[i] = i+10;}
  printf("*************cuda_init*************\n");
  cuInit(0);

  CUdevice device;
  cuDeviceGet(&device, 0);
  CUcontext context;
  cuCtxCreate(&context, 0, device);

  uint64_t *door_bell = (uint64_t*)0x7ffff7fab090; // ovo je uvek nula  , libcuda prectra , mozda je  doorbell ? // *((int*)0x7ffff7fab090)
  mprotect((void*)0x7ffff7fab000, 0x10000 , PROT_READ | PROT_WRITE);

  mprotect((void*)0x7fffcc000000, 0x7fffce400000-0x7fffcc000000 , PROT_READ | PROT_WRITE);

  struct nouveau_pushbuf push_buf = {.cur = (uint32_t*)0x200434054}; // 0x200434054
  nouveau_pushbuf *push =  &push_buf;

  cuMemAlloc(&d_a, sizeof(int) * N);
  memset((void*)&b ,0x0 , 0x20);

  //clear_nvctrl();
  //cuMemcpyHtoD(d_a, a, sizeof(int)*N); // 9 je doorbell
  //dump_small((void*)0x200400000 , (void*)0x203c00000);//dump_dumb((void*)0x200200000 , (void*)0x200400000);

  clear_nvctrl();memset((void*)0x200200000 ,0x0, 0x40000);
  printf("***** HOST TO DEVICDE *****\n");
  printf("d_a -> %llx ---- DUMP ---\n" ,d_a); // 0x7fffcda00000
  push->cur = (uint32_t*)0x200433e48; // 0x200433e48 // MORA BAS OVDE !!!!!
  PUSH_DATA(push , 0x20022062); //NVC5C0_OFFSET_OUT_UPPER
  PUSH_DATAh(push , 0x7fffcda00000);
  PUSH_DATAl(push , 0x7fffcda00000);
  PUSH_DATA(push , 0x20022060); //NVC5C0_LINE_LENGTH_IN
  PUSH_DATA(push , 0x28);
  PUSH_DATA(push , 0x1);
  PUSH_DATA(push , 0x2001206c); // NVC5C0_LAUNCH_DMA
  PUSH_DATA(push , 0x41);
  PUSH_DATA(push , 0x600a206d); // NVC597_LOAD_INLINE_DATA
  for(int  i = 0 ; i < 10 ; i ++){PUSH_DATA(push , i+i);}
  
  
  /*PUSH_DATA(push , 0x200426c0); // NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE
  PUSH_DATA(push , 0x2); 
  PUSH_DATA(push , 0x4a0fff0); 
  PUSH_DATA(push , 0x64); 
  PUSH_DATA(push , 0x0);*/


  *((uint32_t *)0x200200318) = 0x433e48; ///  0x200433e48
  *((uint32_t *)0x20020031c) = 0x6202; 
  *((uint32_t *)0x20020204c) = 0x2; 
  *door_bell = 0x9; // RING
  //*((uint32_t *)0x200202040) = 0x433ea8; 
  //*((uint32_t *)0x200202044) = 0x433ea8; 
  //*((uint32_t *)0x200202060) = 0x2; 
  //*((uint32_t *)0x200202088) = 0x64; 
  //*((uint32_t *)0x20020208c) = 0x64; 
  
  //dump_small((void*)0x200400000 , (void*)0x203c00000);//dump_dumb((void*)0x200200000 , (void*)0x200400000);
  hexdump((void*)0x7fffce700000 , 0x16);
  printf("***** DEVICDE TO HOST *****\n");

  //clear_nvctrl();memset((void*)0x200200000 ,0x0, 0x40000);
  push->cur = (uint32_t*)0x202c00020;
  PUSH_DATA(push ,0x20048100);  // BEGIN_NVC0(push ,0x4, NVC5C0_SET_OBJECT, 0x4); 
  PUSH_DATAh(push ,0x7fffcda00000); // D_A
  PUSH_DATAl(push ,0x7fffcda00000);
  PUSH_DATAh(push ,(uint64_t)c); // 7fffce600000-7fffce800000 rw-s 00000000 00:01 /dev/zero (deleted)
  PUSH_DATAl(push ,(uint64_t)c);
  PUSH_DATA(push ,0x20018106);  // METHOD 18
  PUSH_DATA(push  , 0x28);
  BEGIN_NVC0(push ,0x4, NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE, 0x1);
  PUSH_DATA(push , 0x182);
  
  /*PUSH_DATA(push , 0x20038090); // BEGIN_NVC0(push ,0x4, NVC597_SET_L1_CONFIGURATION, 0x3);
  PUSH_DATA(push , 0x2);
  PUSH_DATA(push , 0x04a0ff30);//ovo moze da bude nula?
  PUSH_DATA(push , 0x2);
  BEGIN_NVC0(push ,0x4, NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE, 0x1);
  PUSH_DATA(push , 0x14);*/

  *((uint32_t*)0x200224008)= 0x2c00020;  // OVO JE SAMO  0x202c00020 ali skraceno 
  *((uint32_t*)0x20022400c)= 0x3e02;    
  *((uint32_t*)0x20022608c) = 0x2; 
  *door_bell = 0x90015; // RING 

  for(uint32_t *ptr = (uint32_t*)0x200200000 ; ptr <(uint32_t*)(0x200400000) ; ptr ++){ if(*ptr !=0 ){printf("%p: %x\n " , ptr , *ptr);}}
  for(uint32_t *ptr = (uint32_t*)0x200400000 ; ptr <(uint32_t*)(0x203c00000) ; ptr ++){ if(*ptr !=0 ){printf("%p: %x\n " , ptr , *ptr);}}

  sleep(1);
  //*((uint32_t*)0x200226040)= 0x2c0005c; 
  //*((uint32_t*)0x200226044)= 0x2c0005c; 
  //*((uint32_t*)0x200226088) = 0x2;

  //dump_dumb((void*)0x200400000 , (void*)0x203c00000);
  //dump_dumb((void*)0x200200000 , (void*)0x200400000);
  
  hexdump((void*)((uint64_t)c) , 0x16);
  return 0;
}