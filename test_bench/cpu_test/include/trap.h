#ifndef __TRAP_H__
#define __TRAP_H__

#define bool int

void halt(int code);
__attribute__((noinline))
void check(bool cond) {
  if (!cond) halt(1);
}

#endif
