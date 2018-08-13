//#include "useful-functions.h"
#include "register.h"
/**
 * 
 * 
 **/



class instruction{
public:

    instruction(std::string command, reg* ar1, reg* ar2);

    instruction(std::string command, reg* ar1, reg* ar2, reg* ar3);

    uint32_t getMachineInstruction ();

    void setCondFlags (uint8_t *ptr);

private:

    void generateMachineInstruction ();


    // MOV, SUB etc.
    std::string Operat;

    // Register arguments
    reg* opperand1;
    reg* opperand2;
    reg* opperand3;

    // instruction and opperands coverted into a 32 bit instruction
    uint32_t machineInstruction;

    bool machineCodeGenerated;

    uint8_t *cond_flags;


};