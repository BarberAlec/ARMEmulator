#include "ARM-file.h"
#include <unistd.h>
#include <ctime>
/**
 * 
 * 
 * Over arching Control Class 
 * 
 *
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
    aFile.printRegisters ();
    aFile.executeFile ();
    aFile.printRegisters ();
    return 0;
}