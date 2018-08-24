#include "ARM-file.h"
#include <unistd.h>
#include <ctime>
#include <cstdlib>

/**
 * 
 * 
 * User interface helper class
 * 
 * Main function at bottom of file.
 * 
 *  Overall todo list:
 *  > Implement most common instructions                                                X
 *  > Implement add on bit at end of instruction (like roate shift etc.)
 *  > Implement Comments with ;
 *  > Implement PC accurately                                                           X
 *  > implement basic B branchs and labels                                              X
 *  > implement non register memory and insturctions to access it
 *  > condition flags                                                                   X
 *  > s feature on instructions so as to update flags                                   X
 *  > CMP (finally)                                                                     X
 *  
 * 
 **/



class ARMEmulatorUserInterface{
public:
    ARMEmulatorUserInterface ();

    void start ();

    
private:
    
    void promptUser4DebugSett ();


    bool checkStr4Spaces (std::string str);

    ARMFile aFile;
    std::string fileName;


    bool printRegsAfterEachInstruct;    // defulat to false
    bool resetCPSRAfterEachIter;        // defulat to true (just makes life easier)
    bool printInstructAsExecuted;
};



int main (){
    ARMEmulatorUserInterface interface;
    interface.start ();
    return 0;
}