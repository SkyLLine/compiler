repeat error!
.section  .rodata
STR0:
.string "%d"
STR1:
.string "%d\n"
STR2:
.string "End Loop\n"
.text
.global main
.type main, @function
main:
pushl %ebp
movl %esp, %ebp
subl $16968, %esp
movl $-4, %eax
addl %ebp, %eax
pushl %eax
pushl $STR0
call scanf
addl $8, %esp
movl $1, %ebx
movl %ebx, -16788(%ebp)
L0:
movl -16788(%ebp), %eax
movl $10 , %ebx
cmp %ebx, %eax
jl L1
jmp L2
L1:
movl $1, %ebx
movl %ebx, -16792(%ebp)
L3:
movl -16792(%ebp), %eax
movl $8 , %ebx
cmp %ebx, %eax
jle L4
jmp L5
L4:
movl $-8, %eax
movl -16788(%ebp), %ebx
imull $-408, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16832(%ebp)
movl -16832(%ebp), %eax
movl -16792(%ebp), %ebx
imull $-12, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16836(%ebp)
movl -16836(%ebp), %eax
movl $1, %ebx
imull $-4, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16840(%ebp)
movl -16788(%ebp), %eax
movl -16792(%ebp), %ebx
subl %ebx, %eax
movl %eax, -16828(%ebp)
movl -16828(%ebp), %ebx
movl -16840(%ebp), %eax
addl %ebp, %eax
movl %ebx, 0(%eax)
movl -16792(%ebp), %eax
movl $1 , %ebx
addl %ebx, %eax
movl %eax, -16824(%ebp)
movl -16824(%ebp), %ebx
movl %ebx, -16792(%ebp)
jmp L3
L5:
movl -16788(%ebp), %eax
movl $1 , %ebx
addl %ebx, %eax
movl %eax, -16816(%ebp)
movl -16816(%ebp), %ebx
movl %ebx, -16788(%ebp)
jmp L0
L2:
L2:
movl -4(%ebp), %eax
movl $0 , %ebx
cmp %ebx, %eax
jg L6
jmp L7
L6:
movl -4(%ebp), %eax
movl $1 , %ebx
subl %ebx, %eax
movl %eax, -16848(%ebp)
movl -16848(%ebp), %ebx
movl %ebx, -4(%ebp)
movl $1, %ebx
movl %ebx, -16796(%ebp)
L8:
movl -16796(%ebp), %eax
movl $10 , %ebx
cmp %ebx, %eax
jl L9
jmp L10
L9:
movl $1, %ebx
movl %ebx, -16800(%ebp)
L11:
movl -16800(%ebp), %eax
movl $8 , %ebx
cmp %ebx, %eax
jle L12
jmp L13
L12:
movl $-8, %eax
movl -16796(%ebp), %ebx
imull $-408, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16884(%ebp)
movl -16884(%ebp), %eax
movl -16800(%ebp), %ebx
imull $-12, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16888(%ebp)
movl -16888(%ebp), %eax
movl $1, %ebx
imull $-4, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16892(%ebp)
movl $-8, %eax
movl -16796(%ebp), %ebx
imull $-408, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16868(%ebp)
movl -16868(%ebp), %eax
movl -16800(%ebp), %ebx
imull $-12, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16872(%ebp)
movl -16872(%ebp), %eax
movl $1, %ebx
imull $-4, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16876(%ebp)
movl -16876(%ebp), %eax
addl %ebp, %eax
movl 0(%eax), %eax
movl $1 , %ebx
addl %ebx, %eax
movl %eax, -16880(%ebp)
movl -16880(%ebp), %ebx
movl -16892(%ebp), %eax
addl %ebp, %eax
movl %ebx, 0(%eax)
movl -16800(%ebp), %eax
movl $1 , %ebx
addl %ebx, %eax
movl %eax, -16864(%ebp)
movl -16864(%ebp), %ebx
movl %ebx, -16800(%ebp)
jmp L11
L13:
movl -16796(%ebp), %eax
movl $1 , %ebx
addl %ebx, %eax
movl %eax, -16856(%ebp)
movl -16856(%ebp), %ebx
movl %ebx, -16796(%ebp)
jmp L8
L10:
movl $0, %ebx
movl %ebx, -16804(%ebp)
movl $1, %ebx
movl %ebx, -16808(%ebp)
L14:
movl -16808(%ebp), %eax
movl $8 , %ebx
cmp %ebx, %eax
jl L15
jmp L16
L15:
movl $1, %ebx
movl %ebx, -16800(%ebp)
L17:
movl -16800(%ebp), %eax
movl $8 , %ebx
cmp %ebx, %eax
jle L18
jmp L19
L18:
movl $-9392, %eax
movl -16808(%ebp), %ebx
imull $-172, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16924(%ebp)
movl -16924(%ebp), %eax
movl -16800(%ebp), %ebx
imull $-4, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16928(%ebp)
movl $-8, %eax
movl -16800(%ebp), %ebx
imull $-408, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16912(%ebp)
movl -16912(%ebp), %eax
movl -16808(%ebp), %ebx
imull $-12, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16916(%ebp)
movl -16916(%ebp), %eax
movl $1, %ebx
imull $-4, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16920(%ebp)
movl -16920(%ebp), %ebx
addl %ebp, %ebx
movl 0(%ebx), %ebx
movl -16928(%ebp), %eax
addl %ebp, %eax
movl %ebx, 0(%eax)
movl $-9392, %eax
movl -16808(%ebp), %ebx
imull $-172, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16944(%ebp)
movl -16944(%ebp), %eax
movl -16800(%ebp), %ebx
imull $-4, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16948(%ebp)
movl $-9392, %eax
movl -16808(%ebp), %ebx
imull $-172, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16932(%ebp)
movl -16932(%ebp), %eax
movl -16800(%ebp), %ebx
imull $-4, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16936(%ebp)
movl -16936(%ebp), %eax
addl %ebp, %eax
movl 0(%eax), %eax
movl -16804(%ebp), %ebx
addl %ebx, %eax
movl %eax, -16940(%ebp)
movl -16940(%ebp), %ebx
movl -16948(%ebp), %eax
addl %ebp, %eax
movl %ebx, 0(%eax)
movl $-9392, %eax
movl -16808(%ebp), %ebx
imull $-172, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16956(%ebp)
movl -16956(%ebp), %eax
movl -16800(%ebp), %ebx
imull $-4, %ebx, %ebx
addl %ebx, %eax
movl %eax, -16960(%ebp)
movl -16804(%ebp), %eax
movl $10 , %ebx
cdq
idivl %ebx
movl %eax, -16952(%ebp)
movl -16960(%ebp), %eax
addl %ebp, %eax
movl 0(%eax), %eax
movl -16952(%ebp), %ebx
subl %ebx, %eax
movl %eax, -16964(%ebp)
movl -16804(%ebp), %eax
movl -16964(%ebp), %ebx
subl %ebx, %eax
movl %eax, -16968(%ebp)
movl -16968(%ebp), %ebx
movl %ebx, -16804(%ebp)
movl -16800(%ebp), %eax
movl $1 , %ebx
addl %ebx, %eax
movl %eax, -16908(%ebp)
movl -16908(%ebp), %ebx
movl %ebx, -16800(%ebp)
jmp L17
L19:
movl -16808(%ebp), %eax
movl $1 , %ebx
addl %ebx, %eax
movl %eax, -16900(%ebp)
movl -16900(%ebp), %ebx
movl %ebx, -16808(%ebp)
jmp L14
L16:
movl -16804(%ebp), %eax
pushl %eax
pushl $STR1
call printf
addl $8, %esp
jmp L2
L7:
pushl $STR2
call printf
addl $4, %esp
movl $0, %eax
movl %ebp, %esp
popl %ebp
ret
.section .note.GNU-stack,"",@progbits
