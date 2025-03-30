#ifndef __TRAP_H__
#define __TRAP_H__

extern void halt(int code);

__attribute__((noinline)) void check(int cond) {
    if (cond == 0)
        halt(1);
}

#endif
