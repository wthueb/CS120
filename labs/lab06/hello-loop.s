.data
hello: .asciiz "hello world\n"
count: .word 10

.text
main:
	lw $s0, count

loop:
	beq $s0, $0, loop_end
	addi $s0, $s0, -1
	
	la $a0, hello
	li $v0, 4
	syscall
	j loop	

loop_end:
	li $v0, 10
	syscall
