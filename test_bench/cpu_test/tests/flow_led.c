#include <trap.h>

// 地址大小一共 4K
// 内存区域划分：
// 数码管 8 个，一共 4 byte，1 个 MIPS32 字
// 8 个 switch 作为输入，一个 byte，1 个 MIPS32 字
// 16 个 leds 做为输出，两个 byte，1个 MIPS32 字

// 综上，一中可行的地址划分为(从高地址扩展)：
// 1023,1022,1021, 也即是 * << 2

#include <stdint.h>  // 包含 uint32_t 的定义

int main() {
    volatile uint32_t* led_register =
        (volatile uint32_t*)(1023 << 2);  // 将地址转换为指针

    while (1) {
        *led_register = 0xffffffff;  // 使用指针解引用操作
    }

    return 0;
}