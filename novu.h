#include <stdint.h>
#define NVC0_PUSH_EXPLICIT_SPACE_CHECKING
#define NV50_PUSH_EXPLICIT_SPACE_CHECKING

struct nouveau_pushbuf {
  uint32_t *cur;
  uint32_t *end;
};


// <<
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

// PUSH
static inline uint32_t
PUSH_AVAIL(struct nouveau_pushbuf *push)
{
   return push->end - push->cur;
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
PUSH_DATAhl(struct nouveau_pushbuf *push, uint64_t data)
{
   PUSH_DATAh(push, data);
   PUSH_DATAl(push, data);
}
//BEGIN
static inline void
BEGIN_NV04(struct nouveau_pushbuf *push, int subc, int mthd, unsigned size)
{
#ifndef NV50_PUSH_EXPLICIT_SPACE_CHECKING
   PUSH_SPACE(push, size + 1);
#endif
   PUSH_DATA (push, NV50_FIFO_PKHDR(subc, mthd, size));
}

static inline void
BEGIN_NVC0(struct nouveau_pushbuf *push, int subc, int mthd, unsigned size)
{
#ifndef NVC0_PUSH_EXPLICIT_SPACE_CHECKING
   PUSH_SPACE(push, size + 1);
#endif
   PUSH_DATA (push, NVC0_FIFO_PKHDR_SQ(subc, mthd, size));
}

