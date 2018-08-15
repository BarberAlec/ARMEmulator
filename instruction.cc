#include "instruction.h"

instruction::instruction (){
    opperand1 = NULL;
    opperand2 = NULL;
    opperand3 = NULL;

    pc = NULL;

    NR_operand1 = 0;
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

    pc = NULL;

    NR_operand1 = 0;
    NR_operand2 = 0;
    NR_operand3 = 0;

    numberOperands = 1;

    machineInstruction = 0;
    machineCodeGenerated = false;

    Operat = string2Operats (command);

    cond_flags = NULL;
}

instruction::instruction (std::string command, uint32_t ar1){
    opperand1 = NULL;
    opperand2 = NULL;
    opperand3 = NULL;

    pc = NULL;

    NR_operand1 = ar1;
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

    pc = NULL;

    NR_operand1 = 0;
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

    pc = NULL;

    NR_operand1 = 0;
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

    pc = NULL;

    NR_operand1 = 0;
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

    pc = NULL;
    
    NR_operand1 = 0;
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

    pc = NULL;

    NR_operand1 = 0;
    NR_operand2 = 0;
    NR_operand3 = ar3;

    numberOperands = 3;

    machineInstruction = 0;
    machineCodeGenerated = false;

    Operat = string2Operats (command);
    
    cond_flags = NULL;
}

instruction::instruction (std::string command, reg* ar1, uint32_t ar2, reg* ar3){
    opperand1 = ar1;
    opperand2 = NULL;
    opperand3 = ar3;

    pc = NULL;

    NR_operand1 = 0;
    NR_operand2 = ar2;
    NR_operand3 = 0;

    numberOperands = 3;

    machineInstruction = 0;
    machineCodeGenerated = false;

    Operat = string2Operats (command);
    
    cond_flags = NULL;
}

