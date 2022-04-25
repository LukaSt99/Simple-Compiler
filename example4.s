
.data
newline: .asciiz  "\n"
tmp: .word  0
i: .word  0
bab: .float 0.0
a: .float 0.0
h: .word  0

.text
lw   $s0 , tmp 
lw   $s1 , i 
l.s  $f0 , bab 

li    $t0  , 1  
mtc1    $t0  , $f1 
cvt.s.w $f1  , $f1  
mov.s   $f0    , $f1  


li   $t0 , 4 
mtc1 $t0 , $f1
cvt.s.w $f1 , $f1
add.s $f2 , $f0 , $f1 

cvt.w.s   $f1 , $f2
mfc1  		$t0 , $f1 
move  		$s1   , $t0 

L1: bge  $s1, 10, exit1 


li   $v0 , 1 
move $a0 , $s1 
syscall 

li   $v0 , 4
la $a0 , newline
syscall

mul $t0 , $s1 , 8 
move $s0 , $t0 

addi $t1 , $s1 , 1 
move $s1 , $t1 


li   $v0 , 2 
mov.s $f12 , $f0 
syscall 

li   $v0 , 4
la $a0 , newline
syscall


li   $t2 , 1067869798 
mtc1 $t2 , $f1 
add.s $f3, $f0 ,$f1  
mov.s  $f0   , $f3 

j L1
exit1:

li   $s1 , 10 

l.s  $f1 , a 

li    $t0  , 5  
mtc1    $t0  , $f2 
cvt.s.w $f2  , $f2  
mov.s   $f1    , $f2  

beq  $s1, 10, else1

then1:
mul $t2 , $s0 , 5 
mtc1    $t2 , $f3 
cvt.s.w $f3 , $f3 
add.s $f2 , $f0 , $f3 

cvt.w.s   $f2 , $f2
mfc1  		$t0 , $f2 
move  		$s1   , $t0 

mul $t0 , $s1 , 8 
move $s0 , $t0 


li   $v0 , 1 
move $a0 , $s1 
syscall 

li   $v0 , 4
la $a0 , newline
syscall


li   $v0 , 1 
move $a0 , $s0 
syscall 

li   $v0 , 4
la $a0 , newline
syscall

j end1

else1:
  
li    $t0  , 15  
mtc1    $t0  , $f2 
cvt.s.w $f2  , $f2  
c.le.s  $f1 , $f2
bc1t   else2


li   $v0 , 2 
mov.s $f12 , $f1 
syscall 

li   $v0 , 4
la $a0 , newline
syscall

ble  $s1, 10, else3

then3:
li   $t2 , 1092983194 
mtc1 $t2 , $f3 
mul.s $f4, $f0 ,$f3  
mov.s  $f0   , $f4 


li   $v0 , 2 
mov.s $f12 , $f0 
syscall 

li   $v0 , 4
la $a0 , newline
syscall

j end3

else3:
  mul $t2 , $s0 , 1000 
move $s0 , $t2 


li   $v0 , 1 
move $a0 , $s0 
syscall 

li   $v0 , 4
la $a0 , newline
syscall

end3:

j end2

else2:
  
li   $v0 , 2 
mov.s $f12 , $f0 
syscall 

li   $v0 , 4
la $a0 , newline
syscall

ble  $s0, 300, else4

then4:
lw   $s2 , h 
li   $s2 , 0 

L2: bge  $s2, 10, exit2 


li   $v0 , 1 
move $a0 , $s2 
syscall 

li   $v0 , 4
la $a0 , newline
syscall

bge  $s2, 5, else5

then5:
L3: bge  $s2, 6, exit3 


li   $v0 , 1 
move $a0 , $s1 
syscall 

li   $v0 , 4
la $a0 , newline
syscall

addi $t0 , $s2 , 1 
move $s2 , $t0 

j L3
exit3:

j end5

else5:
  end5:

addi $t1 , $s2 , 1 
move $s2 , $t1 

j L2
exit2:

j end4

else4:
  
li   $v0 , 1 
move $a0 , $s0 
syscall 

li   $v0 , 4
la $a0 , newline
syscall


li   $v0 , 2 
mov.s $f12 , $f0 
syscall 

li   $v0 , 4
la $a0 , newline
syscall

end4:

end2:

end1:

