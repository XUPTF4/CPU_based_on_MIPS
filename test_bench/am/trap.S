
#define MAP(c, f) c(f)

#define REGS(f) \
      f( 1) f( 2) f( 3) f( 4) f( 5) f( 6) f( 7) f( 8) f( 9) \
f(10) f(11) f(12) f(13) f(14) f(15) f(16) f(17) f(18) f(19) \
f(20) f(21) f(22) f(23) f(24) f(25)             f(28)       \
f(30) f(31)

#define PUSH(n) sw $n, (n * 4)($sp);
#define POP(n)  lw $n, (n * 4)($v0);

#define CONTEXT_SIZE ((33) * 4)
#define OFFSET_SP     (29 * 4)



.set noat
.globl __am_asm_trap
__am_asm_trap:
  move $k1, $sp
  addiu $sp, $sp, -CONTEXT_SIZE

  MAP(REGS, PUSH)

  sw $k1, OFFSET_SP($sp)

  move $a0, $sp

  jal __am_irq_handle

  # 异常返回

  lw $a0, 16($v0)
  lw $t0, 128($v0) # 载入返回地址
  nop
  nop
  nop
  nop
  nop
  mtc0 $t0, $0      # 将返回地址载入 epc
  addiu $sp, $sp, CONTEXT_SIZE
  eret
