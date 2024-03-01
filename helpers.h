#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>


void dump_CB(void* one, void* two){
  uint32_t *ptr = (uint32_t*)one; 
  while (ptr != (uint32_t*)two) {
    
     if (*ptr != 0){
      int k = 0;
      int ide_gas = *ptr;
      int type =  ide_gas & 0xF0000000;
      int size = (ide_gas & 0x0FFF0000) >> 16;
      int subc = (ide_gas & 0x0000FF00) >> 13;
      int mthd = (ide_gas & 0x000000FF) << 2;
      if ((*ptr > 0x20000000 && *ptr < 0x30000000) ||(*ptr > 0x60000000 && *ptr < 0x70000000) ){
        printf("%p: %8x | type:%x  size:%x subc:%x mthd:%x " ,ptr, *ptr, type, size, subc , mthd);
        switch  (mthd){
          case NVC5C0_SET_OBJECT: {printf("NVC5C0_SET_OBJECT\n");break;}
          case NVC5C0_NO_OPERATION: {printf("NVC5C0_NO_OPERATION\n");break;}
          case NVC5C0_SET_SHADER_SHARED_MEMORY_WINDOW_A: {printf("NVC5C0_SET_SHADER_SHARED_MEMORY_WINDOW_A\n");break;}
          case NVC5C0_SET_SHADER_SHARED_MEMORY_WINDOW_B: {printf("NVC5C0_SET_SHADER_SHARED_MEMORY_WINDOW_B\n");break;}
          case NVC5C0_SET_SPA_VERSION: {printf("NVC5C0_SET_SPA_VERSION\n");break;}
          case NVC5C0_SET_CWD_REF_COUNTER: {printf("NVC5C0_SET_CWD_REF_COUNTER\n");break;}
          case NVC5C0_SET_RESERVED_SW_METHOD07: {printf("NVC5C0_SET_RESERVED_SW_METHOD07\n");break;}
          case NVC5C0_SET_RESERVED_SW_METHOD10: {printf("NVC5C0_SET_RESERVED_SW_METHOD10\n");break;}
          case NVC5C0_SET_RESERVED_SW_METHOD09: {printf("NVC5C0_SET_RESERVED_SW_METHOD09\n");break;}
          case NVC5C0_SET_VALID_SPAN_OVERFLOW_AREA_A: {printf("NVC5C0_SET_VALID_SPAN_OVERFLOW_AREA_A\n");break;}
          case NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_C: {printf("NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_C\n");break;}
          case NVC5C0_INVALIDATE_SKED_CACHES: {printf("NVC5C0_INVALIDATE_SKED_CACHES\n");break;}
          case NVC5C0_LAUNCH_DMA: {printf("NVC5C0_LAUNCH_DMA\n");break;}
          case NVC5C0_OFFSET_OUT_UPPER: {printf("NVC5C0_OFFSET_OUT_UPPER\n");break;}
          case NVC5C0_LINE_LENGTH_IN: {printf("NVC5C0_LINE_LENGTH_IN\n");break;}
          case NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_A: {printf("NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_A\n");break;}
          case NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_B: {printf("NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_B\n");break;}
          case NVC5C0_SET_INLINE_QMD_ADDRESS_A: {printf("NVC5C0_SET_INLINE_QMD_ADDRESS_A\n");break;}
          case NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE: {printf("NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE\n");break;}
          //ase NVC597_SET_STREAM_OUT_BUFFER_LOAD_WRITE_POINTER: {printf("NVC597_SET_STREAM_OUT_BUFFER_LOAD_WRITE_POINTER\n");break;} nikad ovo ne koristis
          //case NVC597_SET_ROOT_TABLE_VISIBILITY: {printf("NVC597_SET_ROOT_TABLE_VISIBILITY\n");break;}
          case NVC597_SET_L1_CONFIGURATION: {printf("NVC597_SET_L1_CONFIGURATION\n");break;}
          case NVC597_LOAD_INLINE_DATA: {printf("NVC597_LOAD_INLINE_DATA\n");break;}
          default:printf("not important :) \n");
        }
        for (int j = 0 ; j < size; j ++){
          ptr++;
          if (j % 4 == 0){ printf("\n\t");}
          printf("%08x ",*ptr);
        }
        if (size != 0){printf("\n ");}
      }
   
    } 
    ++ptr;
  }
}
void dump(void *ptr, int len){
  int i = 0;
  for(uint32_t *ptr_ = (uint32_t*)ptr ; ptr_ < (uint32_t*)((uint64_t)ptr  + len); ptr_++){
    if (i % 16 == 0){printf("\n");}
    printf("%02x ", *ptr_);i++;
  }
  printf("\n");
}

void clear_nvctrl(){memset((void*)0x200400000 ,0x0,0x203c00000-0x200400000);}
  
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


/*

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
    
    else if  (mthd == NVC597_LOAD_INLINE_DATA) {
        printf("NVC597_LOAD_INLINE_DATA\n");
        uint32_t *rom_1 = ptr+1;
        uint32_t *rom_2 = ptr+2;
        uint64_t *f  = NULL;
        if (*rom_1 > 0x10){
          f = (uint64_t *)((uint64_t)(*rom_2) << 32 | (uint32_t)(*rom_1));
        }
        if (f != NULL){
          printf("ide_gas = %p\n" , f);
        }
    }
  } 
*/
