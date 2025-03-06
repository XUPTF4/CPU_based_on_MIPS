// 这里实现系统调用，用来修改 CPU 的某些状态寄存器
// 上下文

#include "/home/luyoung/CPU_based_on_MIPS/test_bench/cpu_test/include/trap.h"

PCB pcb[2], pcb_boot;
PCB* current = &pcb_boot;

static Context* schedule(Context* prev) {
    current->cp = prev;
    current = (current == &pcb[0] ? &pcb[1] : &pcb[0]);
    return current->cp;
}

// 切换上下文
// 内联汇编

unsigned int read_epc() {
    unsigned int epc;
    asm volatile("mfc0 %0, $14" : "=r"(epc));
    return epc;
}

unsigned int read_cause() {
    unsigned int cause;
    asm volatile("mfc0 %0, $13"
                 : "=r"(cause));  // MIPS中，Cause寄存器是CP0寄存器13
    return cause;
}

void write_epc(unsigned int epc) {
    asm volatile("mtc0 %0, $14" : : "r"(epc));
}

void trap() {
    // 保存当前上下文
    Context* prev_ctx = current->cp;

    // 保存通用寄存器
    asm volatile(
        "sw $0, 0(%0)\n"
        "sw $1, 4(%0)\n"
        "sw $2, 8(%0)\n"
        "sw $3, 12(%0)\n"
        "sw $4, 16(%0)\n"
        "sw $5, 20(%0)\n"
        "sw $6, 24(%0)\n"
        "sw $7, 28(%0)\n"
        "sw $8, 32(%0)\n"
        "sw $9, 36(%0)\n"
        "sw $10, 40(%0)\n"
        "sw $11, 44(%0)\n"
        "sw $12, 48(%0)\n"
        "sw $13, 52(%0)\n"
        "sw $14, 56(%0)\n"
        "sw $15, 60(%0)\n"
        "sw $16, 64(%0)\n"
        "sw $17, 68(%0)\n"
        "sw $18, 72(%0)\n"
        "sw $19, 76(%0)\n"
        "sw $20, 80(%0)\n"
        "sw $21, 84(%0)\n"
        "sw $22, 88(%0)\n"
        "sw $23, 92(%0)\n"
        "sw $24, 96(%0)\n"
        "sw $25, 100(%0)\n"
        "sw $26, 104(%0)\n"
        "sw $27, 108(%0)\n"
        "sw $28, 112(%0)\n"
        "sw $29, 116(%0)\n"
        "sw $30, 120(%0)\n"
        "sw $31, 124(%0)\n"
        :
        : "r"(prev_ctx->gpr)
        : "memory");

    // 保存epc和cause
    prev_ctx->epc = read_epc();
    prev_ctx->cause = read_cause();

    // 调用schedule切换上下文
    Context* new_ctx = schedule(prev_ctx);

    // 设置新的epc为原来的epc +4，跳过异常指令
    new_ctx->epc += 4;

    // 恢复通用寄存器
    asm volatile(
        "lw $0, 0(%0)\n"
        "lw $1, 4(%0)\n"
        "lw $2, 8(%0)\n"
        "lw $3, 12(%0)\n"
        "lw $4, 16(%0)\n"
        "lw $5, 20(%0)\n"
        "lw $6, 24(%0)\n"
        "lw $7, 28(%0)\n"
        "lw $8, 32(%0)\n"
        "lw $9, 36(%0)\n"
        "lw $10, 40(%0)\n"
        "lw $11, 44(%0)\n"
        "lw $12, 48(%0)\n"
        "lw $13, 52(%0)\n"
        "lw $14, 56(%0)\n"
        "lw $15, 60(%0)\n"
        "lw $16, 64(%0)\n"
        "lw $17, 68(%0)\n"
        "lw $18, 72(%0)\n"
        "lw $19, 76(%0)\n"
        "lw $20, 80(%0)\n"
        "lw $21, 84(%0)\n"
        "lw $22, 88(%0)\n"
        "lw $23, 92(%0)\n"
        "lw $24, 96(%0)\n"
        "lw $25, 100(%0)\n"
        "lw $26, 104(%0)\n"
        "lw $27, 108(%0)\n"
        "lw $28, 112(%0)\n"
        "lw $29, 116(%0)\n"
        "lw $30, 120(%0)\n"
        "lw $31, 124(%0)\n"
        :
        : "r"(new_ctx->gpr)
        : "memory");

    // 恢复epc
    write_epc(new_ctx->epc);

    // 返回，使用eret指令
    asm volatile("eret");
}

void yield() {
    trap();
}

Context* kcontext(Area kstack, void (*entry)(void*), void* arg) {
    Context* ctp = (Context*)kstack.end - 1;  //
    ctp->gpr[4] = (unsigned int)arg;          // 传参到 a0
    ctp->epc = (unsigned int)entry;
    return ctp;
}
