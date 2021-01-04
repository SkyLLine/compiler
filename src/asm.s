.section  .rodata
STR0:
.string "%d %d"
STR1:
.string "%d\n"
STR2:
.string "%d\n"
.text
.global main
.type main, @function
main:
pushl %ebp
movl %esp, %ebp
subl $1016, %esp
movl $10, %ebx
movl %ebx, -4(%ebp)
movl $12, %ebx
movl %ebx, -8(%ebp)
movl -4(%ebp), %ebx
movl %ebx, -8(%ebp)
movl $0, %ebx
movl %ebx, -908(%ebp)
L0:
movl -908(%ebp), %eax
movl $10 , %ebx
cmp %ebx, %eax
jl L1
jmp L2
L1:
movl $0, %ebx
movl %ebx, -912(%ebp)
L3:
movl -912(%ebp), %eax
movl $10 , %ebx
cmp %ebx, %eax
jl L4
jmp L5
L4:
movl $-508, %eax
movl -908(%ebp), %ebx
imull $-40, %ebx, %ebx
addl %ebx, %eax
movl %eax, -932(%ebp)
movl -932(%ebp), %eax
movl -912(%ebp), %ebx
imull $-4, %ebx, %ebx
addl %ebx, %eax
movl %eax, -936(%ebp)
movl $0, %ebx
movl -936(%ebp), %eax
addl %ebp, %eax
movl %ebx, 0(%eax)
movl -912(%ebp), %eax
movl $1 , %ebx
addl %ebx, %eax
movl %eax, -928(%ebp)
movl -928(%ebp), %ebx
movl %ebx, -912(%ebp)
jmp L3
L5:
movl -908(%ebp), %eax
movl $1 , %ebx
addl %ebx, %eax
movl %eax, -920(%ebp)
movl -920(%ebp), %ebx
movl %ebx, -908(%ebp)
jmp L0
L2:
movl $-12, %eax
addl %ebp, %eax
pushl %eax
movl $-4, %eax
addl %ebp, %eax
pushl %eax
pushl $STR0
call scanf
addl $12, %esp
movl $1, %ebx
movl %ebx, -908(%ebp)
L6:
movl -908(%ebp), %eax
movl -4(%ebp), %ebx
cmp %ebx, %eax
jle L7
jmp L8
L7:
movl $1, %ebx
movl %ebx, -912(%ebp)
L9:
movl -912(%ebp), %eax
movl -12(%ebp), %ebx
cmp %ebx, %eax
jle L10
jmp L11
L10:
movl $-508, %eax
movl -908(%ebp), %ebx
imull $-40, %ebx, %ebx
addl %ebx, %eax
movl %eax, -980(%ebp)
movl -980(%ebp), %eax
movl -912(%ebp), %ebx
imull $-4, %ebx, %ebx
addl %ebx, %eax
movl %eax, -984(%ebp)
movl -4(%ebp), %eax
movl -12(%ebp), %ebx
subl %ebx, %eax
movl %eax, -972(%ebp)
movl -908(%ebp), %eax
movl $1 , %ebx
subl %ebx, %eax
movl %eax, -956(%ebp)
movl $-508, %eax
movl -956(%ebp), %ebx
imull $-40, %ebx, %ebx
addl %ebx, %eax
movl %eax, -960(%ebp)
movl -912(%ebp), %eax
movl $1 , %ebx
subl %ebx, %eax
movl %eax, -964(%ebp)
movl -960(%ebp), %eax
movl -964(%ebp), %ebx
imull $-4, %ebx, %ebx
addl %ebx, %eax
movl %eax, -968(%ebp)
movl -972(%ebp), %eax
movl -968(%ebp), %ebx
addl %ebp, %ebx
movl 0(%ebx), %ebx
addl %ebx, %eax
movl %eax, -976(%ebp)
movl -976(%ebp), %ebx
movl -984(%ebp), %eax
addl %ebp, %eax
movl %ebx, 0(%eax)
movl -912(%ebp), %eax
movl $1 , %ebx
addl %ebx, %eax
movl %eax, -952(%ebp)
movl -952(%ebp), %ebx
movl %ebx, -912(%ebp)
jmp L9
L11:
movl -908(%ebp), %eax
movl $1 , %ebx
addl %ebx, %eax
movl %eax, -944(%ebp)
movl -944(%ebp), %ebx
movl %ebx, -908(%ebp)
jmp L6
L8:
movl -4(%ebp), %eax
pushl %eax
pushl $STR1
call printf
addl $8, %esp
movl $1, %ebx
movl %ebx, -908(%ebp)
L12:
movl -908(%ebp), %eax
movl -4(%ebp), %ebx
cmp %ebx, %eax
jle L13
jmp L14
L13:
movl $1, %ebx
movl %ebx, -912(%ebp)
L15:
movl -912(%ebp), %eax
movl -12(%ebp), %ebx
cmp %ebx, %eax
jle L16
jmp L17
L16:
movl $-508, %eax
movl -908(%ebp), %ebx
imull $-40, %ebx, %ebx
addl %ebx, %eax
movl %eax, -1004(%ebp)
movl -1004(%ebp), %eax
movl -912(%ebp), %ebx
imull $-4, %ebx, %ebx
addl %ebx, %eax
movl %eax, -1008(%ebp)
movl -1008(%ebp), %eax
addl %ebp, %eax
movl 0(%eax), %eax
movl $23 , %ebx
imull %ebx, %eax
movl %eax, -1012(%ebp)
movl -8(%ebp), %eax
movl -1012(%ebp), %ebx
addl %ebx, %eax
movl %eax, -1016(%ebp)
movl -1016(%ebp), %ebx
movl %ebx, -8(%ebp)
movl -912(%ebp), %eax
movl $1 , %ebx
addl %ebx, %eax
movl %eax, -1000(%ebp)
movl -1000(%ebp), %ebx
movl %ebx, -912(%ebp)
jmp L15
L17:
movl -908(%ebp), %eax
movl $1 , %ebx
addl %ebx, %eax
movl %eax, -992(%ebp)
movl -992(%ebp), %ebx
movl %ebx, -908(%ebp)
jmp L12
L14:
movl -8(%ebp), %eax
pushl %eax
pushl $STR1
call printf
addl $8, %esp
movl $0, %eax
movl %ebp, %esp
popl %ebp
ret
.section .note.GNU-stack,"",@progbits