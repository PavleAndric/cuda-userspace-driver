#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

void clear_nvctrl(){memset((void*)0x200400000 ,0x0,0x203c00000-0x200400000);}

uint32_t *fromAdrr(uint64_t *arr , uint32_t size){

  //uint32_t ret[size * 2];
  uint32_t *ret = (uint32_t*)malloc((size * 2)  *sizeof(uint32_t));
  for(int i  = 0 ; i < size; i ++){
    ret[2*i] = arr[i] & 0x0000FFFFFFFF;
    ret[2*i+1] = (arr[i] & 0xFFFF00000000) >> 32;
  }
  return ret;
}

void dump(void *ptr, int len){
  int i = 0;
  for(uint32_t *ptr_ = (uint32_t*)ptr ; ptr_ < (uint32_t*)((uint64_t)ptr  + len); ptr_++){
    if (i % 16 == 0){printf("\n");}
    printf("%02x ", *ptr_);i++;
  }
  printf("\n");
}
  
void map(pid_t pid){
  
    char path[100];
    sprintf(path , "/proc/%d/maps" , pid);
    char buf[12000];
    FILE *f = fopen(path, "r");
    size_t bytes_read = fread(buf, 1, sizeof(buf) - 1, f);
    buf[bytes_read] = '\0';
    fclose(f);
    printf("%s\n" , buf);
}  
