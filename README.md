# ARMEmulator
**The ARM Interpreter.**

The ARMEmulator is an interpreter for the ARM instruction set. Devlopment for this project started on Monday the 13th of Augest. At this early stage, there are key features which have not as of yet been implemented, asides this, there are still many bugs in the program. If you do find any bugs, please contact me at barberal@tcd.ie.

Instructions:

- Open notepad and save a new file in the ARMEulator's working directory called examples.txt.

- Go to your editors settings and ensure that tabs are not displayed using spaces (as is default on many applications).

- Write your ARM program using tab indentations before instructions always, no spaces between registers ( ADD r0,r1,r2) and all caps for instructions.

- For labels, begin the label without a tab and seperate the end of the label from the main instruction (if any) by a single space.

- Do not have any empty lines

- To compile the Interpreter, go to the working directory in terminal and execute the following command:

> make

- To run your program, while still in the working directory in terminal, execute the following command:

>./armulate

-Enjoy!!


Features: 

 - [X] Basic instructions such as ADD AND and EOR
 
 - [X] Labels and Branching with B

 - [X] condition flags
 
 - [X] conditional execution

 - [X] s feature (MOVS etc.)

 - [X] character support

 - [ ] General robustness...

 - [X] An actual Make File

 - [ ] Passable UI

 - [ ] Logic shifts

 - [ ] Comments

 - [ ] Debugging features
