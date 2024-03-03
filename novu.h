#include <stdint.h>

struct nouveau_pushbuf {uint32_t *cur;};

struct nv_0_buff{
	uint32_t *cur;
	uint32_t *next;
	uint32_t *inc;
};

/* command  buffer and nv0 mmap */
typedef struct {
  uint64_t* door_bell;
  NvHandle ctrl;      /*nvidiactl mmap  200400000-203c00000 */  
  NvHandle nv_0;      /*nvidia0   mmap  200200000-200400000 */  
} MmapObjects;

/* main objects*/
typedef struct {
  NvHandle root;
  NvHandle device;
  NvHandle sub_device;
  NvHandle turing_user;
  NvHandle fermi_1;
  NvHandle fermi_2;
  NvHandle mem_virtual;
  NvHandle kepler_group;
  NvHandle fermi_context;
} ObjectHandles;

static inline void
ITER(struct nv_0_buff *buff, uint32_t command){

	*buff->cur++ = *buff->next;
	*buff->cur++ = command;
	*buff->inc += 1;
	*(buff->inc + 1) += 1;
}

static inline uint32_t
NVC0_FIFO_PKHDR_SQ(int subc, int mthd, unsigned size)
{
   return 0x20000000 | (size << 16) | (subc << 13) | (mthd >> 2);
}
static inline uint32_t
NVC0_FIFO_PKHDR_NI(int subc, int mthd, unsigned size)
{
   return 0x60000000 | (size << 16) | (subc << 13) | (mthd >> 2);
}
static inline uint32_t
NV50_FIFO_PKHDR(int subc, int mthd, unsigned size)
{
   return 0x00000000 | (size << 18) | (subc << 13) | mthd;
}

static inline void
PUSH_DATA(struct nouveau_pushbuf *push, uint32_t data)
{
   *push->cur++ = data;
}
static inline void
PUSH_DATAh(struct nouveau_pushbuf *push, uint64_t data)
{
   *push->cur++ = (uint32_t)(data >> 32);
}
static inline void
PUSH_DATAl(struct nouveau_pushbuf *push, uint64_t data)
{
   *push->cur++ = (uint32_t)(data >> 0);
}

static inline void
BEGIN_NV04(struct nouveau_pushbuf *push, int subc, int mthd, unsigned size)
{
   PUSH_DATA (push, NV50_FIFO_PKHDR(subc, mthd, size));
}

static inline void
BEGIN_NVC0(struct nouveau_pushbuf *push, int subc, int mthd, unsigned size)
{
   PUSH_DATA (push, NVC0_FIFO_PKHDR_SQ(subc, mthd, size));
}

static inline void
BEGIN_NIC0(struct nouveau_pushbuf *push, int subc, int mthd, unsigned size)
{
   PUSH_DATA (push, NVC0_FIFO_PKHDR_NI(subc, mthd, size));
}

void gpu_setup(nv_0_buff *nv_buff , nouveau_pushbuf *push){

  *nv_buff->cur++ = 0x400000;
  *nv_buff->cur++ = 0x2a602;
  *nv_buff->next =  0x4002a4;
  *nv_buff->inc =  0x1;
  *(nv_buff->inc + 1) =  0x1;

  PUSH_DATA(push , 0x20012000);
  PUSH_DATA(push , 0xc5c0);
  PUSH_DATA(push , 0x200120a8);   // NVC5C0_SET_SHADER_SHARED_MEMORY_WINDOW_A
  PUSH_DATA(push , 0x7fff);
  PUSH_DATA(push , 0x200120a9);   // NVC5C0_SET_SHADER_SHARED_MEMORY_WINDOW_B
  PUSH_DATA(push , 0xed000000);
  PUSH_DATA(push , 0x200120b9);   // NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_A
  PUSH_DATA(push , 0x0);
  PUSH_DATA(push , 0x200120b9);   // NVC5C0_SET_SHADER_LOCAL_MEMORY_NON_THROTTLED_B
  PUSH_DATA(push , 0x8);     // ????????
}
/* USER */
uint32_t* HtoDCpy(nouveau_pushbuf *push , uint32_t* curr , uint64_t addr ,uint32_t line_len, uint32_t* data, uint32_t range){

  push->cur = curr;
  BEGIN_NVC0(push , 0x1, NVC5C0_OFFSET_OUT_UPPER, 0x2);
  PUSH_DATAh(push , addr);
  PUSH_DATAl(push , addr);
  BEGIN_NVC0(push , 0x1, NVC5C0_LINE_LENGTH_IN, 0x2); 
  PUSH_DATA(push , line_len);
  PUSH_DATA(push , 0x1);
  BEGIN_NVC0(push , 0x1 ,NVC5C0_LAUNCH_DMA ,0x1);  // 0x2001206c
  PUSH_DATA(push , 0x41);
  BEGIN_NIC0(push , 0x1, NVC597_LOAD_INLINE_DATA, range); 
  for(int  i = 0 ; i < range; i ++){PUSH_DATA(push , data[i]);}
  return push->cur;
}

void DtoHCpy(nouveau_pushbuf *push , uint32_t* curr , uint64_t addr_1 ,uint64_t addr_2){
  
  push->cur = curr;
  PUSH_DATA(push ,0x20048100);  // TODO: popravi ovo
  PUSH_DATAh(push ,(uint64_t)addr_1); 
  PUSH_DATAl(push ,(uint64_t)addr_1);
  PUSH_DATAh(push ,(uint64_t)addr_2);
  PUSH_DATAl(push ,(uint64_t)addr_2);
  PUSH_DATA(push ,0x20018106);  //TODO:  popravi ovo
  PUSH_DATA(push ,0x28);
  BEGIN_NVC0(push ,0x4, NVC597_SET_PS_OUTPUT_SAMPLE_MASK_USAGE, 0x1);
  PUSH_DATA(push , 0x182);
}

void ring(uint64_t *door_bell, uint32_t work_token){*door_bell = work_token;usleep(50000);}
