# CPU_based_on_MIPS

基于 MIPS 指令集的 32 位模型机设计与 FPGA 实现

## 项目运行指南

### 环境

- 系统：Linux 平台，如 Ubuntu 22.4。
- Verilator: 可以从源码编译，也可以直接通过包管理器进行安装
- Surfer (VSCode 插件)：用来查看波形图
- bear：配合 clangd 进行代码错误检查
- 需要安装的软件包有：`make` `bear` `mips-linux-gnu-gcc`(`gcc-mips-linux-gnu`)

### 工作原理

#### CPU

这是 CPU，通过 Verilog 代码实现电路逻辑。

#### test_bench

这里面有很多的测试用例，将 C 代码交叉编译成 MIPS 平台的二进制，然后通过 Makefile 脚本转化成 `XXX.hex`。然后将 `XXX.hex` 处理到 CPU 中的 `InstMem.v` 中，就可以进行测试了。至于怎么将 hex 文件中的字节导入到 InstMem 中，就看你的选择了，当然借助 AI 让他帮你搞是最好的选择。

好消息是，我通过 python 脚本已经自动化完成这件事了。你只需要在 cpu_test 中直接 `make clean && make build ALL=sub` 就能让 CPU 准备跑 sub 程序了，接着在项目目录中直接输入 `make run`，如果 CPU 实现正确的话，你就能直接看到绿色的 `HIT good trap!`。

更好的消息是，你可以直接在项目目录中直接输入 `make runall`，测试所有测试案例：

```bash
make runall
...
[2025-02-28 18:32:22] 开始编译测试用例: fib
[2025-02-28 18:32:23] 开始运行测试用例: fib
运行时间: 0.471秒
测试通过: fib (耗时 1 秒)
[2025-02-28 18:32:23] 开始编译测试用例: matrix_mul
[2025-02-28 18:32:23] 开始运行测试用例: matrix_mul
运行时间: 0.558秒
测试通过: matrix_mul (耗时 1 秒)
[2025-02-28 18:32:24] 开始编译测试用例: bubble_sort
[2025-02-28 18:32:24] 开始运行测试用例: bubble_sort
运行时间: 0.366秒
测试通过: bubble_sort (耗时 0 秒)
[2025-02-28 18:32:24] 开始编译测试用例: div
[2025-02-28 18:32:24] 开始运行测试用例: div
运行时间: 0.613秒
测试通过: div (耗时 1 秒)
[2025-02-28 18:32:25] 开始编译测试用例: add
[2025-02-28 18:32:25] 开始运行测试用例: add
运行时间: 0.481秒
测试通过: add (耗时 0 秒)
[2025-02-28 18:32:26] 开始编译测试用例: or
[2025-02-28 18:32:26] 开始运行测试用例: or
运行时间: 0.481秒
测试通过: or (耗时 0 秒)
[2025-02-28 18:32:26] 开始编译测试用例: shift
[2025-02-28 18:32:26] 开始运行测试用例: shift
运行时间: 0.483秒
测试通过: shift (耗时 1 秒)
[2025-02-28 18:32:27] 开始编译测试用例: mult
[2025-02-28 18:32:27] 开始运行测试用例: mult
运行时间: 0.498秒
测试通过: mult (耗时 0 秒)
[2025-02-28 18:32:27] 开始编译测试用例: recursion
[2025-02-28 18:32:27] 开始运行测试用例: recursion
运行时间: 0.550秒
测试通过: recursion (耗时 1 秒)
[2025-02-28 18:32:28] 开始编译测试用例: danger
[2025-02-28 18:32:28] 开始运行测试用例: danger
运行时间: 0.582秒
测试通过: danger (耗时 1 秒)
[2025-02-28 18:32:29] 开始编译测试用例: pipeline_test
[2025-02-28 18:32:29] 开始运行测试用例: pipeline_test
运行时间: 0.528秒
测试通过: pipeline_test (耗时 0 秒)
[2025-02-28 18:32:29] 开始编译测试用例: return
[2025-02-28 18:32:29] 开始运行测试用例: return
运行时间: 0.487秒
测试通过: return (耗时 1 秒)
[2025-02-28 18:32:30] 开始编译测试用例: fact
[2025-02-28 18:32:30] 开始运行测试用例: fact
运行时间: 0.570秒
测试通过: fact (耗时 1 秒)
[2025-02-28 18:32:31] 开始编译测试用例: branch
[2025-02-28 18:32:31] 开始运行测试用例: branch
运行时间: 0.544秒
测试通过: branch (耗时 0 秒)
[2025-02-28 18:32:31] 开始编译测试用例: sub
[2025-02-28 18:32:31] 开始运行测试用例: sub
运行时间: 0.573秒
测试通过: sub (耗时 1 秒)

[2025-02-28 18:32:32] 测试结果汇总:
├── 总测试用例: 15
├── 通过用例: 15
└── 失败用例: 0
[2025-02-28 18:32:32] 执行清理操作...
```

