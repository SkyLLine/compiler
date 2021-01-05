.section  .rodata
STR0:
.string "%d\n"
.text
.global myFunc
.type myFunc, @function
myFunc:
pushl %ebp
movl %esp, %ebp
subl $28, %esp
movl 16(%ebp), %eax
mov %eax, -4(%ebp)
movl 12(%ebp), %eax
mov %eax, -8(%ebp)
movl 8(%ebp), %eax
mov %eax, -12(%ebp)
movl $2, %ebx
movl %ebx, -4(%ebp)
movl $0, %ebx
movl %ebx, -12(%ebp)
L0:
movl -12(%ebp), %eax
movl $0 , %ebx
cmp %ebx, %eax
jne L1
jmp L2
L1:
movl $0, %eax
movl %ebp, %esp
popl %ebp
ret
jmp L2
L2:
L2:
movl -8(%ebp), %eax
movl $0 , %ebx
cmp %ebx, %eax
jg L3
jmp L4
L3:
movl -8(%ebp), %eax
movl $1 , %ebx
subl %ebx, %eax
movl %eax, -24(%ebp)
movl -24(%ebp), %ebx
movl %ebx, -8(%ebp)
jmp L2
L4:
movl -4(%ebp), %eax
movl -8(%ebp), %ebx
addl %ebx, %eax
movl %eax, -28(%ebp)
movl -28(%ebp), %eax
movl %ebp, %esp
popl %ebp
ret
.text
.global main
.type main, @function
main:
pushl %ebp
movl %esp, %ebp
subl $16, %esp
movl $3, %ebx
movl %ebx, -4(%ebp)
movl $1, %eax
pushl %eax
movl $2, %eax
pushl %eax
movl $1, %eax
pushl %eax
call myFunc
addl $4, %esp
movl %eax, -12(%ebp)
movl -12(%ebp), %ebx
movl %ebx, -8(%ebp)
movl -4(%ebp), %eax
movl -8(%ebp), %ebx
addl %ebx, %eax
movl %eax, -16(%ebp)
movl -16(%ebp), %eax
pushl %eax
pushl $STR0
call printf
addl $8, %esp
movl $0, %eax
movl %ebp, %esp
popl %ebp
ret
.section .note.GNU-stack,"",@progbits
