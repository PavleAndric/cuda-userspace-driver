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
#include <signal.h>

#define N 10

void dump_dump(){
  printf("--dumping--\n");
  for(uint32_t *ide_gas  = (uint32_t*)0x200400000;  ide_gas <(uint32_t*)0x203c00000 ; ide_gas ++ ){
    if (*ide_gas != 0){printf("%p %x \n",ide_gas, *ide_gas);}
  }
}
void print_needed(){
  printf("rez = %lx ff30 = %lx  080 = %lx  \n" , *((uint64_t*)0x7ffff7fab080)-*((uint64_t*)0x204a0ff38) , *((uint64_t*)0x204a0ff38) , *((uint64_t*)0x7ffff7fab080));
}

void sigsegv_handler(int signum, siginfo_t *si, void *arg) {
    void *monitored_address = (void *) arg;
    printf("Memory address %p has been modified!\n", monitored_address);
}

int main(){

  pid_t pid = getpid();
  int a[N], b[N],control[N];
  int c[N];
  CUdeviceptr d_a, d_b, d_c;

  for (int i = 0; i < N; ++i)
  {
      a[i] = i;
  }
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
  cuMemAlloc(&d_b, sizeof(int) * N);
  //cuMemAlloc(&d_b, sizeof(int) * N);

  memset((void*)&b ,0x0 , 0x20);

  //kada se ovo promeni na 2 cuda ne radi
  //*((uint32_t*)0x204a0ff00) = 0x2; 
  cuMemcpyHtoD(d_a, a, sizeof(int)*N);   
  clear_nvctrl();
  
  push->cur = (uint32_t*)0x202c00020;
  PUSH_DATA(push ,0x20048100);  // BEGIN_NVC0(push ,0x4, NVC5C0_SET_OBJECT, 0x4); 
  PUSH_DATAh(push ,0x7fffcda00000); // %llx -> d_a
  PUSH_DATAl(push ,0x7fffcda00000);
  PUSH_DATAh(push ,0x7fffce700000);
  PUSH_DATAl(push ,0x7fffce700000);
  PUSH_DATA(push ,0x20018106); //METHOD 18 
  PUSH_DATA(push  , 0x28);
  BEGIN_NVC0(push ,0x4, NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE, 0x1);
  PUSH_DATA(push , 0x182);
  PUSH_DATA(push , 0x20038090); // BEGIN_NVC0(push ,0x4, NVC597_SET_L1_CONFIGURATION, 0x3); // 
  PUSH_DATA(push , 0x2);
  PUSH_DATA(push , 0x04a0ff30);
  PUSH_DATA(push , 0x2);
  BEGIN_NVC0(push ,0x4, NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE, 0x1);
  PUSH_DATA(push , 0x14);

  *((uint32_t*)0x200226040)= 0x2c0005c; 
  *((uint32_t*)0x200226044)= 0x2c0005c; 
  *((uint32_t*)0x200224008)= 0x2c00020; 
  *((uint32_t*)0x20022400c)= 0x3e02;    

  *((uint32_t*)0x20022608c) = 0x2;      
  *((uint32_t*)0x200226088) = 0x2;
  *((uint32_t*)0x204a0ff30) = 0x1; // ovo se menja

  int lmao = *((uint32_t*)0x204a0ff30);
  *door_bell = 0x90017; // VOVOVOVOVOVOVOVOVOVOVOVOVOVOVOVOVO

  // 0x200226000
  // control //memset((void*)0x200200000 , 0x0 , 0x200000);
  uint64_t k_1 = *((uint64_t*)0x7ffff7fab080);
  uint64_t stari = *((uint64_t*)0x204a0ff38);
  /*
  sleep(1); 
  *((uint64_t*)0x204a0ff38) =  *((uint64_t*)0x204a0ff38) + 0x3b9fdd20;
  printf("080 novi - stari = %lx, novi = %lx, stari = %lx \n" ,*((uint64_t*)0x7ffff7fab080)-k_1 , *((uint64_t*)0x7ffff7fab080), k_1); //080 se smanjuje
  printf("fff novi - stari = %lx, novi = %lx, stari = %lx \n", *((uint64_t*)0x204a0ff38) - stari , *((uint64_t*)0x204a0ff38) , stari);

  hexdump((void*)0x7fffce700000 , 0x10);

  printf("LOLOLOLOLOLOLOLOLO\n");

  */
  sleep(1);
  //munmap((void*)0x7ffff7fab000 , 0x7ffff7fbb000-0x7ffff7fab000);  
  //mmap((void*)0x7ffff7fab000,  0x7ffff7fbb000-0x7ffff7fab000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
//
  //cuMemcpyDtoH(b , d_a , sizeof(int)*N); 

  printf("080 novi - stari = %lx, novi = %lx, stari = %lx \n" ,*((uint64_t*)0x7ffff7fab080)-k_1 , *((uint64_t*)0x7ffff7fab080), k_1); //080 se smanjuje
  printf("fff novi - stari = %lx, novi = %lx, stari = %lx \n", *((uint64_t*)0x204a0ff38) - stari , *((uint64_t*)0x204a0ff38) , stari);

  hexdump((void*)0x7fffce700000 , 0x10);
  return 0;

}
/*

  std::thread t([](){ // 
    while(1){
      for (uint32_t * p=  (uint32_t*)0x204a00000 ;p < (uint32_t*)0x204c00000 ; p ++){
        if (p == (uint32_t*)0x204a0ff30){ printf("%p: %x \n" , p , *p); }
      }
      usleep(50 *1000);
    }
  });



p $_siginfo._sifields._sigfault.si_addr
for(uint32_t *ide_gas  = (uint32_t*)0x200200000;  ide_gas <(uint32_t*)0x200400000 ; ide_gas ++ ){
  if (*ide_gas != 0){
    printf("%p %x \n",ide_gas, *ide_gas);
  }
}

*/
