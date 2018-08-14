#include "ARM-file.h"
/**
 * TODO:
 * > implemtnet hex option in string2num
 * > Make loadSourceFile more readable and less abhorent.... that thing is disgusting....
 **/

ARMFile::ARMFile(){
    condFlags = 0xF0;       // Initialise to all flags = 0
    initialiseMemory ();
}

bool ARMFile::CompileToMachineInstructions (){
    if (machineInstructionVect.size () < instructionVect.size ()){
        for (std::vector<instruction>::iterator iter = instructionVect.begin (); iter != instructionVect.end (); ++iter){
            machineInstructionVect.push_back (iter->getMachineInstruction ());
        }
        return true;
    }
    else{
        return false;
    }
}

void ARMFile::initialiseMemory (){
    
}

void ARMFile::addSourceFile (std::string fileName){
    std::string curr_line;

    FILE.open(fileName);

    if (FILE.is_open ()){
        std::cout << "Successfully Opened file: " << fileName << std::endl;
    }
    else{
        std::cout << "FATAL_ERROR: Unable to open file " << fileName << ", Exiting program...probably with minimal cleanup :(" <<std::endl;
        std::exit(-1);
    }
}

void ARMFile::closeSourceFile (){
    if (FILE.is_open ()){
        FILE.close ();
    }
    else{
        std::cout << "ERROR, attempting to close file that was never opened..." << std::endl;
    }
}

void ARMFile::printRegistersBits (){
    std::cout << "_____________________________________________________________________________________________________________________________________" << std::endl;

    std::cout << "|               r0               |               r1               |               r2               |               r3               |" << std::endl;
    std::cout << "|" << std::bitset<32> (r0.getMem ()) << "|" << std::bitset<32> (r1.getMem ()) << "|" << std::bitset<32> (r2.getMem ()) << "|" 
                << std::bitset<32> (r3.getMem ()) << "|" << std::endl;

    std::cout << "-------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "_____________________________________________________________________________________________________________________________________" << std::endl;

    std::cout << "|               r4               |               r5               |               r6               |               r7               |" << std::endl;
    std::cout << "|" << std::bitset<32> (r4.getMem ()) << "|" << std::bitset<32> (r5.getMem ()) << "|" << std::bitset<32> (r6.getMem ()) << "|" 
                << std::bitset<32> (r7.getMem ()) << "|" << std::endl;

    std::cout << "-------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "_____________________________________________________________________________________________________________________________________" << std::endl;
    
    std::cout << "|               r8               |               r9               |               r10              |               r11              |" << std::endl;
    std::cout << "|" << std::bitset<32> (r8.getMem ()) << "|" << std::bitset<32> (r9.getMem ()) << "|" << std::bitset<32> (r10.getMem ()) << "|" 
                << std::bitset<32> (r11.getMem ()) << "|" <<std::endl;

    std::cout << "-------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "_____________________________________________________________________________________________________________________________________" << std::endl;
    
    std::cout << "|               r12              |               SP               |               LC               |               PC               |" << std::endl;
    std::cout << "|" << std::bitset<32> (r12.getMem ()) << "|" << std::bitset<32> (SP.getMem ()) << "|" << std::bitset<32> (LP.getMem ()) << "|" 
                << std::bitset<32> (PC.getMem ()) << "|" << std::endl;
    std::cout << "-------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
}

void ARMFile::printRegistersHex (){
    std::cout  << std::setfill('0');
    
    std::cout << "_____________________________________________" << std::endl;

    std::cout << "|    r0    |    r1    |    r2    |    r3    |" << std::endl;
    std::cout << "| " << std::setw(8) << std::hex <<  (r0.getMem ()) << " | " << std::setw(8) << std::hex <<  (r1.getMem ()) << " | " << std::setw(8) << std::hex <<  (r2.getMem ()) << " | " 
                << std::setw(8) << std::hex <<  (r3.getMem ()) << " |" << std::endl;

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "_____________________________________________" << std::endl;

    std::cout << "|    r4    |    r5    |    r6    |    r7    |" << std::endl;
    std::cout << "| " << std::setw(8) << std::hex <<  (r4.getMem ()) << " | " << std::setw(8) << std::hex <<  (r5.getMem ()) << " | " << std::setw(8) << std::hex <<  (r6.getMem ()) << " | " 
                << std::setw(8) << std::hex <<  (r7.getMem ()) << " |" << std::endl;

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "_____________________________________________" << std::endl;
    
    std::cout << "|    r8    |    r9    |    r10   |    r11   |" << std::endl;
    std::cout << "| " << std::setw(8) << std::hex <<  (r8.getMem ()) << " | " << std::setw(8) << std::hex <<  (r9.getMem ()) << " | " << std::setw(8) << std::hex <<  (r10.getMem ()) << " | " 
                << std::setw(8) << std::hex <<  (r11.getMem ()) << " |" <<std::endl;

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "_____________________________________________" << std::endl;
    
    std::cout << "|    r12   |    SP    |    LC    |    PC    |" << std::endl;
    std::cout << "| " << std::setw(8) << std::hex <<  (r12.getMem ()) << " | " << std::setw(8) << std::hex <<  (SP.getMem ()) << " | " << std::setw(8) << std::hex <<  (LP.getMem ()) << " | " 
                << std::setw(8) << std::hex <<  (PC.getMem ()) << " |" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}

