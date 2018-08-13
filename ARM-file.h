//#include "useful-functions.h"
#include <vector>
#include "instruction.h"
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
/**
 * 
 * 
 * 
 **/



class ARMFile{
public:

    //Constructor for ARMFile
    ARMFile ();

    void initialiseMemory ();

    bool CompileToMachineInstructions ();

    void addSourceFile (std::string fileName);

    void closeSourceFile ();

    void printRegisters ();

    void loadSourceFile ();

    void executeFile ();

private:

    // bit 4 to 7 are out of bounds and should not be used
    uint8_t condFlags;
    reg r0, r1, r2, r3, r4, r5, r6, r7, r8, r9 ,r10, r11, r12;
    reg SP;
    reg LP;
    reg PC;

    std::vector<instruction> instructionVect;
    std::vector<uint32_t> machineInstructionVect;

    std::ifstream FILE;
};