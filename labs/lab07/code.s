.data
arr: .word 1
      .word 2
      .word 3
      .word 4
      .word 5
      .word 6

.text
main:
    la $s0, arr
    li $s1, 0
    li $s2, 6
    li $s3, 3

loop:
    bge $s1, $s2, end_loop
    lw $s4, ($s0)
    bge $s4, $s3, else
    addi $s4, 5
    b end_else
else:
    addi $s4, 7
end_else:
    sw $s4, ($s0)
    addi $s1, 1
    addi $s0, 4
    b loop
    
end_loop:
    li $v0, 10
    syscall
