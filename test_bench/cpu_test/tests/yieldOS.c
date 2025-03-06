#include <trap.h>

typedef struct area {
    void *start, *end;
} Area;

typedef struct context {
    unsigned int gpr[32];  // 寄存器
    unsigned int epc;      // 返回的 epc--->pc+4
} Context;                 // 33 个字

// 最小的 PCB，仅仅包含上下文，使用 33 个字大小
typedef union pcb {
    unsigned int stack[33];
    struct {
        Context* cp;
    };
} PCB;

PCB pcb[2], pcb_boot;
PCB* current = &pcb_boot;

// 系统调用
void yield() {
    asm volatile(
        "syscall\n\t"
        "nop"
        : : :
    );
}

// 将当前所有的状态保存到 pcb 中

void save_context() {
    asm volatile(
        "sw $0, 0(%0)\n\t"
        "sw $at, 4(%0)\n\t"
        "sw $v0, 8(%0)\n\t"
        "sw $v1, 12(%0)\n\t"
        "sw $a0, 16(%0)\n\t"
        // "sw $epc, 128(%0)\n\t"
        :
        : "r"(current->cp->gpr)
        : "memory");
}

// 恢复上下文
void restore_context() {
    asm volatile(
        "lw $0, 0(%0)\n\t"
        "lw $at, 4(%0)\n\t"
        "lw $v0, 8(%0)\n\t" // 写的是 32
        "lw $v1, 12(%0)\n\t"
        "lw $a0, 16(%0)\n\t"

        // "lw $epc, 128(%0)\n\t"
        :
        : "r"(current->cp->gpr)
        : "memory");

    asm volatile(
        "lw $t0, 128(%0)\n\t"  // 将当前上下文的 epc 放到 CP0
        "mtc0 $t0, $14\n\t"
        :
        : "r"(current->cp->gpr)
        : "memory");
}

void schedule() {
    current = (current == &pcb[0] ? &pcb[1] : &pcb[0]);
}

void exception_handler() {
    // 1. 保存当前上下文
    save_context();

    // 2. 选择下一个要执行的上下文
    schedule();

    // 3. 恢复新的上下文
    restore_context();

    // 4. 返回到新的上下文（ERET 指令）
    asm volatile("eret");
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
void print(unsigned int char_x4) {
    volatile unsigned int* seg_register = (volatile unsigned int*)(1023 << 2);
    *seg_register = char_x4;
}

// 程序
void f(void* arg) {
    unsigned int* arg_ptr =
        (unsigned int*)arg;  // 将 void* 转换为 unsigned int*

    while (1) {
        if (*arg_ptr == 1) {    // 解引用 unsigned int*
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
    return 0;
}
