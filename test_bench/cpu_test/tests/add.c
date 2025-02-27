#include <trap.h>

int add(int a, int b) {
    int c = a + b;
    return c;
}

int test_data[] = {0,          1,          2,          0x7fffffff,
                   0x80000000, 0x80000001, 0xfffffffe, 0xffffffff};
int ans[] = {
    0,          0x1, 0x2,        0x7fffffff, 0x80000000, 0x80000001, 0xfffffffe,
    0xffffffff, 0x1, 0x2,        0x3,        0x80000000, 0x80000001, 0x80000002,
    0xffffffff, 0,   0x2,        0x3,        0x4,        0x80000001, 0x80000002,
    0x80000003, 0,   0x1,        0x7fffffff, 0x80000000, 0x80000001, 0xfffffffe,
    0xffffffff, 0,   0x7ffffffd, 0x7ffffffe, 0x80000000, 0x80000001, 0x80000002,
    0xffffffff, 0,   0x1,        0x7ffffffe, 0x7fffffff, 0x80000001, 0x80000002,
    0x80000003, 0,   0x1,        0x2,        0x7fffffff, 0x80000000, 0xfffffffe,
    0xffffffff, 0,   0x7ffffffd, 0x7ffffffe, 0x7fffffff, 0xfffffffc, 0xfffffffd,
    0xffffffff, 0,   0x1,        0x7ffffffe, 0x7fffffff, 0x80000000, 0xfffffffd,
    0xfffffffe};

int main() {
    int i, j, ans_idx = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            int a = test_data[i];
            int b = test_data[j];
            int c = ans[ans_idx];
            ans_idx = ans_idx + 1;
            check(add(a, b) == c);
        }
        check(j == 8);
    }

    check(i == 8);

    return 0;
}