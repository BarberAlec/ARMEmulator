//#include "useful-functions.h"
#include "register.h"
#include <iostream>
#include <limits>
#include <map>
/**
 * 
 * 
 **/



class instruction{
public:

    // Various Constructors for different scenarios

    instruction ();

    instruction (std::string command, reg* ar1);

    instruction (std::string command, uint32_t ar1);

    instruction (std::string command, reg* ar1, reg* ar2);

    instruction (std::string command, reg* ar1, uint32_t ar2);

    instruction (std::string command, reg* ar1, reg* ar2, reg* ar3);

    instruction (std::string command, reg* ar1, uint32_t ar2, uint32_t ar3);

    instruction (std::string command, reg* ar1, reg* ar2, uint32_t ar3);

    instruction (std::string command, reg* ar1, uint32_t ar2, reg* ar3);

    

    enum enum_operats{
        // X designates that it has been implemented
        UNDEFINED,
        ADC,
        ADD,        // X
        AND,        // X
        B,          // X
        BIC,
        BL,         // Got my eyes on you
        BX,         // you too laddy
        CDP,
        CMN,
        CMP,
        EOR,        // X
        LDC,
        LDM,
        LDR,
        MCR,
        MLA,
        MOV,        // X
        MRC,
        MRS,
        MSR,
        MUL,        // X
        MVN,
        ORR,        // X
        RSB,
        RSC,
        SBC,
        STC,
        STM,
        STR,
        SUB,        // X
        SWI,
        SWP,
        TEQ,
        TST
    };

    enum enum_condition_code{
        UNDEFINED_C,
        NO_COND_CODE,
        EQ,
        NE,
        CS,
        CC,
        MI,
        PL,
        VS,
        VC,
        HI,
        LS,
        GE,
        LT,
        GT,
        LE,
        AL
    };

    // Get Machine code 32 bit instruction
    uint32_t getMachineInstruction ();

    // Set condition Flags pointer
    void setCondFlags (uint8_t *ptr);

    void setPCPointer (reg* p);


    enum_operats string2Operats (std::string input);

    // Called by Emulator to execute each instruction independently
    void execute ();

    void printInstructionInfo ();

private:
    // To be implemented soon !!!!!
    void generateMachineInstruction ();


    // Returns true if string contains a S to designate flag updates
    bool updateFlags (std::string instruc, int command_length);

    //  returns condition code 
    enum_condition_code getCondCode (std::string instruc, int command_length);


    // Helper functions for execute () to keep code clean and maintainable
    void executeADD ();

    void executeAND ();

    void executeB ();

    void executeCMP ();

    void executeEOR ();

    void executeMOV ();

    void executeMUL ();

    void executeORR ();

    void executeSUB ();

    // General Organisation Variables
    uint8_t numberOperands;

    // MOV, SUB etc.
    enum_operats Operat;

    // Register arguments
    reg* opperand1;
    reg* opperand2;
    reg* opperand3;

    // Pointer to PC register (needed for branching)
    reg* pc;

    // Non-register arguments
    uint32_t NR_operand1;
    uint32_t NR_operand2;                   // Not Register Opperands
    uint32_t NR_operand3;

    // Pointer to cond flags which are owned by ARM-file
    uint8_t *cond_flags;

    // Should cond_flags be updated with this instruction (i.e. is s present)
    bool update_flag;

    enum_condition_code cond_code;

    // instruction and opperands coverted into a 32 bit instruction
    uint32_t machineInstruction;

    // Has MachineCode been generated yet
    bool machineCodeGenerated;
};