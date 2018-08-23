#include "user-interface.h"
/**
 * TODO:
 *      Implement OS check so this works on wndows or MAC;
 **/

ARMEmulatorUserInterface::ARMEmulatorUserInterface (){
    printRegsAfterEachInstruct = false;
    std::cerr<<"BOOTING ARMEULATOR";
    std::cout<<std::endl;
}


void ARMEmulatorUserInterface::start (){
    std::string input_string;
    char input_char;

    std::cout << "Thanks for using ARMEmulator, the ARM Interpreter" << std::endl;
    std::cout << "\tWould you like to start with examples.txt? [y/n]: ";
    std::cin >> input_char;
    std::cout << std::endl;


    if (input_char == 'y' || input_char == 'Y'){
        fileName = "example.txt";
        
    }
    else if (input_char == 'n' || input_char == 'N'){

        bool goodFileName = false;
        while (!goodFileName){
            std::cout << "\tPlease enter the name of the ARME file you wish to open, or the name for a new ARME file: ";
            std::cin >> input_string;
            std::cout << std::endl;
            if (checkStr4Spaces (input_string)){
                std::cout << "\tError: ARME file cannot have spaces in the name" << std::endl;
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

    std::cout << "\tWould you like to edit the debugger settings? [y/n]: ";
    std::cin >> input_char;
    std::cout << std::endl;

    if (input_char == 'y' || input_char == 'Y'){
        promptUser4DebugSett ();
    }
    else if (input_char == 'n' || input_char == 'N'){
        // Nothing I guess
    }
    else{
        std::cout << "\tError: Unknown response " << input_char << "continueing without debuging..." << std::endl;
    }


    input_char = 0;
    while (!(input_char == 'Y' || input_char == 'y')){
        std::cout << "\tWhen Ready enter [y] to run Interpreter: ";
        std::cin >> input_char;
        std::cout << std::endl;
    }

    aFile.addSourceFile (fileName);
    aFile.loadSourceFile ();
    if (printRegsAfterEachInstruct){
        aFile.executeFile ();
    }
    else{
        aFile.executeFile ();           //TODO: Implement debugging
    }
    aFile.printRegistersHex ();
    aFile.closeSourceFile ();

}

void ARMEmulatorUserInterface::promptUser4DebugSett (){
    char input_char;
    std::cout << "\t\tEntering Debug settings..." << std::endl << std::endl;
    std::cout << "\t\tWould you like to print Register Values after every Instruction [y/n]: ";
    std::cin >> input_char;

    if (input_char == 'y' || input_char == 'Y'){
        printRegsAfterEachInstruct = true;
    }
    else if (input_char == 'n' || input_char == 'N'){
        printRegsAfterEachInstruct = false;
    }
    else{
        std::cout << "\t\tError: Unknown response " << input_char << "continueing without debuging..." << std::endl;
    }
}

bool ARMEmulatorUserInterface::checkStr4Spaces (std::string str){

    for (uint32_t i = 0; i < str.size (); i++){
        if (str.at (i) == ' '){
            return true;
        }
    }
    return false;
}

