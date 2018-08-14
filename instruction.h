//#include "useful-functions.h"
#include "register.h"
#include <iostream>
/**
 * 
 * 
 **/



class instruction{
public:
    instruction ();

    instruction (std::string command, reg* ar1);

    instruction (std::string command, reg* ar1, reg* ar2);

    instruction (std::string command, reg* ar1, uint32_t ar2);

    instruction (std::string command, reg* ar1, reg* ar2, reg* ar3);

    instruction (std::string command, reg* ar1, uint32_t ar2, uint32_t ar3);

    instruction (std::string command, reg* ar1, reg* ar2, uint32_t ar3);

    instruction (std::string command, reg* ar1, uint32_t ar2, reg* ar3);

    enum enum_operats{
        UNDEFINED,
        MOV,
        ADD,
        SUB,
        CMP
    };

    // Get Machine code 32 bit instruction
    uint32_t getMachineInstruction ();

    // Set condition Flags pointer
    void setCondFlags (uint8_t *ptr);


    enum_operats string2Operats (std::string input);

    // Called by Emulator to execute each instruction independently
    void execute ();

private:

    void generateMachineInstruction ();


    // General Organisation Variables
    uint8_t numberOperands;

    // MOV, SUB etc.
    enum_operats Operat;

    // Register arguments
    reg* opperand1;
    reg* opperand2;
    reg* opperand3;

    // Non-register arguments
    uint32_t NR_operand2;
    uint32_t NR_operand3;

    // instruction and opperands coverted into a 32 bit instruction
    uint32_t machineInstruction;

    bool machineCodeGenerated;

    uint8_t *cond_flags;


};