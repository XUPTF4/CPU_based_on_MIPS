#ifndef __TRAP_H__
#define __TRAP_H__

void halt(int code);
__attribute__((noinline)) void check(int cond) {
    if (cond == 0)
        halt(1);
}

typedef struct {
    void *start, *end;
} Area;

typedef struct context {
    unsigned int gpr[32];  // 寄存器
    unsigned int epc;      // 返回的 epc
    unsigned int cause;    // 中断号
} Context;                 // 34 个字节

typedef union {
    unsigned int kstack[64];
    struct {
        Context* cp;
    };
} PCB;

extern PCB pcb[2], pcb_boot;
extern PCB* current;

#endif
