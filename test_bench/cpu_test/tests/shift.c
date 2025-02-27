#include <trap.h>

unsigned test[] = {0x12345678, 0x98765432, 0x0,  0xeffa1000,
                   0x7fffffff, 0x80000000, 0x33, 0xffffffff};

unsigned srl_ans[] = {0x2468ac, 0x130eca8, 0x0, 0x1dff420,
                      0xffffff, 0x1000000, 0x0, 0x1ffffff};

int main() {
    unsigned i;

    for (i = 0; i < 8; i++) {
        check((test[i] >> 7) == srl_ans[i]);
    }
    return 0;
}