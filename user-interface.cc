#include "user-interface.h"
/**
 * TODO:
 *      Implement OS check so this works on wndows or MAC;
 **/

ARMEmulatorUserInterface::ARMEmulatorUserInterface (){
    std::cerr<<"BOOTING ARMEULATOR";
    std::cout<<std::endl;
}


void ARMEmulatorUserInterface::start (){
    std::string input_string;
    char input_char;

    std::cout << "Thanks for using ARMEmulator, the ARM Interpreter" << std::endl;
    std::cout << "\t\tWould you like to start with examples.txt? [y/n]: ";
    std::cin >> input_char;
    std::cout << std::endl;


    if (input_char == 'y' || input_char == 'Y'){
        fileName = "example.txt";
        
    }
    else if (input_char == 'n' || input_char == 'N'){

        bool goodFileName = false;
        while (!goodFileName){
            std::cout << "\t\tPlease enter the name of the ARME file you wish to open, or the name for a new ARME file: ";
            std::cin >> input_string;
            std::cout << std::endl;
            if (checkStr4Spaces (input_string)){
                std::cout << "\t\tError: ARME file cannot have spaces in the name" << std::endl;
                goodFileName = false;
            }
            else{
                goodFileName = true;
            }
        }
        fileName = input_string;
        std::fstream newFile;
    }
    else{
        std::cout << "Error, " << input_char << " not recognized, exiting program..." << std::endl;
        exit (-1);
    }
    std::string fileOpener = "gedit " + fileName;
    std::system (fileOpener.c_str ());

    input_char = 0;
    while (!(input_char == 'Y' || input_char == 'y')){
        std::cout << "\t\tWhen Ready enter [y] to run Interpreter: ";
        std::cin >> input_char;
        std::cout << std::endl;
    }

    aFile.addSourceFile (fileName);
    aFile.loadSourceFile ();
    aFile.executeFile ();
    aFile.printRegistersHex ();
    aFile.closeSourceFile ();

}


bool ARMEmulatorUserInterface::checkStr4Spaces (std::string str){

    for (int i = 0; i < str.size (); i++){
        if (str.at (i) == ' '){
            return true;
        }
    }
    return false;
}

