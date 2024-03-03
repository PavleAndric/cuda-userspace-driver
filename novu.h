#include <stdint.h>
struct nouveau_pushbuf {uint32_t *cur;};

struct nv_0_buff{
	uint32_t *cur;
	uint32_t *next;
	uint32_t *inc;
};


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