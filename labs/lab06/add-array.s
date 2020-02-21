.data
data: .word 33
      .word 44
      .word 66
      .word 0

.text
main:
    la $s0, data
    li $s1, 0

loop:
    lw $s2, 0($s0)
    beq $s2, $0, loop_end

    add $s1, $s1, $s2
    addi $s0, $s0, 4
    j loop

loop_end:
    move $a0, $s1
    li $v0, 1
    syscall

    li $v0, 10
    syscall
