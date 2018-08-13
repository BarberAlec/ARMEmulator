#include "instruction.h"

instruction::instruction (){
    opperand1 = NULL;
    opperand2 = NULL;
    opperand3 = NULL;

    NR_operand2 = 0;
    NR_operand3 = 0;

    numberOperands = 0;

    machineInstruction = 0;
    machineCodeGenerated = false;

    Operat = UNDEFINED;

    cond_flags = NULL;
}

instruction::instruction (std::string command, reg* ar1){
    opperand1 = ar1;
    opperand2 = NULL;
    opperand3 = NULL;

    NR_operand2 = 0;
    NR_operand3 = 0;

    numberOperands = 1;

    machineInstruction = 0;
    machineCodeGenerated = false;

    Operat = string2Operats (command);

    cond_flags = NULL;
}

instruction::instruction (std::string command, reg* ar1, reg* ar2){
    opperand1 = ar1;
    opperand2 = ar2;
    opperand3 = NULL;

    NR_operand2 = 0;
    NR_operand3 = 0;

    numberOperands = 2;

    machineInstruction = 0;
    machineCodeGenerated = false;

    Operat = string2Operats (command);

    cond_flags = NULL;
}

instruction::instruction (std::string command, reg* ar1, uint32_t ar2){
    opperand1 = ar1;
    opperand2 = NULL;
    opperand3 = NULL;

    NR_operand2 = ar2;
    NR_operand3 = 0;

    numberOperands = 2;

    machineInstruction = 0;
    machineCodeGenerated = false;

    Operat = string2Operats (command);
    
    cond_flags = NULL;
}

instruction::instruction (std::string command, reg* ar1, reg* ar2, reg* ar3){
    opperand1 = ar1;
    opperand2 = ar2;
    opperand3 = ar3;

    NR_operand2 = 0;
    NR_operand3 = 0;

    numberOperands = 3;

    machineInstruction = 0;
    machineCodeGenerated = false;

    Operat = string2Operats (command);

    cond_flags = NULL;
}


instruction::instruction (std::string command, reg* ar1, uint32_t ar2, uint32_t ar3){
    opperand1 = ar1;
    opperand2 = NULL;
    opperand3 = NULL;

    NR_operand2 = ar2;
    NR_operand3 = ar3;

    numberOperands = 3;

    machineInstruction = 0;
    machineCodeGenerated = false;

    Operat = string2Operats (command);
    
    cond_flags = NULL;
}

instruction::instruction (std::string command, reg* ar1, reg* ar2, uint32_t ar3){
    opperand1 = ar1;
    opperand2 = ar2;
    opperand3 = NULL;

    NR_operand2 = 0;
    NR_operand3 = ar3;

    numberOperands = 3;

    machineInstruction = 0;
    machineCodeGenerated = false;

    Operat = string2Operats (command);
    
    cond_flags = NULL;
}

instruction::enum_operats instruction::string2Operats (std::string input){
    if (input.compare("MOV") == 0){
        return MOV;
    }
    else if (input.compare("SUB") == 0){
        return SUB;
    }
    else if (input.compare("ADD") == 0){
        return ADD;
    }
    else if (input.compare ("CMP") == 0){
        return CMP;
    }
    else{
        return UNDEFINED;
    }
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

void instruction::execute (){


    switch (Operat){
        case MOV:
            // TODO add assert here for opperands
            
            opperand1->setMem (opperand2->getMem ());

            break;

        case ADD:

            opperand1->setMem (opperand2->getMem () + opperand3->getMem ());

            break;

        case SUB:
            
            opperand1->setMem (opperand2->getMem () - opperand3->getMem ());

            break;

        case CMP:

            std::cout << "Sorry CMP has not yet been implemented... " << std::endl;

            break;
        default:
            std::cout << "This Operator is not recognised or has not been implemented yet >> " << Operat << " <<" << std::endl;
            break;
    }

}