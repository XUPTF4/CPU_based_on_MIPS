.section entry, "ax"
.globl _start
.type _start, @function

_start:
  move $fp, $zero
  la $sp, 0x1000
  jal _trm_init