目前能通过所有测试，这意味着，我们的 CPU 设计正确地实现了所有的指令。



#### Verilator

> - [Verilator 使用指南 - USTC CECS 2023](https://soc.ustc.edu.cn/CECS/lab2/verilator/)

这是利用 Verilator 将 CPU 中的所有 Verilog 代码仿真成 C++ 类库，然后在 `main.cpp` 中就可以利用这些库进行操控、监视、CPU 的行为等等，从而进行仿真，这也是 Verilator 的工作原理。它比 Vivado 等工具快几乎 100 倍，效率非常高。

### 启动一个例子

在 Makefile 中所在的目录中运行 `make run` 即可。

之后就能看到多了一个 `wave.vcd` 文件。通过 surfer 插件打开，就能看到波形图了。目前为止，CPU 已经能识别所有已经实现的指令了。你可以自由探索 surfer 的各种用法。


## 课设要求

> FPGA模型机课程设计总共进行两周时间，主要围绕设计一个完整的模型计算机展开，包括设计模型机的基本架构、数据通路、运算器、指令存储器、数据存储器、通用寄存器、输入/输出端口等硬件部件。指令系统采用MIPS 32位处理器指令子集实现。要求实现基本的Load-Store-ALU类型20条指令，在此基础上可以扩展需要实现的指令，包括乘除运算、条件转移、异常与中断、原子操作等指令，构成完整模型机。在此基础上可以按照指令周期的不同阶段，设计指令流水线，并完成流水处理器设计。
>
> 所有设计的指令需通过Modelsim仿真，验证模型机设计功能是否符合要求。仿真通过后，用机器指令编写程序，实现简单的应用功能。有FPGA开发板的同学，通过Vivado综合工具，下载到FPGA开发板上。

### 一、时间安排

“FPGA模型机课程设计”的时间安排可视实际情况而定，主要内容和安排大致如下：

#### 第一周周一

FPGA模型计算机整体方案设计。由指导教师给学生讲解本课程设计的题目和要求。学生自行分组，每组成员不得超过4人，由于设备数量关系，建议每组成员3~4人。学生小组认真研究“FPGA模型机设计”课程网站上题目要求和教学资源，查阅有关资料，确定所设计MIPS指令集范畴，完成模型机整体方案设计，搭建设计所需的软硬件环境，注意分工合作：模型机代码编写测试和FPGA开发板下载使用，逐步推进设计开发实现工作。

#### 第一周周二

模型计算机各功能电路设计。学生根据总体方案，自行运用VerilogHDL语言进行运算器设计、存储器设计、输入\输出端口设计、总线接口设计等。即要求完成20条MIPS整数指令，基本能够在Modelsim上进行功能仿真，运算、转移和访存功能需测试正确，能够模型机在FPGA开发板上下载运行简单测试。

#### 第一周周三

模型机指令系统设计。学生根据搭建的模型机数据通路图，选择扩展的指令格式和指令功能。扩展指令系统的选择可以参照MIPS 32位处理器指令集，选择MIPS12条整数指令。要求能够画出指令格式和指令功能，能够画出处理器内部实现结构图，包括时序信号和控制信号，可以采用单周期方案，能够在FPGA开发板上运行较为综合程序测试所有指令的功能。

#### 第一周周四

选择MIPS与中断异常相关的6条指令，继续将完整模型机的指令进行实现。学生将在Modelsim里仿真验证通过的模型机程序，并编写具体测试指令，能够通过简单的中断异常机器指令对中断异常等功能进行测试，能够Modelsim/Vivoda中仿真上运行中断异常的测试，注意要逐条指令的细致对比分析，并验证功能的正确性。由于中断异常实现与一般程序有较大区别，需仿真验证正确且真正理解掌握其实现方式后，再进行下载FPGA开发板。

#### 第一周周五

模型机整体的联调。完成模型机指令系统实现。学生根据设计好的指令系统实现方案，在Modelsim上进行功能仿真。要求将所有设计的机器指令都仿真正确，包括：数据流通、时序节拍、寄存器的读写，输入输出端口的访问、接口控制信号等。所有指令功能测试正确。指导教师对学生进行中期检查，主要观察指令运行结果，包括数据寄存器打入是否正确，转移指令是否正确设置PC，中断异常等指令功能的实现，即能够编写具体测试指令，能够通过简单的中断异常机器指令对中断异常等功能进行测试，能够在FPGA开发板上运行中断异常的测试并验证功能的正确性。注意若本阶段任务达成，需录制视频让指导教师验收，并将调试好的版本freeze冻结，因为下周开始将要进行流水线设计，改动较大。

#### 第二周周一

设计指令流水线，按照指令周期不同阶段进行划分，实现指令基本流水处理功能。然后在基本流水线设计基础上加入数据相关、资源相关处理和控制相关的解决，编写机器指令程序，对指令逐一进行测试。注意每添加一个相关冲突解决都需要进行相应的测试，测试务必细致，是考验设计开发者的基本功，务必重视。在Modelsim/Vivado中仿真检测结果时需注意每条指令功能和时序的对应关系。在FPGA开发板上运行相应的测试程序，验证指令流水线的正确性。

#### 第二周周二

在数据相关、资源相关处理和控制相关的解决基础上，将中断异常引入流水线，实现精确的中断异常控制。注意中断异常的实现方式，和对流水线的影响。中断异常发时后，是在最后一个阶段收集，并将流水线中所有指令提交申请（写入寄存器或存储器）作废。需正确设计相应的冲突解决方案。然后编写异常中断测试程序，在Modelsim/Vivado里仿真测试，注意对时序和功能进行细致比对分析，确保时序和功能仿真正确。进而编写中断异常的测试程序，对模型机的功能进行实现和仿真验证。

#### 第二周周三

编写较为复杂的系统测试程序，将完整模型机的指令进行实现和仿真验证。在Modelsim/Vivado里仿真测试，注意对时序和功能进行细致比对分析，确保时序和功能仿真正确。进而模型机在FPGA上的功能测试。能够用机器指令编写较复杂功能的程序，测试模型机的各项功能。要求：用机器指令编写的程序应在Modelsim上仿真通过，明确实验结果。该测试程序由学生自行设计，需将所设计结果和指令运行结果逐一验证以确保正确。能够通过Vivado将模型机下载FPGA开发板进行验证。该测试程序由学生自行设计，测试指令种类和条数越多，测试功能越多，性能提升明显者为佳。

#### 第二周周四

教师检查学生完成情况，每个学生组应诚实地将自己的作品向教师进行展示。包括功能演示、设计方案讲解、设计步骤讲解、实验结果正确性分析等。教师需根据每个设计组以及每个学生承担的具体工作合理评分。对流水处理器进行改进和完善，注意数据相关和控制相关冲突的解决。编写机器指令程序，对各条指令功能逐一进行检测。教师需根据每个设计组以及每个学生承担的具体工作合理评分。

#### 第二周周五

学生小组在通过验收后，录制模型机演示视频（一般<3min，优秀组可适当延长），优秀设计者需制作答辩讲解ppt。模型机演示视频应包括：所设计的指令集、模型机架构、程序运行演示和对运行结果的说明；曾经出现的问题及解决办法；每位成员在设计开发团队中起到的作用。所录视频为mp4格式，要求屏幕视角大，图像清晰，声音洪亮，演示运行过程清楚明了，运行结果是否正确有解释说明。视频最好有字幕提示。
学生小组整理好FPGA开发板和实验工具，归还硬件实验室。整理好代码和文档，包括模型机整体设计、各模块设计、测试代码说明等。学生撰写FPGA模型机课程设计报告，注意需在其中说明个人的分工和体会。

### 二、关键时间节点和要求

1. 第一周周一：完成分组并向指导教师报告。
2. 第一周周五：完成模型机设计所有仿真测试，包括基本20条指令和扩展12条指令，以及6条中断异常指令，包括在FPGA开发板上运行测试。
3. 第二周周三：基本完成所有设计实现工作，包括流水设计的处理器和FPGA开发板下载运行和验证。
4. 第二周周四：学生小组完成项目验收，现场操作演示，回答问题。
5. 第二周周五：课程设计收尾及优秀作品展示答辩。

### 三、实验要求

#### 基本模型机：（20%）

实现基本20条MIPS整数指令，模型机在Modelsim上时序和功能仿真正确。编写机器指令程序，实现逐条指令功能测试和复杂功能测试。应用程序由学生自行编写，题材不限。以指令实现越多，功能测试越多者为佳。

#### 完整模型机：（30%）

实现全部扩展指令，即包括12条MIPS整数指令和中断相关指令。学生编写机器指令程序，实现逐条指令功能测试和复杂功能测试。该应用程序由学生自行编写，题材不限。以指令实现越多，功能测试越多者为佳。

#### 流水处理器（50%）

实现流水处理器，包括之前（表1~表3）所有指令功能，能够合理划分流水阶段，解决数据相关和控制相关冲突,以及实现精确中断异常。通过基本指令测试和复杂功能测试，所有程序功能测试正确，并且效率提升显著者为佳。

### 四、任务要求

1. 在Modelsim/Vivado仿真环境下实现模型机系统功能仿真测试。
2. 在FPGA开发板上实现模型机系统功能验证实现。
3. 验收：视频系统演示、回答教师问题。
4. 优秀设计者制作ppt，讲解设计思想，展示设计成果（视频演示），参加答辩
5. 每名学生需自行完成课程设计报告。
6. 每个学生小组需提交组内互评表给指导教师。

## 附录

### Table 1: MIPS 20 Integer Instructions

| 指令 | 31:26  | 25:21   | 20:16 | 15:11     | 10:6  | 5:0    | 意义       |
| ---- | ------ | ------- | ----- | --------- | ----- | ------ | ---------- |
| add  | 000000 | rs      | rt    | rd        | 00000 | 100000 | 寄存器加   |
| sub  | 000000 | rs      | rt    | rd        | 00000 | 100010 | 寄存器减   |
| and  | 000000 | rs      | rt    | rd        | 00000 | 100100 | 寄存器与   |
| or   | 000000 | rs      | rt    | rd        | 00000 | 100101 | 寄存器或   |
| xor  | 000000 | rs      | rt    | rd        | 00000 | 100110 | 寄存器异或 |
| sll  | 000000 | 00000   | rt    | rd        | 00000 | 100000 | 左移       |
| srl  | 000000 | 00000   | rt    | rd        | sa    | 000010 | 逻辑右移   |
| sra  | 000000 | 00000   | rt    | rd        | sa    | 000011 | 算术右移   |
| jr   | 000000 | rs      | 00000 | 00000     | 00001 | 001000 | 寄存器跳转 |
| addi | 001000 | rs      | rt    | immediate |       |        | 立即数加   |
| andi | 001100 | rs      | rt    | immediate |       |        | 立即数与   |
| ori  | 001101 | rs      | rt    | immediate |       |        | 立即数或   |
| xori | 001110 | rs      | rt    | immediate |       |        | 立即数异或 |
| lw   | 100011 | rs      | rt    | offset    |       |        | 取整数字据 |
| sw   | 101011 | rs      | rt    | offset    |       |        | 存整数字据 |
| beq  | 000100 | rs      | rt    | offset    |       |        | 相等转移   |
| bne  | 000101 | rs      | rt    | offset    |       |        | 不等转移   |
| lui  | 001111 | 00000   | rt    | immediate |       |        | 设置高位   |
| j    | 000010 | address |       |           |       |        | 跳转       |
| jal  | 000011 | address |       |           |       |        | 调用       |

### Table 2: MIPS 12 Integer Instructions

| 指令            | 31:26  | 25:21 | 20:16 | 15:11  | 10:6  | 5:0    | 功能                          |
| --------------- | ------ | ----- | ----- | ------ | ----- | ------ | ----------------------------- |
| slt rd, rs, rt  | 000000 | rs    | rt    | Rd     | 00000 | 101010 | rd <- (rs < rt), signed       |
| bgtz rs, offset | 000111 | rs    | 00000 | offset |       |        | if rs > 0, then branch        |
| bltz rs, offset | 000001 | rs    | 00000 | offset |       |        | if rs < 0, then branch        |
| Jalr rd, rs     | 000000 | rs    | 00000 | Rd     | 00000 | 001001 | rd <- npc, PC <- rs           |
| mult rs, rt     | 000000 | rs    | rt    | 00000  | 00000 | 011000 | {hi, lo} <- rs * rt, signed   |
| multu rs, rt    | 000000 | rs    | rt    | 00000  | 00000 | 011001 | {hi, lo} <- rs * rt, unsigned |
| div rs, rt      | 000000 | rs    | rt    | 00000  | 00000 | 011010 | {hi, lo} <- rs / rt, signed   |
| divu rs, rt     | 000000 | rs    | rt    | 00000  | 00000 | 011011 | {hi, lo} <- rs / rt, unsigned |
| mfhi rd         | 000000 | 00000 | 00000 | Rd     | 00000 | 010000 | rd <- hi                      |
| mflo rd         | 000000 | 00000 | 00000 | Rd     | 00000 | 010010 | rd <- lo                      |
| mthi rs         | 000000 | rs    | 00000 | 00000  |       | 010001 | hi <- rs                      |
| mtlo rs         | 000000 | rs    | 00000 | 00000  |       | 010011 | lo <- rs                      |

### Table 3: MIPS 6 Exception Instructions

| 指令              | 31:26  | 25:21 | 20:16 | 15:11  | 10:6  | 5:0    | 功能                            |
| ----------------- | ------ | ----- | ----- | ------ | ----- | ------ | ------------------------------- |
| ll rt, offset(rs) | 110000 | rs    | rt    | offset |       |        | load; LLbit=1                   |
| sc rt, offset(rs) | 111000 | rs    | rt    | offset |       |        | if(LLbit) store; rt=1 else rt=0 |
| mfc0 rt, rd       | 010000 | 00000 | rt    | rd     | 00000 | 000000 | rt <- cp0[rd]                   |
| mtc0 rt, rd       | 010000 | 00100 | rt    | rd     | 00000 | 000000 | cp0[rd] <- rt                   |
| eret              | 010000 | 10000 | 00000 | 00000  | 00000 | 011000 | PC <- epc, LLbit <- 0           |
| syscall           | 000000 | 00000 | 00000 | 0      |       | 001100 | SysInt, LLbit <- 0              |

## TODO

- [x] 项目文档
- [x] 约束文件
- [x] 实现所有要求的指令
- [x] 通过所有测试
- [ ] 流水线 CPU
- [ ] 实现的功能：分支预测 + 缓存
- [ ] 数码管显示 + LCD。数码管显示 PC，LCD + 按钮用于人机交互，类似于终端
- [ ] 简单的操作系统：不实现任何文件、内存管理，只借助于最简单的 UART 来打印一些字符

## 问题

以后要考虑做流水线，又因为利用 Vivado 提供的 ROM IP 是多周期访存的，如果利用这些 IP 做流水线，就极大地上升了难度。因此这里不打算使用 IP 核，所有的内存均由 Verilog 的 reg 类型模拟。

ROM 使用 4K，这意味着只能装一些小程序。最核心的也是唯一的系统调用 printf 只能自己实现然后链接到目标程序上。
RAM 使用 2K，RAM 基本用不到，足够了。

测试 CPU:

- 要有 MIPS 交叉编译工具链，通过提取 `.txt` 段的指令，然后加载到 ROM 中，然后观察时序逻辑图；
- 简单搭建 Verilator 仿真环境；
- 时序图生成工具；
- 将二进制代码载入 ROM 观察 波形图：推荐使用 surfer VSCode 插件浏览波形图，速度快；
- 波形图格式已经换成了 fst，体积非常小；

## 性能对比

通过对比实现流水线前后的 MIPS 对比来量化性能变动。

以测试案例 `matrix_mul.c` 为基准，目前它的 MIPS 为：

```bash
MIPS: 0.825649 MIPS
```






