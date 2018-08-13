#include "string"
#include <iostream>

bool stringCompare(std::string a, std::string b){
    if(a.size() != b.size()){
        return false;
    }
    for (std::string::const_iterator c1 = a.begin(), c2 = b.begin(); c1 != a.end(); ++c1, ++c2) {
        if (tolower(*c1) != tolower(*c2)) {
            return false;
        }
    }
    return true;
}

void ASSERT(bool argument, std::string msg){
    if (!argument){
        std::cout << "ASSERT FAIL, Message: " << msg << std::endl;
        std::exit(EXIT_FAILURE);
    }
}