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