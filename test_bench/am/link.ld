ENTRY(_start)

MEMORY {
  rom(rx) : ORIGIN = 0x00000000, LENGTH = 4K  # ROM 起始地址
  ram(rw) : ORIGIN = 0x00000000, LENGTH = 4K  # RAM 起始地址设为高位
}

SECTIONS {
    . = 0x00000000; /* 起始地址为 0 */
  .text : ALIGN(4) {
    *(entry)
    *(.text*)
  } > rom

  .rodata : ALIGN(4) {
    *(.rodata*)
    *(.srodata*)
  } > rom

  .data : ALIGN(4) {
    *(.data .data.*)
    *(.sdata .sdata.*)
  } > ram AT> rom  # 数据段从 rom 加载到 ram

  _sdata = ADDR(.data);
  _edata = ADDR(.data) + SIZEOF(.data);
  _sidata = LOADADDR(.data);

  .bss : ALIGN(4) {
    *(.bss*)
    *(.sbss*)
    *(.scommon*)
  } > ram  # 将 .bss 段分配到 ram 中

  _sbss = ADDR(.bss);
  _ebss = ADDR(.bss) + SIZEOF(.bss);

  _k_stack_start = 0x00000500; # 内核栈的起始地址
  _k_stack_end = 0x00000800; # 内核栈的起始地址
  _stack_pointer = 0x1000;  # 栈起始地址
}
