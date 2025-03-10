#include <trap.h>
#include <stdint.h>

extern void __am_asm_trap(void);

typedef struct area {
    void *start, *end;
} Area;

typedef struct context {
    unsigned int gpr[32];  // 寄存器
    unsigned int epc;      // 返回的函数体
} Context;                 // 33 个字

// 最小的 PCB，仅仅包含上下文，使用 33 个字大小
typedef union pcb {
    unsigned int stack[33];
    Context* cp;
} PCB;

PCB pcb[2], pcb_boot;
PCB* current = &pcb_boot;

// 系统调用
void yield() {
    asm volatile(
        "syscall\n\t"
        "nop"
        :
        :
        :);
}
int tag = 0;
Context* user_handler(Context* prev) {
    // 切换两个线程
    Context* c;
    tag++;
    if (tag % 2 == 0) {
        c = pcb[0].cp;
    } else {
        c = pcb[1].cp;
    }
    return c;
}

Context* __am_irq_handle(Context* c) {
    c = user_handler(c);

    return c;
}

Context* kcontext(Area kstack, void (*entry)(void*), void* arg) {
    Context* ctp = (Context*)kstack.end - 1;
    // 传参到 a0 (gpr[4])
    ctp->gpr[4] = (unsigned int)arg;
    // 设置异常返回地址 (epc)
    ctp->epc = (unsigned int)entry;
    return ctp;
}

// 这里会设计一个简单的OS

// 首先利用 kcontext 初始化两个进程。
// 然后第一次调用 yield，切换到 A 的上下文，

// A 进程在运行后，直接 yield，切换到 B

// 然后在 B 进程中同样触发 yield,然后继续触发切换上下文返回到 A

// 循环往复

// A 和 B 是同一个代码段，以减小体积。
// A 和 B 的功能都是给已经实现的 “UART”上发送一个字符，A进程 发送 `A`，B进程
// 发送 `B` 预期的观察效果是，在数码管上可以看到 'A' 和 'B' 交替输出

// 打印函数
void show(unsigned int char_x4) {
    volatile unsigned int* seg_register = (volatile unsigned int*)(1023 << 2);
    *seg_register = char_x4;
    volatile unsigned int* leds_register = (volatile unsigned int*)(1022 << 2);
    *leds_register = char_x4;
}


// 程序
void f(void* arg) {
    while (1) {
        if ((uintptr_t)arg == 1) {
            show(0xaaaaaaaa);  // A 进程打印 A...
        } else {
            show(0x55555555);  // B 进程打印 B...
        }
        yield();
    }
}

int main() {
    pcb[0].cp = kcontext((Area){pcb[0].stack, &pcb[0] + 1}, f, (void*)1L);
    pcb[1].cp = kcontext((Area){pcb[1].stack, &pcb[1] + 1}, f, (void*)2L);
    yield();
    check(0);  // Should not reach here!
    return 0;
}
