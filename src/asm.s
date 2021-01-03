.section  .rodata
STR0:
.string "%d%d"
STR1:
.string "my number:%d"
.text
.global main
.type main, @function
main:
pushl %ebp
movl %esp, %ebp
subl $72, %esp
movl $-8, %eax
movl $5, %ebx
imull $4, %ebx, %ebx
addl %ebx, %eax
movl %eax, -52(%ebp)
movl -52(%ebp), %eax
addl %ebp, %eax
pushl %eax
movl $-8, %eax
addl %ebp, %eax
pushl %eax
movl $-4, %eax
addl %ebp, %eax
pushl %eax
pushl $STR0
call scanf
addl $16, %esp
movl -4(%ebp), %eax
movl -8(%ebp), %ebx
addl %ebx, %eax
movl %eax, -68(%ebp)
movl $-8, %eax
movl $5, %ebx
imull $4, %ebx, %ebx
addl %ebx, %eax
movl %eax, -72(%ebp)
movl -68(%ebp), %eax
movl -72(%ebp), %ebx
addl %ebp, %ebx
movl 0(%eax), %ebx
addl %ebx, %eax
movl %eax, -64(%ebp)
movl -64(%ebp), %eax
pushl %eax
pushl $STR1
call printf
addl $8, %esp
movl $0, %eax
movl %ebp, %esp
popl %ebp
ret
.section .note.GNU-stack,"",@progbits
