# ARMEmulator
**The ARM Interpreter.**

The ARMEmulator is an interpreter for the ARM instruction set.

Instructions:

-Open notepad and save a new file in the ARMEulator's working directory called examples.txt.

-Go to your editors settings and ensure that tabs are not displayed using spaces (as is default on many applications).

-Write your ARM program using tab indentations before instructions always, no spaces between registers ( ADD r0,r1,r2) and all caps for instructions.

-For labels, begin the label without a tab and seperate the end of the label from the main instruction (if any) by a single space.

-Do not have any empyty lines

-To compile the Interpreter, go to the working directory in terminal and execute the following command:

> g++ ARM-file.cc instruction.cc register.cc emulator.cc

-To run your program, while still in the working directory in terminal, execute the following command:

>./a.out

-If you encounter any bugs please let me know at barberal@tcd.ie


Features: 

 - [X] Basic instructions such as ADD AND and EOR
 
 - [X] Labels and Branching with B

 - [X] condition flags
 
 - [X] conditional execution

 - [X] s feature (MOVS etc.)

 - [ ] character support

 - [ ] General robustness...

 - [ ] An actual Make File

 - [ ] Passable UI

 - [ ] Logic shifts

 - [ ] Comments

 - [ ] Debugging features
