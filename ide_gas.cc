#include<stdio.h>
#include<cuda.h>
#include<unistd.h>
#include<sys/mman.h>
#include<unistd.h>
#include<sys/mman.h>

#include <thread>
#include"structs.h"
#include"novu.h"
#include"helpers.h"

//int munmap(void *addr, size_t length);
//void *mmap(void addr[.length], size_t length, int prot, int flags,int fd, off_t offset);

#define N 100

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

  /*
  CUmodule module;
  const char *module_file = "kernel.ptx";
  cuModuleLoad(&module, module_file);

  CUfunction function;
  const char *kernel_name = "kernel";
  cuModuleGetFunction(&function, module, kernel_name);
  */

  uint64_t *door_bell = (uint64_t*)0x7ffff7fab090; // ovo je uvek nula  , libcuda prectra , mozda je  doorbell ? // *((int*)0x7ffff7fab090)
  mprotect((void*)0x7ffff7fab000, 0x7ffff7fbb000-0x7ffff7fab000 , PROT_READ | PROT_WRITE);
  
  struct nouveau_pushbuf push_buf = {
    .cur = (uint32_t*)0x200434054
  };
  nouveau_pushbuf *push =  &push_buf;
  
  cuMemAlloc(&d_a, sizeof(int) * N); //  MEMALLOC

  memset((void*)&b ,0x0 , 0x100);
  clear_nvctrl();
  
  uint32_t *ptr_1 =  (uint32_t*)0x200200338;
  uint32_t *ptr_2 =  (uint32_t*)0x20020033c;
  uint32_t *ptr_3 =  (uint32_t*)0x200202040;
  uint32_t *ptr_10 = (uint32_t*)0x200202044;
  uint32_t *ptr_4 =  (uint32_t*)0x200202088;
  uint32_t *ptr_5 =  (uint32_t*)0x20020208c;

  uint32_t *counter =  (uint32_t*)0x204a0fff0;
  uint32_t *dont_know =  (uint32_t*)0x204a0fff8;

  uint64_t *bar =  ((uint64_t*)0x7ffff7fab080);
  uint32_t vr[3];


  //make_arr(0); 
  //make_arr(1);
  //compare();

  //int mun = munmap((void*)0x7ffff7fab000, 0x7ffff7fbb000-0x7ffff7fac000);
  //mmap((void*)0x7ffff7fab000, 0x7ffff7fbb000-0x7ffff7fab000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  //printf("MUN %x|\n" , mun);

  //memset((void*)0x7ffff7fab000 ,0x10, 0x1000);

  // pise u door_bell 
  //*((uint32_t*)0x7ffff7fab000) = 0xf;
  //*((uint32_t*)0x7ffff7fab080) = 0xf;
  //*((uint32_t*)0x7ffff7fab084) = 0xf;
  //*door_bell = 0xFFFFF;

  /*printf("IDE_POCETAK %x \n" ,*((uint32_t*)0x7ffff7fab000));
  printf("IDE_UPPER %x \n" ,*((uint32_t*)0x7ffff7fab080));
  printf("IDE_LOWER %x \n" ,*((uint32_t*)0x7ffff7fab084));
  printf("IDE_DOOR %x \n" , *door_bell);*/
  //dump_small((void*)0x200400000 ,(void*)0x203c00000);

  
  //int mun = munmap((void*)0x7ffff7fab000, 0x7ffff7fbb000-0x7ffff7fac000);
  //mmap((void*)0x7ffff7fab000, 0x7ffff7fbb000-0x7ffff7fab000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);  

  //memset((void*)0x200200000 ,0x0 , 0x100000);

  //cuMemcpyHtoD(d_a, a, sizeof(int)*N);  // 0x7ffff7fab090 , 
  //dump_small((void*)0x200400000 ,(void*)0x203c00000);
  //exit(10);
  /*for(uint32_t *ide_gas  = (uint32_t*)0x200200000;  ide_gas <(uint32_t*)0x200400000; ide_gas ++ ){
    if (*ide_gas != 0){
      printf("%p %x \n",ide_gas, *ide_gas);
    }
  }*/


  /*
  BEGIN_NVC0(push ,0x1, NVC5C0_OFFSET_OUT_UPPER, 0x2);
  //PUSH_DATAh(push,0x7fffcda00000);   
  PUSH_DATA(push,0x7fff);   
  PUSH_DATA(push,0xcda00000);
  BEGIN_NVC0(push ,0x1,NVC5C0_LINE_LENGTH_IN, 0x2);
  PUSH_DATA(push,0x14);  
  PUSH_DATA(push,0x1);
  BEGIN_NVC0(push ,0x1,NVC5C0_LAUNCH_DMA, 0x1);
  PUSH_DATA(push,0x41);
  BEGIN_NIC0(push ,0x1,NVC597_LOAD_INLINE_DATA, 0x5);
  PUSH_DATA(push,0x0);
  PUSH_DATA(push,0x1);
  PUSH_DATA(push,0x2);
  PUSH_DATA(push,0x3);
  PUSH_DATA(push,0x4);
  PUSH_DATA(push ,0x200426c0); //BEGIN_NVC0(push ,0x1 ,NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE, 0x4); // 200420c0 200426c0
  PUSH_DATA(push,0x2);
  PUSH_DATA(push,0x04a0fff0);
  PUSH_DATA(push,0x68);
  PUSH_DATA(push,0x0);  */

  //int mun = munmap((void*)0x7ffff7fab000, 0x7ffff7fbb000-0x7ffff7fac000);
  //mmap((void*)0x7ffff7fab000, 0x7ffff7fbb000-0x7ffff7fab000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  
  cuMemcpyHtoD(d_a, a, sizeof(int)*N); 

  // kada se ovo promeni na 2 cuda ne radi

  *((uint32_t*)0x204a0ff30) = 0x1; 

  push->cur = (uint32_t*)0x202c00020;
  PUSH_DATA(push ,0x20048100);  // BEGIN_NVC0(push ,0x4, NVC5C0_SET_OBJECT, 0x4); 
  PUSH_DATA(push ,0x7fff);
  PUSH_DATA(push ,0xcda00000);
  PUSH_DATA(push ,0x7fff);
  PUSH_DATA(push ,0xce700000);
  PUSH_DATA(push ,0x20018106); //METHOD 18 
  PUSH_DATA(push  , 0x14);
  BEGIN_NVC0(push ,0x4, NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE, 0x1);
  PUSH_DATA(push , 0x182);
  PUSH_DATA(push , 0x20038090); // BEGIN_NVC0(push ,0x4, NVC597_SET_L1_CONFIGURATION, 0x3); // 
  PUSH_DATA(push , 0x2);
  PUSH_DATA(push , 0x04a0ff30);
  PUSH_DATA(push , 0x2);
  BEGIN_NVC0(push ,0x4, NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE, 0x1);
  PUSH_DATA(push , 0x14);
  
  *((uint32_t*)0x200224008)= 0x2c00020;
  *((uint32_t*)0x20022400c)= 0x3e02; // 0x3e02;
  *((uint32_t*)0x200226040)= 0x2c0005c; // 0x2c0005c
  *((uint32_t*)0x200226044)= 0x2c0005c; // 0x2c0005c

  *((uint32_t*)0x200226088)= 0x2;
  *((uint32_t*)0x20022608c)= 0x2 ;
  *((uint32_t*)0x20022604c)  = 0x2;
  *((uint32_t*)0x200226060)  = 0x2;

  //door_bell = 0x1000000; // 0xa001b 0x10A036

  usleep(50*100);
  //*((uint32_t*)0x204a0ff30) = 0x2; // ova adresa menja  cuMemcpyDtoH(b , d_a , sizeof(int)*N) , 1 radi,2 ne radi, 3  stalluje
  //*((uint32_t*)0x204a0ff38) = 0x2; 

  hexdump((void*)&b , 0x30);
  printf("\n-----------------------");
  hexdump((void*)&a , 0x30);
  printf("\n");

  printf("mun %d \n" , munmap((void*)0x7ffff7fac000, 0x7ffff7fbb000-0x7ffff7fac000));
  //uint32_t* ptr = ((uint32_t*)0x7ffff7fab090);

  /*
  printf("IDE_GAS\n");
  make_arr(0);
  for(int i = 0 ; i < 0x100000; i ++){
    *((uint32_t*)0x204a0ff38) =  (*(uint64_t*)0x7ffff7fab080);
  }
  */
  printf("gas = %lx \n", *((uint64_t*)0x7ffff6624b9f));
  make_arr(0);
  cuMemcpyDtoH(b , d_a , sizeof(int)*N); 
  make_arr(1);
  compare();

  


  hexdump((void*)&b , 0x30);
  printf("\n-----------------------");
  hexdump((void*)&a , 0x30);
  printf("\n");

  //printf("***DUMP %p %p\n" , &b , &d_a); //printf("%p " ,&b); printf("%p " ,&a);
  return 0;
}
/*
p $_siginfo._sifields._sigfault.si_addr
*/
  //mmap((void*)0x7ffff7fab000, 0x7ffff7fbb000-0x7ffff7fab000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

   /*for(uint32_t *ide_gas  = (uint32_t*)0x204a00000;  ide_gas <(uint32_t*)0x204c00000 ; ide_gas ++ ){
    if (*ide_gas != 0){
      printf("%p %x \n",ide_gas, *ide_gas);
    }
  }*/

  //dump_small((void*)0x200400000 ,(void*)0x203c00000);
  //*ptr_1 = 0x434054;
  //*ptr_2 = 0x4e02; 
  //*ptr_3 = 0x4340a0; 
  //*ptr_10 = 0x4340a0;  //*counter = *counter + 0x1;
  //*ptr_4 = 0x68; 
  //*ptr_5 = 0x68; //*bar  = 0x0;
  //*(uint32_t*)0x204a0fff0 = 0x68;
  //*(uint32_t*)0x204a0fff8 = *bar;

   //int mun = munmap((void*)0x7ffff7fab000, 0x7ffff7fbb000-0x7ffff7fac000);
  //mmap((void*)0x7ffff7fab000, 0x7ffff7fbb000-0x7ffff7fab000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  /*std::thread t([](){ // 
    while(1){
      for (uint32_t * p=  (uint32_t*)0x7ffff7fab000 ;p < (uint32_t*)0x7ffff7fbb000 ; p ++){
        if (*p){ printf("%p: %x \n" , p , *p); }
      }
    }
    usleep(50 *10000);
  });*/
