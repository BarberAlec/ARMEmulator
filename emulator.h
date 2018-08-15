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
 *  > Implement Comments with ;
 *  > Implement PC accurately                                                           X
 *  > implement basic B branchs and labels                                              X
 *  > implement non register memory and insturctions to access it
 *  > condition flags                                                                   X
 *  > s feature on instructions so as to update flags
 *  > CMP (finally)                                                                     X
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