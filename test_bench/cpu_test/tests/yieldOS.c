#include "trap.h"

// 这里会设计一个简单的OS

// 首先利用 kcontext 初始化两个进程。
// 然后第一次调用 yield，切换到 A 的上下文，

// A 进程在运行后，直接 yield，切换到 B

// 然后在 B 进程中同样触发 yield,然后继续触发切换上下文返回到 A

// 循环往复

// A 和 B 是同一个代码段，以减小体积。
// A 和 B 的功能都是给已经实现的 “UART”上发送一个字符，A进程 发送 `A`，B进程
// 发送 `B` 预期的观察效果是，在数码管上可以看到 'A' 和 'B' 交替输出

typedef struct {
    uint32_t regs[32];  // 寄存器组
    uint32_t epc;       // 异常返回地址
    uint32_t status;    // 状态寄存器
} TCB;


//

    typedef union {
    uint32_t stack[64];
    struct {
        Context* cp;
    };
} PCB;
static PCB pcb[2], pcb_boot, *current = &pcb_boot;

static void f(void* arg) {
    while (1) {
        putch("?AB"[(uintptr_t)arg > 2 ? 0 : (uintptr_t)arg]);
        for (int volatile i = 0; i < 100000; i++)
            ;
        yield();
    }
}

static Context* schedule(Context* prev) {
    current->cp = prev;
    current = (current == &pcb[0] ? &pcb[1] : &pcb[0]);
    return current->cp;
}

int main() {
    cte_init(schedule);
    pcb[0].cp = kcontext((Area){pcb[0].stack, &pcb[0] + 1}, f, (void*)1L);
    pcb[1].cp = kcontext((Area){pcb[1].stack, &pcb[1] + 1}, f, (void*)2L);
    yield();
    check(0);  // Should not reach here!
}