void ARMFile::loadSourceFile (){
    // TODO assert file has been opened
    std::string command;
    std::string arg1;
    std::string arg2;
    std::string arg3;
    reg* arg1_point;
    reg* arg2_point;
    reg* arg3_point;
    uint32_t arg2_int;
    uint32_t arg3_int;
    

    char charHelper;
    int index;

    std::string curr_line;
    while (getline (FILE, curr_line)){

        command = "";
        arg1 = "";
        arg2 = "";
        arg3 = "";
        index = -1;


        charHelper = curr_line.at (++index);
        while (charHelper != ' '){
            if (charHelper == '\n' || charHelper == EOF){
                std::cout << "FATAL ERROR: ARMFile::loadSourceFile could not comprehend line.... terminating" << std::endl;
                std::exit (-1);
            }
            if (charHelper != '\t'){
                command += charHelper;
            }
            charHelper = curr_line.at (++index);
        }
        
        // Get first argument
        charHelper = curr_line.at (++index);
        while (charHelper != ','){
            arg1 += charHelper;
            charHelper = curr_line.at (++index);
        }

        // get first register
        if (arg1.at (0) == 'r' || arg1.at (0) == 'R'){
            arg1_point = string2Reg (arg1);
        }



        // Parser for argument 2
        charHelper = curr_line.at (++index);
        while (charHelper != ',' && charHelper != '\n'){
            arg2 += charHelper;
            if (index == (curr_line.size () - 1)){
                break;
            }
            charHelper = curr_line.at (++index);
        }

        if (index != (curr_line.size () - 1)){
            // 3 arguments
            charHelper = curr_line.at (++index);

            // argument 3 parser
            for (;;){
                arg3 += charHelper;
                if (index == (curr_line.size () - 1)){
                    break;
                }
                charHelper = curr_line.at (++index);
            }
            if (arg2.at (0) == 'r' || arg2.at (0) == 'R'){
                // second argument is a register
                arg2_point = string2Reg (arg2);
                if (arg3.at (0) == 'r' || arg3.at (0) == 'R'){
                    // third argument is a register
                    arg3_point = string2Reg (arg3);
                    instruction x(command, arg1_point, arg2_point, arg3_point);
                    instructionVect.push_back (x);
                }
                else{
                    // third argument is a number
                    arg3_int = string2Num (arg3);

                    instruction x(command, arg1_point, arg2_point, arg3_int);
                    instructionVect.push_back (x);
                }
            }
            else{
                // second argument is a number
                arg2_int = string2Num (arg2);

                if (arg3.at (0) == 'r' || arg3.at (0) == 'R'){
                    // third argument is a register
                    arg3_point = string2Reg (arg3);

                    instruction x(command, arg1_point, arg2_int, arg3_point);
                    instructionVect.push_back (x);
                }
                else{
                    // third argument is a number
                    arg3_int = string2Num (arg3);

                    instruction x(command, arg1_point, arg2_int, arg3_int);
                    instructionVect.push_back (x);
                }
            }
        }
        else{
            // only 2 arguments

            // Is argument 2 a number or register
            if (arg2.at (0) == 'r' || arg2.at (0) == 'R'){
                // second argument is a register
                arg2_point = string2Reg (arg2);

                instruction x(command, arg1_point, arg2_point);
                instructionVect.push_back (x);
            }
            else{
                // second argument is a number
                arg2_int = string2Num (arg2);

                instruction x(command, arg1_point, arg2_int);
                instructionVect.push_back (x);
            }
        }
    }
}

void ARMFile::executeFile (){
    if (instructionVect.size () != 0){
        for (int i = 0; i < instructionVect.size (); i++){
            instructionVect.at (i).execute ();
        }
    }
    else{
        std::cout << "ERROR: ARMFile::executeFile could not find any instructions" << std::endl;
    }
}

reg* ARMFile::string2Reg (std::string R){

    switch (R.at (1)){
        case '0': return &r0;
        case '1': 
            if (R.size () == 2){
                return &r1;
            }
            else if (R.at (2) == '0'){
                return &r10;
            }
            else if (R.at (2) == '1'){
                return &r11;
            }
            else if (R.at (2) == '2'){
                return &r12;
            }
            else{
                std::cout << "ERROR: ARMFile::string2Reg could not find register ferernced... " << R << " exiting program" << std::endl;
                std::exit (-1);
            }
            break;
        case '2': return &r2;
        case '3': return &r3;
        case '4': return &r4;
        case '5': return &r5;
        case '6': return &r6;
        case '7': return &r7;
        case '8': return &r8;
        case '9': return &r9;
        case 'S':
            if (R.at (2) == 'P'){
                return &SP;
            }
            break;
        case 'L':
            if (R.at (2) == 'P'){
                return &LP;
            }
            break;
        case 'P':
            if (R.at (2) == 'C'){
                return &PC;
            }
            break;
        default:
            std::cout << "ERROR: ARMFile::string2Reg could not find register ferernced... " << R << " exiting program" << std::endl;
            std::exit (-1);
            break;
    }
}

uint32_t ARMFile::string2Num (std::string N){
    // TODO search for other types of number values
    std::string num_val = "";

    if (N.at (0) == '0' && N.at (1) == 'x'){
        num_val = N.substr (2, N.size () - 2);
        return stoi (num_val, 0, 16);
    }
    else if (N.at (0) == '#'){
        // Decimal value
        num_val = N.substr (1, N.size () - 1);
        return stoi (num_val);
    }
    else{
        std::cout << "ERROR: in ARMFile::string2Num, unknown Number type: " << N << std::endl;
    }
}