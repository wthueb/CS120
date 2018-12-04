	# Solution for lab 10.  Make sure you made a good
	# effort on your own, before looking through this
	# code.  If you don't understand how this works,
	# you'll have a tough time on the final
.text
	# Save RA
f2:	addi $sp, $sp, -4
	sw $ra, 0($sp)

	# Get variable X from the stack, add it
	# to itself, and put the result in $v0 to
	# return it
	lw $t0, 4($sp)
	add $v0, $t0, $t0

	# Restore register RA.
	# It didn't get changed, but functions typically
	# do the save/restore work
	lw $ra, 0($sp)
	addi $sp, $sp, 4

	# Back to whomever called this function
	jr $ra
	
	
	# Save RA
f1:	addi $sp, $sp, -4
	sw $ra, 0($sp)

	
	# Get A and B from the stack, add them
	lw $t0, 4($sp)
	lw $t1, 8($sp)
	add $t0, $t0, $t1

	# Push the value on the stack, and call f2
	addi $sp, $sp, -4
	sw $t0, 0($sp)
	jal f2

	# Remove the value we pushed on the stack,
	# then restore RA
	addi $sp, $sp, 4
	lw $ra, 0($sp)
	addi $sp, $sp, 4

	# Back to wherever we were called from
	jr $ra

	
	# Save RA
main:	addi $sp, $sp, -4
	sw $ra, 0($sp)

	# push 4
	li $t0, 4
	addi $sp, $sp, -4
	sw $t0, 0($sp)

	# push 3
	li $t0, 3
	addi $sp, $sp, -4
	sw $t0, 0($sp)

	jal f1

	# CHECK VALUE OF V0 HERE!
	nop
	nop
	nop
	nop

	# Pop the A and B values we pushed on
	addi $sp, $sp, 8
	
	# Restore RA
	lw $ra, 0($sp)
	addi $sp, $sp, 4

	# Back to the operating system (machine shuts down
	# after this).
	jr $ra
	
	