instruction::enum_operats instruction::string2Operats (std::string input){
    if (input.compare("ADC") == 0){
        return ADC;
    }
    else if (input.compare("ADD") == 0){
        return ADD;
    }
    else if (input.compare("AND") == 0){
        return AND;
    }
    else if (input.compare("B") == 0){
        return B;
    }
    else if (input.compare("BIC") == 0){
        return BIC;
    }
    else if (input.compare("BL") == 0){
        return BL;
    }
    else if (input.compare("BX") == 0){
        return BX;
    }
    else if (input.compare("CDP") == 0){
        return CDP;
    }
    else if (input.compare("CMN") == 0){
        return CMN;
    }
    else if (input.compare ("CMP") == 0){
        return CMP;
    }
    else if (input.compare("EOR") == 0){
        return EOR;
    }
    else if (input.compare ("LDC") == 0){
        return LDC;
    }
    else if (input.compare ("LDM") == 0){
        return LDM;
    }
    else if (input.compare ("LDR") == 0){
        return LDR;
    }
    else if (input.compare ("MCR") == 0){
        return MCR;
    }
    else if (input.compare ("MLA") == 0){
        return MLA;
    }
    else if (input.compare("MOV") == 0){
        return MOV;
    }
    else if (input.compare ("MRC") == 0){
        return MRC;
    }
    else if (input.compare ("MRS") == 0){
        return MRS;
    }
    else if (input.compare ("MSR") == 0){
        return MSR;
    }
    else if (input.compare("MUL") == 0){
        return MUL;
    }
    else if (input.compare ("MVN") == 0){
        return MVN;
    }
    else if (input.compare("ORR") == 0){
        return ORR;
    }
    else if (input.compare ("RSB") == 0){
        return RSB;
    }
    else if (input.compare ("RSC") == 0){
        return RSC;
    }
    else if (input.compare ("SBC") == 0){
        return SBC;
    }
    else if (input.compare ("STC") == 0){
        return STC;
    }
    else if (input.compare ("STM") == 0){
        return STM;
    }
    else if (input.compare ("STR") == 0){
        return STR;
    }
    else if (input.compare("SUB") == 0){
        return SUB;
    }
    else if (input.compare ("SWI") == 0){
        return SWI;
    }
    else if (input.compare ("SWP") == 0){
        return SWP;
    }
    else if (input.compare ("TEQ") == 0){
        return TEQ;
    }
    else if (input.compare ("TST") == 0){
        return TST;
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

void instruction::setPCPointer (reg* p){
    pc = p;
}

void instruction::execute (){


    switch (Operat){
        case ADD:
            executeADD ();
            break;

        case AND:
            executeAND ();
            break;

        case B:
            executeB ();
            break;

        case CMP:
            executeCMP ();
            break;

        case EOR:
            executeEOR ();
            break;

        case MOV:
            executeMOV ();
            break;

        case MUL:
            executeMUL ();
            break;

        case ORR:
            executeORR ();
            break;

        case SUB:
            executeSUB ();
            break;
        default:
            std::cout << "This Operator is not recognised or has not been implemented yet >> " << Operat << " <<" << std::endl;
            break;
    }

}

void instruction::printInstructionInfo (){
    std::cout << "Information for Instruction" << std::endl;
    std::cout << "Operate: " << Operat << std::endl;
    std::cout << "numberOperands: " << numberOperands << std::endl;
    std::cout << "opperand1: " << opperand1 << std::endl;
    std::cout << "opperand2: " << opperand2 << std::endl;
    std::cout << "opperand3: " << opperand3 << std::endl;
    std::cout << "NR_operand1: " << NR_operand1 << std::endl;
    std::cout << "NR_operand2: " << NR_operand2 << std::endl;
    std::cout << "NR_operand3: " << NR_operand3 << std::endl;
}

void instruction::executeADD (){
    if (numberOperands == 2){
        if (opperand2 == NULL){
            opperand1->setMem (opperand1->getMem () + NR_operand2);
        }
        else{
            opperand1->setMem (opperand1->getMem () + opperand2->getMem ());
        }
    }
    else{
        if (opperand2 == NULL){
            if (opperand3 == NULL){
                opperand1->setMem (NR_operand2 + NR_operand3);
            }
            else{
                opperand1->setMem (NR_operand2 + opperand3->getMem ());
            }
        }
        else{
            if (opperand3 == NULL){
                opperand1->setMem (opperand2->getMem () + NR_operand3);
            }
            else{
                opperand1->setMem (opperand2->getMem () + opperand3->getMem ());
            }
        }
    }
}

void instruction::executeAND (){
    if (numberOperands < 3){
        std::cout << "ERROR: instruction::executeAND must have three arguments" << std::endl;
    }
    else{
        if (opperand2 == NULL){
            if (opperand3 == NULL){
                opperand1->setMem (NR_operand2 & NR_operand3);
            }
            else{
                opperand1->setMem (NR_operand2 & opperand3->getMem ());
            }
        }
        else{
            if (opperand3 == NULL){
                opperand1->setMem (opperand2->getMem () & NR_operand3);
            }
            else{
                opperand1->setMem (opperand2->getMem () & opperand3->getMem ());
            }
        }
    }
}

void instruction::executeB (){
    if (numberOperands == 1){
        pc->setMem (NR_operand1);
    }  
    else{
        std::cout << "ERROR: B can only have one argument..." << std::endl;
    }
}

void instruction::executeCMP (){
    std::cout << "got into cmp" << std::endl;
    if (numberOperands == 2){
        if (opperand1 != NULL){
            uint32_t temp;
            if (opperand2 == NULL){
                temp = opperand1->getMem () - NR_operand2;

                // TEST FOR CARRY
                if (opperand1->getMem () >= NR_operand2){               // **unsigned comparison**
                    // No carry
                    (*cond_flags) = (*cond_flags) & 0b11111101;         // Set C flag to low
                }
                else{
                    // There is a carry
                    (*cond_flags) = (*cond_flags) | 0b00000010;         // Set C flag to high
                }

                // TEST FOR OVERFLOW
                if ((((0x80000000 & opperand1->getMem ()) != 0x0) && ((0x80000000 & NR_operand2) == 0x0))  ||
                                                    (((0x80000000 & opperand1->getMem ()) == 0x0) && ((0x80000000 & NR_operand2) != 0x0))){
                    // signs of arguments differ
                    if ((((0x80000000 & opperand1->getMem ()) != 0x0) && ((temp & 0x80000000) == 0x0)) || 
                                                    (((0x80000000 & opperand1->getMem ()) == 0x0) && ((temp & 0x80000000) != 0x0))){
                        (*cond_flags) = (*cond_flags) | 0b00000001;     // Set V flag to high
                    }
                    else{
                        (*cond_flags) = (*cond_flags) & 0b11111110;     // Set V flag to low
                    }  
                }
            }
            else{
                temp = opperand1->getMem () - opperand2->getMem ();

                // TEST FOR CARRY
                if (opperand1->getMem () >= opperand2->getMem ()){               // **unsigned comparison**
                    // No carry
                    (*cond_flags) = (*cond_flags) & 0b11111101;         // Set C flag to low
                }
                else{
                    // There is a carry
                    (*cond_flags) = (*cond_flags) | 0b00000010;         // Set C flag to high
                }

                // TEST FOR OVERFLOW
                if ((((0x80000000 & opperand1->getMem ()) != 0x0) && ((0x80000000 & opperand2->getMem ()) == 0x0))  ||
                                                    (((0x80000000 & opperand1->getMem ()) == 0x0) && ((0x80000000 & opperand2->getMem ()) != 0x0))){
                    // signs of arguments differ
                    if ((((0x80000000 & opperand1->getMem ()) != 0x0) && ((temp & 0x80000000) == 0x0)) || 
                                                    (((0x80000000 & opperand1->getMem ()) == 0x0) && ((temp & 0x80000000) != 0x0))){
                        (*cond_flags) = (*cond_flags) | 0b00000001;     // Set V flag to high
                    }
                    else{
                        (*cond_flags) = (*cond_flags) & 0b11111110;     // Set V flag to low
                    }  
                }
            }

            // TEST FOR NEGITIVITY
            if ((0x80000000 & temp) != 0x00000000){
                (*cond_flags) = (*cond_flags) | 0b00001000;             // Set N flag to high
            }
            else{
                (*cond_flags) = (*cond_flags) & 0b11110111;             // Set N flag to low
            }

            // TEST FOR ZERO...NESS
            if (temp == 0x00000000){
                (*cond_flags) = (*cond_flags) | 0b00000100;             // Set Z flag to high
            }
            else{
                (*cond_flags) = (*cond_flags) & 0b11110111;             // Set Z flag to low
            }
        }
        else{
            std::cout << "ERROR: CMP requires first argument to be a register." << std::endl;
        }
    }
    else{
        std::cout << "ERROR: CMP requires exactly 2 arguments." << std::endl;
    }
}

void instruction::executeEOR (){
    if (numberOperands < 3){
        std::cout << "ERROR: instruction::executeEOR must have three arguments" << std::endl;
    }
    else{
        if (opperand2 == NULL){
            if (opperand3 == NULL){
                opperand1->setMem (NR_operand2 ^ NR_operand3);
            }
            else{
                opperand1->setMem (NR_operand2 ^ opperand3->getMem ());
            }
        }
        else{
            if (opperand3 == NULL){
                opperand1->setMem (opperand2->getMem () ^ NR_operand3);
            }
            else{
                opperand1->setMem (opperand2->getMem () ^ opperand3->getMem ());
            }
        }
    }
}

void instruction::executeMOV (){
    if (numberOperands == 2){
        if (opperand2 != NULL){
            opperand1->setMem (opperand2->getMem ());
        }
        else{
            opperand1->setMem (NR_operand2);
        }
    }
    else{
        std::cout << "Error: MOV only support two operands at the moment..." << std::endl;
    }
}

void instruction::executeMUL (){
    // TODO implement more accurate Multiply function...
    if (numberOperands < 3){
        std::cout << "Error instruction::executeMUL requires 3 arguments" << std::endl;
    }
    else{
        if (opperand2 == NULL){
            if (opperand3 == NULL){
                opperand1->setMem (0xFFFFFFFF & (NR_operand2 * NR_operand3));     // 0xFFFFFFFF ensures that only the least significant 32 bits are sent
            }
            else{
                opperand1->setMem (0xFFFFFFFF & (NR_operand2 * opperand3->getMem ()));
            }
        }
        else{
            if (opperand3 == NULL){
                opperand1->setMem (0xFFFFFFFF & (opperand2->getMem () * NR_operand3));
            }
            else{
                opperand1->setMem (0xFFFFFFFF & (opperand2->getMem () * opperand3->getMem ()));
            }
        }
    }
}

void instruction::executeORR (){
    if (numberOperands < 3){
        std::cout << "ERROR: instruction::executeORR must have three arguments" << std::endl;
    }
    else{
        if (opperand2 == NULL){
            if (opperand3 == NULL){
                opperand1->setMem (NR_operand2 | NR_operand3);
            }
            else{
                opperand1->setMem (NR_operand2 | opperand3->getMem ());
            }
        }
        else{
            if (opperand3 == NULL){
                opperand1->setMem (opperand2->getMem () | NR_operand3);
            }
            else{
                opperand1->setMem (opperand2->getMem () | opperand3->getMem ());
            }
        }
    }
}

void instruction::executeSUB (){
    if (numberOperands == 2){
        if (opperand2 == NULL){
            opperand1->setMem (opperand1->getMem () - NR_operand2);
        }
        else{
            opperand1->setMem (opperand1->getMem () - opperand2->getMem ());
        }
    }
    else{
        if (opperand2 == NULL){
            if (opperand3 == NULL){
                opperand1->setMem (NR_operand2 - NR_operand3);
            }
            else{
                opperand1->setMem (NR_operand2 - opperand3->getMem ());
            }
        }
        else{
            if (opperand3 == NULL){
                opperand1->setMem (opperand2->getMem () - NR_operand3);
            }
            else{
                opperand1->setMem (opperand2->getMem () - opperand3->getMem ());
            }
        }
    }
}