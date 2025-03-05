.data
.text
li $fp,268500992
la $ra, $program_end_20374042$
j $main$
             #### $main$
$main$:
             #### enter block1
             #### int a_1
addiu $fp, $fp, 4
             #### a_1 = 1
addiu $k0, $fp, -4
li $k1,1
sw $k1, 0($k0)
             #### int b_1
addiu $fp, $fp, 4
             #### b_1 = 2
addiu $k0, $fp, -4
li $k1,2
sw $k1, 0($k0)
             #### int c_1
addiu $fp, $fp, 4
             #### c_1 = 3
addiu $k0, $fp, -4
li $k1,3
sw $k1, 0($k0)
             #### $t_1 = a_1
addiu $k0, $fp, -12
lw $t0, 0($k0)
             #### $t_2 = b_1
addiu $k0, $fp, -8
lw $t1, 0($k0)
             #### $t_1 = $t_1 + $t_2
addu $t0, $t0, $t1
             #### $t_2 = c_1
addiu $k0, $fp, -4
lw $t1, 0($k0)
             #### $t_1 = $t_1 + $t_2
addu $t0, $t0, $t1
             #### $ret = $t_1
move $v0, $t0
             #### exit block 1
addiu $fp, $fp, -12
             #### return
jr $ra
             #### exit block
addiu $fp, $fp, -12
$program_end_20374042$: