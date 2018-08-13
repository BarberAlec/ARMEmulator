#include "ARM-file.h"


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

void ARMFile::printRegisters (){
    std::cout << "_____________________________________" << std::endl;

    std::cout << "|   r0   |   r1   |   r2   |   r3   |" << std::endl;
    std::cout << "|" << std::bitset<8> (r0.getMem ()) << "|" << std::bitset<8> (r1.getMem ()) << "|" << std::bitset<8> (r2.getMem ()) << "|" 
                << std::bitset<8> (r3.getMem ()) << "|" << std::endl;

    std::cout << "-------------------------------------" << std::endl;
    std::cout << "_____________________________________" << std::endl;

    std::cout << "|   r4   |   r5   |   r6   |   r7   |" << std::endl;
    std::cout << "|" << std::bitset<8> (r4.getMem ()) << "|" << std::bitset<8> (r5.getMem ()) << "|" << std::bitset<8> (r6.getMem ()) << "|" 
                << std::bitset<8> (r7.getMem ()) << "|" << std::endl;

    std::cout << "-------------------------------------" << std::endl;
    std::cout << "_____________________________________" << std::endl;
    
    std::cout << "|   r8   |   r9   |   r10  |   r11  |" << std::endl;
    std::cout << "|" << std::bitset<8> (r8.getMem ()) << "|" << std::bitset<8> (r9.getMem ()) << "|" << std::bitset<8> (r10.getMem ()) << "|" 
                << std::bitset<8> (r11.getMem ()) << "|" <<std::endl;

    std::cout << "-------------------------------------" << std::endl;
    std::cout << "_____________________________________" << std::endl;
    
    std::cout << "|   r12  |   SP   |   LC   |   PC   |" << std::endl;
    std::cout << "|" << std::bitset<8> (r12.getMem ()) << "|" << std::bitset<8> (SP.getMem ()) << "|" << std::bitset<8> (LP.getMem ()) << "|" 
                << std::bitset<8> (PC.getMem ()) << "|" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}

void ARMFile::loadSourceFile (){
    // TODO assert file has been loaded
    std::string command;
    std::string arg1;
    std::string arg2 = "";
    std::string arg3 = "";
    char charHelper;
    int index;

    std::string curr_line;

    while (getline (FILE, curr_line)){

        command = curr_line.substr (0, 3);
        arg1 = curr_line.substr (4, 2);

        index = 5;
        charHelper = curr_line.at (index++);

        while (charHelper != ',' && charHelper != '\n'){
            arg2 += charHelper;
            charHelper = curr_line.at (index++);
        }

        if (charHelper != '\n'){

            charHelper = curr_line.at (index++);
            while (charHelper != '\n'){
                arg3 += charHelper;
                charHelper = curr_line.at (index++);
            }
        }
        else{
            instruction x(command, arg1, arg2);
            instructionVect.push_back (x);
        }
    }
}

void ARMFile::executeFile (){

}