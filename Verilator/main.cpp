#include <stdbool.h>
#include <stdint.h>
#include "VCPU.h"
#include "VCPU___024root.h"

#include "verilated_fst_c.h"
VerilatedFstC* tfp = new VerilatedFstC;

vluint64_t main_time = 0;  // initial 仿真时间

VCPU* top = new VCPU;

void step() {
    top->clk = 0;
    top->eval();

    tfp->dump(main_time);  // 记录波形数据
    main_time++;           // 时间递增

    top->clk = 1;
    top->eval();

    tfp->dump(main_time);
    main_time++;
}
void reset(int n) {
    top->rst = 1;
    while (n--) {
        step();
    }
    top->rst = 0;
}

// 执行一步
// int i = 0;
void stepi() {
    step();
}

void cpu_exec(uint64_t n) {
    // 执行 n 条指令
    while (n) {
        stepi();
        if(top->rootp->CPU__DOT__idu__DOT__is_break){
            // 执行结束
            // 检查 is_OK
            if(top->rootp->CPU__DOT__exu_is_OK){
                printf(" HIT bad trap.");
            }
            else printf(" HIT good trap.");
        }
        n--;
    }
    top->final();
    tfp->close();
}

int main(int argc, char* argv[]) {
    Verilated::traceEverOn(true);  //导出 FST 波形需要加此语句
    top->trace(tfp, 99);
    tfp->open("wave.vcd");

    reset(2);

    cpu_exec(10000); // 先执行 200 个指令周期

    return 0;
}
