ENTRY(_start)

MEMORY {
  rom(rx) : ORIGIN = 0x00000000, LENGTH = 4K  # ROM 起始地址和大小
  ram(rw) : ORIGIN = 0x00000000, LENGTH = 4K  # RAM 起始地址和大小
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
    *(.data*)
    *(.sdata*)
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

  # 堆和栈分配
  _heap_start = 0x00000100;  # 堆的起始地址
  _heap_end = ORIGIN(ram) + LENGTH(ram);  # 堆的结束地址
  _stack_pointer = _heap_end;  # 栈指针设置为堆的结束地址
}
