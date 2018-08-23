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

    void printOptions2User ();

    bool checkStr4Spaces (std::string str);

    ARMFile aFile;
    std::string fileName;
};



int main (){
    ARMEmulatorUserInterface interface;
    interface.start ();

    /*std::cerr<<"BOOTING ARMEULATOR";
    std::cout<<std::endl;

    ARMFile aFile;
    aFile.addSourceFile ("example.txt");
    aFile.loadSourceFile ();

    aFile.executeFile ();

    aFile.printRegistersHex ();

    aFile.closeSourceFile ();*/
    return 0;
}