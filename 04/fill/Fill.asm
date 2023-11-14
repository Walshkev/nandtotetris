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
// sets the value of D to M[KBD]
@KBD
D=M
// jumps to black if D is greater than 0
@Black
D;JGT
// jumps to white if D is equal to 0
@White
D;JEQ

//jumps back to KeyPressed
@keyPressed
0;JMP

//when black is called it sets the value of M[1] to -1 and jumps to switchColor
// -1 represents black 1111111111111
(Black)
@1
M=-1
@switchColor
0;JMP


// when white is called it sets the value of M[1] to 0 and jumps to switchColor
(White)
@1
M=0
@switchColor
0;JMP

//when switch color is called it sets the value of D to M[1] 
(switchColor)
@1
D=M 

// sets the value of D and M[0] to A
@0 
A=M 
M=D 
//this incriments M and stores it in D 
@0
D=M+1
@KBD
D=A-D 

//incriments A by 1 
@0
M=M+1
A=M 

// jumps to switchcolor if D (if D and A are the same edge of the screen) is greater than 0
@switchColor
D;JGT

@Restart
0;JMP







@100
D=M
0;JMP