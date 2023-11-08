// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

(Restart)
@SCREEN
D=A
@0
M=D

(KeyPressed)

@KBD
D=M
@Black
D;JGT
@White
D;JEQ


@keyPressed
0;JMP

(Black)
@1
M=-1
@switchColor
0;JMP



(White)
@1
M=0
@switchColor
0;JMP

(switchColor)
@1
D=M 

@0 
A=M 
M=D 

@0
D=M+1
@KBD
D=A-D 

@0
M=M+1
A=M 


@switchColor
D;JGT

@Restart
0;JMP







