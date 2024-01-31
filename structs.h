#include <stdint.h>
#include <stdio.h>
#include <string.h>
#define SIZE 2
#define ARR_SIZE 0x3800000

uint32_t A[ARR_SIZE];
uint32_t B[ARR_SIZE];

struct parse { uint32_t *str; uint32_t *end; };
struct parse parseArray[] = {

  //{ .str = (uint32_t*)0x200200000, .end = (uint32_t*)0x200400000 },    //_dev_nvidia0
  //{ .str = (uint32_t*)0x200400000, .end = (uint32_t*)0x203c00000 },    //_dev_nvidiactl
  //{ .str = (uint32_t*)0x204a00000, .end = (uint32_t*)0x204c00000 },    //_dev_nvidiactl
  //{ .str = (uint32_t*)0x204c00000, .end = (uint32_t*)0x204e00000 },    //_dev_nvidiactl
  //{ .str = (uint32_t*)0x204e00000, .end = (uint32_t*)0x205000000 },    //_dev_nvidiactl
  //{ .str = (uint32_t*)0x205000000, .end = (uint32_t*)0x205200000 },    //_dev_nvidia-uvm
  //{ .str = (uint32_t*)0x205200000, .end = (uint32_t*)0x205400000 },    //_dev_nvidiactl
  //{ .str = (uint32_t*)0x205600000, .end = (uint32_t*)0x205800000 },    //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffce400000, .end = (uint32_t*)0x7fffce600000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffcf000000, .end = (uint32_t*)0x7fffcf200000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffcf400000, .end = (uint32_t*)0x7fffcf577000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2fdf000, .end = (uint32_t*)0x7fffe2fe0000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2fe0000, .end = (uint32_t*)0x7fffe2fe1000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2fe1000, .end = (uint32_t*)0x7fffe2fe2000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2fe2000, .end = (uint32_t*)0x7fffe2fe3000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2fe3000, .end = (uint32_t*)0x7fffe2fe4000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2fe4000, .end = (uint32_t*)0x7fffe2fe5000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2fe5000, .end = (uint32_t*)0x7fffe2fe6000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2fe6000, .end = (uint32_t*)0x7fffe2fe7000 }, //_dev_nvidiactl
  // { .str = (uint32_t*)0x7fffe2fe7000, .end = (uint32_t*)0x7fffe2fe8000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2fe8000, .end = (uint32_t*)0x7fffe2fe9000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2fe9000, .end = (uint32_t*)0x7fffe2fea000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2fea000, .end = (uint32_t*)0x7fffe2feb000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2feb000, .end = (uint32_t*)0x7fffe2fec000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2fec000, .end = (uint32_t*)0x7fffe2fed000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2fed000, .end = (uint32_t*)0x7fffe2fee000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2fee000, .end = (uint32_t*)0x7fffe2fef000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2fef000, .end = (uint32_t*)0x7fffe2ff0000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2ff0000, .end = (uint32_t*)0x7fffe2ff1000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2ff1000, .end = (uint32_t*)0x7fffe2ff2000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7fffe2ff2000, .end = (uint32_t*)0x7fffe2ff3000 }, //_dev_nvidiactl
  //{ .str = (uint32_t*)0x7ffff7fab000, .end = (uint32_t*)0x7ffff7fbb000 } //_dev_nvidia0

};
void clear_arrs(){
  memset(&A , 0x0 , ARR_SIZE);
  memset(&B , 0x0 , ARR_SIZE);
}

void make_arr(int broj){
  for(int i = 0 ; i < SIZE; i ++){
    int j = 0;
    for(uint32_t* start = parseArray[i].str; start < parseArray[i].end ; start++){
      if (start != NULL) { 
        if (broj == 0){A[j] = (uint32_t)*start; j++;}
        if (broj == 1){B[j] = (uint32_t)*start; j++;}
      }
    } 
  } 
}
void compare(){
  for(int i = 0 ; i < ARR_SIZE ;  i ++){
      if (B[i] != A[i]){
        printf("%x->%x \n" , A[i] , B[i]);
    }
  }
}

/*
JAs
00 00 00 00 00 
0->20022062 
0->7fff 
0->cda00000 
0->20022060 
0->14 
0->1 
0->2001206c 
0->41 
0->6005206d 
0->1 
0->2 
0->3 
0->4 
0->200426c0 
0->2 
0->4a0fff0 
0->68 
0->20048100 
0->7fff 
0->cda00000 
0->7fff 
0->ce700000 
0->20018106 
0->14 
0->200180c0 
0->182 
0->20038090 
0->2 
0->4a0ff30 
0->2 
0->200180c0 
0->14 

CUDA
00 00 00 00 00 
0->20022062 
0->7fff 
0->cda00000 
0->20022060 
0->14 
0->1 
0->2001206c 
0->41 
0->6005206d 
0->1 
0->2 
0->3 
0->4 
0->200426c0 
0->2 
0->4a0fff0 
0->68 
0->20048100 
0->7fff 
0->cda00000 
0->7fff 
0->ce700000 
0->20018106 
0->14 
0->200180c0 
0->182 
0->20038090 
0->2 
0->4a0ff30 
0->2 
0->200180c0 
0->14 */