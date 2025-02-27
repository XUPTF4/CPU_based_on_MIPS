#ifndef __TRAP_H__
#define __TRAP_H__

void* memcpy(void* dest, const void* src, int n) {
  char* d = dest;
  const char* s = src;
  while(n--) *d++ = *s++;
  return dest;
}

void halt(int code);
__attribute__((noinline))
void check(int cond) {
  if (cond == 0) halt(1);
}

#endif
