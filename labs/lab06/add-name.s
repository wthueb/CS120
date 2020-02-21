.data
name: .asciiz "William Huebner"

.text
main:
    la $s0, name
    li $s1, 0

loop:
    lb $s2, 0($s0)
    beq $s2, $0, loop_end
    add $s1, $s1, $s2
    addi $s0, $s0, 1
    j loop

loop_end:
    move $a0, $s1
    li $v0, 1
    syscall
    
    li $v0, 10
    syscall
