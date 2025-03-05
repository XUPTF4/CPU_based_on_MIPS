// 这里实现系统调用，用来修改 CPU 的某些状态寄存器
// 上下文
struct Context {
    unsigned int GPR[32];
    unsigned int epc;
    unsigned int cause;
  }; // 34 个字节
// 上下文，包括寄存器、epc，也就是异常返回地址，这里应该+4，就是异常指令后的地址、
void yield() {

}

// syscall 之后，CPU 开始执行特定的代码，完成cause 保存、epc 保存、以及返回到 注册的异常处理程序


// 注册异常处理程序
static Context* (*user_handler)(Context*) = NULL;

int cte_init(Context* (*handler)(Context*)) {
    // initialize exception entry
    asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

    // register event handler
    user_handler = handler;

    return 1;
}

Context* kcontext(Area kstack, void (*entry)(void*), void* arg) {
    
    Context* ctp = (Context*)kstack.end - 1;
    ctp->gpr[10] = (uintptr_t)arg;  // 传参到 a0
    ctp->mepc = (uintptr_t)entry;
    return ctp;
}


unsigned int isa_raise_intr(unsigned int  NO, unsigned int epc) {

    cpu.csr.mcause = NO;
    cpu.csr.mepc = epc;
    return cpu.csr.mtvec;
}
