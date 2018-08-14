#include "ARM-file.h"
#include <unistd.h>
#include <ctime>
/**
 * 
 * 
 * Over arching Control Class 
 * 
 *  Overall todo list:
 *  > Implement most common instructions                                                X
 *  > Implement add on bit at end of instruction (like roate shift etc.)
 *  > Implement PC accurately
 *  > implement basic B branchs and labels
 *  > implement non register memory and insturctions to access it
 *  
 * 
 **/



class emulator{
public:
    emulator ();


    
private:

    ARMFile aFile;
};



int main (){
    std::cerr<<"BOOTING ARMEULATOR";
    /*
    for (int i = 0; i < 2000000000; i++){
        if (i%300000691 == 0){
            std::cerr<<".";
        }

    }*/
    std::cout<<std::endl;

    ARMFile aFile;
    aFile.addSourceFile ("example.txt");
    aFile.loadSourceFile ();

    aFile.executeFile ();

    aFile.printRegistersHex ();

    aFile.closeSourceFile ();
    return 0;
}