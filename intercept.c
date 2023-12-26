#define _GNU_SOURCE
#define _FCNTL_H
#include <dlfcn.h>
#include <unistd.h>
#include <stdio.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <bits/fcntl.h>
#include <stddef.h>

int (*my_write)(int , const void* , size_t);
ssize_t write(int fd, const void *buf, size_t count) {

  printf(" -intercept- write syscall %d, %ld , %s\n" ,fd ,count , (char*)buf);
  my_write = dlsym(RTLD_NEXT , "write");
  int result = my_write(fd, buf, count);
  return result;
}

int (*my_brk)(void *);
#undef brk
int brk(void *addr){

  printf("syscall brk\n");
  my_brk  = dlsym(RTLD_NEXT , "brk");
  int result  = my_brk(addr);
  return result;
}

void* (*real_malloc)(size_t);
void *malloc(size_t size)
{
  real_malloc = dlsym(RTLD_NEXT, "malloc");
  fprintf(stderr, "malloc(%zu) = " , size);
  void *p = NULL;
  p = real_malloc(size);
  fprintf(stderr, "%p\n", p);
  return p;
}