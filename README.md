# ARMEmulator
**The ARM Interpreter.**

The ARMEmulator is an interpreter for the ARM instruction set. Devlopment for this project started on Monday the 13th of Augest. At this early stage, there are key features which have not as of yet been implemented, asides this, there are still many bugs in the program. If you do find any bugs, please contact me at barberal@tcd.ie.

Instructions:

- To first compile the Interpreter, go to the working directory in terminal and execute the following command:

> make

- Next, to run the interpreter, execute the following command:

>./armulate

- This will prompt the program to begin, follow the instructions as provided.

- Once the text file opens, it is important to insure that tabs are not displayed as spaces as is the default for many text document viewers.

- Write your ARM program using tab indentations before instructions always, no spaces between registers ( ADD r0,r1,r2) and all caps for instructions.

- For labels, begin the label without a tab and seperate the end of the label from the main instruction (if any) by a single space.

- Do not have any empty lines

- It is advisable to look at the example.txt to get a grasp of the enviroment.

- Enjoy!!


Features: 

 - [X] Basic instructions such as ADD AND and EOR
 
 - [X] Labels and Branching with B

 - [X] Condition flags
 
 - [X] Conditional execution

 - [X] S feature (MOVS etc.)

 - [X] Character support

 - [ ] General robustness...

 - [X] An actual Make File

 - [X] Passable UI

 - [ ] Logic shifts

 - [ ] Comments

 - [ ] Debugging features
