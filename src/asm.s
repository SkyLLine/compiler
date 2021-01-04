.section  .rodata
STR0:
.string "%d"
STR1:
.string "%d"
STR2:
.string "test:%d\n"
.text
.global main
.type main, @function
main:
pushl %ebp
movl %esp, %ebp
subl $16, %esp
movl $-4, %eax
addl %ebp, %eax
pushl %eax
pushl $STR0
call scanf
addl $8, %esp
movl $-8, %eax
addl %ebp, %eax
pushl %eax
pushl $STR0
call scanf
addl $8, %esp
movl -4(%ebp), %eax
movl -8(%ebp), %ebx
imull %ebx, %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %ebx
movl %ebx, -12(%ebp)
movl -12(%ebp), %eax
pushl %eax
pushl $STR2
call printf
addl $8, %esp
movl $0, %eax
movl %ebp, %esp
popl %ebp
ret
.section .note.GNU-stack,"",@progbits
