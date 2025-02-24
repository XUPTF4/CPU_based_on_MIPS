extern char _heap_start;
int main();

// #define cpu_trap(code) asm volatile("li a0, %0; break" : : "r"(code))

void halt(int code) {
    asm volatile("move $a0, %0" : : "r"(code));
    asm("break");
    while (1)
        ;
}

void _trm_init() {
    int ret = main();
    halt(ret);
}