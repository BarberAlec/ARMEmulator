//#include "useful-functions.h"
#include <vector>
#include "instruction.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <bitset>
#include <map>
/**
 * 
 * 
 * 
 **/



class ARMFile{
public:

    // Constructor for ARMFile
    ARMFile ();

    // Currently does nothing -- may delete
    void initialiseMemory ();

    // not implemented as of yet
    bool CompileToMachineInstructions ();


    // Add and close files
    void addSourceFile (std::string fileName);

    void closeSourceFile ();


    // Print Register Contents Functions
    void printRegistersBits ();

    void printRegistersHex ();


    // Load contents of file
    void loadSourceFile ();


    // Execute File after loading contents
    void executeFile (bool printAfterEachIter, bool printInstructsAsExecuted);

private:

    // Reads FILE in full searching for Labels and in the future defined memory
    void firstPassLoadSourceFile ();


    // Helper function that returns pointer to appropiate register given a string name
    reg* string2Reg (std::string R);

    // Helper Function that returns int given a string value for a hex/dec etc. number
    uint32_t string2Num (std::string N);

    // bit 4 to 7 are out of bounds and should not be used
    uint8_t condFlags;

    // Register Memory
    reg r0, r1, r2, r3, r4, r5, r6, r7, r8, r9 ,r10, r11, r12;
    reg SP;
    reg LR;
    reg PC;

    // Label addressing
    std::map<std::string, uint32_t> labels;

    // Memory for Instructions and machine code instructions (not implemented yet)
    std::vector<instruction> instructionVect;
    std::vector<uint32_t> machineInstructionVect;

    // Incoming text file
    std::ifstream FILE;
};