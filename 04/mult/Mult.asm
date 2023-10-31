// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.

//sets the meomory value of position 2 to 0 
@2
M=0

//sets the memory value d to the value at M[0]
@0
D=M
// sets a to @END's position 
@END
// if d is 0 then jump to the end
D;JEQ

@1
D=M
@END
// if d is 0 then jump to the end
D;JEQ

@0
D=M


(LOOP)
@1
D=M

@2
M=D+M

@0
M=M-1

D=M 
@LOOP
// if d is greater than 1 then jump to the postion on loop 
D;JGT

(END)
@END
0;JMP


