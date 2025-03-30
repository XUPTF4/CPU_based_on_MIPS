# CPU_based_on_MIPS

基于 MIPS 指令集的 32 位模型机设计与 FPGA 实现

## 项目运行指南

### 快速开始

在目录 `test_bench/cpu_test` 中输入：
```bash
make clean && make build ALL=yieldOS
```
接着在项目根目录输入：

```bash
make run
```
就可以在 verilatoer 中仿真了，通过查看波形图（借助 vscode 中的插件 surfer）就可以看到 yieldOS 的仿真情况了。

这个 yieldOS 是不符合规范的，只是一个实例。

## 板子

FPGA 在 xc7a200tfbg676ABX1733（事实上， 对应着实验室 xc7a200tfbg676-2 的板子） 板子上运行的案例程序。
