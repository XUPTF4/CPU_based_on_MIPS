#include <trap.h>
int main() {
    // 测试加法和减法
    int a = 10;
    int b = 5;
    int result;

    // 加法
    result = a + b;
    check(result == 15);  // 检查加法结果

    // 减法
    result = a - b;
    check(result == 5);  // 检查减法结果

    // 测试分支跳转 (if-else)
    if (result > 0) {
        check(result > 0);  // 如果结果大于0，应进入if分支
    } else if (result < 0) {
        check(result < 0);  // 不应该进入else if 分支
    } else {
        check(result == 0);  // 不应该进入else分支
    }

    // 测试条件跳转 (while loop)
    int counter = 0;
    while (counter < 5) {
        counter++;
    }
    check(counter == 5);  // 验证循环后的值是否为5

    return 0;
}