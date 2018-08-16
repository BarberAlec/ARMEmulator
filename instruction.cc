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

    Operat = enum_operats::UNDEFINED;

    cond_flags = NULL;
    update_flag = false;
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
    update_flag = false;
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
    update_flag = false;
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
    update_flag = false;
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
    update_flag = false;
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
    update_flag = false;
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
    update_flag = false;
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
    update_flag = false;
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
    update_flag = false;
}

instruction::enum_operats instruction::string2Operats (std::string input){

    std::string input_3 = input.substr (0,3);
    std::string input_2 = input.substr (0,2);
    std::string input_1 = input.substr (0,1);

    if (input_3.compare("ADC") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return ADC;
    }
    else if (input_3.compare("ADD") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return ADD;
    }
    else if (input_3.compare("AND") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return AND;
    }
    else if (input_1.compare("B") == 0){
        if (updateFlags (input, 1)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 1);
        return B;
    }
    else if (input_3.compare("BIC") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return BIC;
    }
    else if (input_2.compare("BL") == 0){
        if (updateFlags (input, 2)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 2);
        return BL;
    }
    else if (input_2.compare("BX") == 0){
        if (updateFlags (input, 2)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 2);
        return BX;
    }
    else if (input_3.compare("CDP") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return CDP;
    }
    else if (input_3.compare("CMN") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return CMN;
    }
    else if (input_3.compare ("CMP") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return CMP;
    }
    else if (input_3.compare("EOR") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return EOR;
    }
    else if (input_3.compare ("LDC") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return LDC;
    }
    else if (input_3.compare ("LDM") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return LDM;
    }
    else if (input_3.compare ("LDR") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return LDR;
    }
    else if (input_3.compare ("MCR") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return MCR;
    }
    else if (input_3.compare ("MLA") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return MLA;
    }
    else if (input_3.compare("MOV") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return MOV;
    }
    else if (input_3.compare ("MRC") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return MRC;
    }
    else if (input_3.compare ("MRS") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return MRS;
    }
    else if (input_3.compare ("MSR") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return MSR;
    }
    else if (input_3.compare("MUL") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return MUL;
    }
    else if (input_3.compare ("MVN") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return MVN;
    }
    else if (input_3.compare("ORR") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return ORR;
    }
    else if (input_3.compare ("RSB") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return RSB;
    }
    else if (input_3.compare ("RSC") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return RSC;
    }
    else if (input_3.compare ("SBC") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return SBC;
    }
    else if (input_3.compare ("STC") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return STC;
    }
    else if (input_3.compare ("STM") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return STM;
    }
    else if (input_3.compare ("STR") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return STR;
    }
    else if (input_3.compare("SUB") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return SUB;
    }
    else if (input_3.compare ("SWI") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return SWI;
    }
    else if (input_3.compare ("SWP") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return SWP;
    }
    else if (input_3.compare ("TEQ") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return TEQ;
    }
    else if (input_3.compare ("TST") == 0){
        if (updateFlags (input, 3)){
            update_flag = true;
        }
        cond_code = getCondCode (input, 3);
        return TST;
    }
    else{
        return enum_operats::UNDEFINED;
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

bool instruction::updateFlags (std::string instruc, int command_length){
    if (instruc.size () == command_length){
        return false;
    }
    if (instruc.at (instruc.size () - 1) == 'S' || instruc.at (instruc.size () - 1) == 's'){
        return true;
    }
    else{
        return false;
    }
}

instruction::enum_condition_code instruction::getCondCode (std::string instruc, int command_length){
    if (instruc.size () == command_length){
        return NO_COND_CODE;
    }

    std::string addon = instruc.substr (command_length, instruc.size () - command_length);
    // Remove S if present
    if (addon.at (addon.size () - 1) == 's' || addon.at (addon.size () - 1) == 'S'){
        addon = addon.substr (0, addon.size () - 1);
    }
    if (addon.size () == 0){
        return NO_COND_CODE;
    }


    if (addon.compare ("EQ") == 0){
        return EQ;
    }
    else if (addon.compare ("NE") == 0){
        return NE;
    }
    else if (addon.compare ("CS") == 0){
        return CS;
    }
    else if (addon.compare ("CC") == 0){
        return CC;
    }
    else if (addon.compare ("MI") == 0){
        return MI;
    }
    else if (addon.compare ("PL") == 0){
        return PL;
    }
    else if (addon.compare ("VS") == 0){
        return VS;
    }
    else if (addon.compare ("VC") == 0){
        return VC;
    }
    else if (addon.compare ("HI") == 0){
        return HI;
    }
    else if (addon.compare ("LS") == 0){
        return LS;
    }
    else if (addon.compare ("GE") == 0){
        return GE;
    }
    else if (addon.compare ("LT") == 0){
        return LT;
    }
    else if (addon.compare ("GT") == 0){
        return GT;
    }
    else if (addon.compare ("LE") == 0){
        return LE;
    }
    else if (addon.compare ("AL") == 0){
        return AL;
    }
    else{
        return UNDEFINED_C;
    }


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
                (*cond_flags) = (*cond_flags) & 0b11111011;             // Set Z flag to low
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