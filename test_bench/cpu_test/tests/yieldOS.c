#include "/home/luyoung/CPU_based_on_MIPS/test_bench/cpu_test/include/trap.h"


void yield();
Context* kcontext(Area kstack, void (*entry)(void*), void* arg);

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
void print(unsigned int char_x4) {
    volatile unsigned int* seg_register = (volatile unsigned int*)(1023 << 2);
    *seg_register = char_x4;
}

// 程序
static void f(void* arg) {
    while (1) {
        if ((unsigned int)(*arg) == 1) {
            print(0xaaaaaaaa);  // A 进程打印 A

        } else {
            print(0xbbbbbbbb);  // B 进程打印 B
        }
        yield();
    }
}

int main() {
    pcb[0].cp = kcontext((Area){pcb[0].stack, &pcb[0] + 1}, f, (void*)1L);
    pcb[1].cp = kcontext((Area){pcb[1].stack, &pcb[1] + 1}, f, (void*)2L);
    yield();
    check(0);  // Should not reach here!
}
