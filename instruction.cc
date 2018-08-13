#include "instruction.h"


instruction::instruction(std::string command, reg* ar1, reg* ar2){
    opperand1 = ar1;
    opperand2 = ar2;
    Operat = command;
    machineCodeGenerated = false;
}

instruction::instruction(std::string command, reg* ar1, reg* ar2, reg* ar3){
    opperand1 = ar1;
    opperand2 = ar2;
    opperand3 = ar3;
    Operat = command;
    machineCodeGenerated = false;
}

uint32_t instruction::getMachineInstruction (){
    if (!machineCodeGenerated){
        machineCodeGenerated = true;
        generateMachineInstruction ();
    }
    return machineInstruction;
}

void instruction::generateMachineInstruction (){

}

void instruction::setCondFlags (uint8_t *ptr){
    cond_flags = ptr;
}