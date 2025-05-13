.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
  li $v0, 4
  la $a0, _prompt
  syscall
  li $v0, 5
  syscall
  jr $ra
write:
  li $v0, 1
  syscall
  li $v0, 4
  la $a0, _ret
  syscall
  move $v0, $0
  jr $ra
main:
  addi $sp, $sp, -4
  sw $s8, 0($sp)
  la $s8, 4($sp)
  addi $sp, $sp, -100
  li $t0, 0
  sw $t0, 96($sp)
  lw $t0, 96($sp)
  sw $t0, 92($sp)
  li $t0, 1
  sw $t0, 88($sp)
  lw $t0, 88($sp)
  sw $t0, 84($sp)
  li $t0, 0
  sw $t0, 80($sp)
  lw $t0, 80($sp)
  sw $t0, 76($sp)
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal read
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $t0, $v0
  sw $t0, 72($sp)
  lw $t0, 72($sp)
  sw $t0, 68($sp)
  lw $t0, 72($sp)
  sw $t0, 64($sp)
L1:
  lw $t0, 76($sp)
  sw $t0, 56($sp)
  lw $t0, 68($sp)
  sw $t0, 52($sp)
  lw $t0, 56($sp)
  lw $t1, 52($sp)
  blt $t0, $t1, L2
  j L3
L2:
  lw $t0, 92($sp)
  sw $t0, 40($sp)
  lw $t0, 84($sp)
  sw $t0, 36($sp)
  lw $t0, 40($sp)
  lw $t1, 36($sp)
  add $t0, $t0, $t1
  sw $t0, 32($sp)
  lw $t0, 32($sp)
  sw $t0, 28($sp)
  lw $t0, 84($sp)
  sw $t0, 24($sp)
  lw $a0, 24($sp)
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $t0, $v0
  li $t0, 0
  sw $t0, 64($sp)
  lw $t0, 84($sp)
  sw $t0, 20($sp)
  lw $t0, 20($sp)
  sw $t0, 92($sp)
  lw $t0, 20($sp)
  sw $t0, 64($sp)
  lw $t0, 28($sp)
  sw $t0, 16($sp)
  lw $t0, 16($sp)
  sw $t0, 84($sp)
  lw $t0, 16($sp)
  sw $t0, 64($sp)
  lw $t0, 76($sp)
  sw $t0, 12($sp)
  li $t0, 1
  sw $t0, 8($sp)
  lw $t0, 12($sp)
  lw $t1, 8($sp)
  add $t0, $t0, $t1
  sw $t0, 4($sp)
  lw $t0, 4($sp)
  sw $t0, 76($sp)
  lw $t0, 4($sp)
  sw $t0, 64($sp)
  j L1
L3:
  li $t0, 0
  sw $t0, 0($sp)
  lw $v0, 0($sp)
  move $sp, $s8
  lw $s8, -4($s8)
  jr $ra
