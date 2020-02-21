.text

f2:
    addi $sp, $sp, -4
    sw $ra, ($sp)

    lw $t0, 4($sp)
    
    add $v0, $t0, $t0

    lw $ra, ($sp)
    addi $sp, $sp, 4

    jr $ra

    
f1:
    addi $sp, $sp, -4
    sw $ra, ($sp)

    lw $t0, 4($sp)
    lw $t1, 8($sp)
    
    add $t0, $t0, $t1

    addi $sp, $sp, -4
    sw $t0, ($sp)
    
    jal f2

    addi $sp, $sp, 4
    
    lw $ra, ($sp)
    addi $sp, $sp, 4

    jr $ra

    
main:
    addi $sp, $sp, -4
    sw $ra, ($sp)

    li $t0, 4
    li $t1, 3
    
    addi $sp, $sp, -8
    sw $t1, ($sp) # right to left, so 4 ($t0) goes before 3 ($t1) on the stack
    sw $t0, 4($sp)

    jal f1

    addi $sp, $sp, 8
    
    lw $ra, ($sp)
    addi $sp, $sp, 4

    jr $ra
