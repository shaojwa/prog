.section .data
.section .text
.global _start
_start:
mov $2, %eax
mov $1102, %ebx
int $0x80
