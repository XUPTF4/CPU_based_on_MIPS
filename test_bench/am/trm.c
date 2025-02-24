extern char _heap_start;
extern char _stack_pointer;
int main();

#define cpu_trap(code) asm volatile("move $a0, %0; break" : : "r"(code))

void halt(int code) {
    cpu_trap(code);
    while (1)
        ;
}

void _trm_init() {
    int ret = main();
    halt(ret);
}