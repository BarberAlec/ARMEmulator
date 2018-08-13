#include "register.h"

reg::reg (){

}


void reg::setMem (uint32_t val){
    mem = val;
}

uint32_t reg::getMem (){
    return mem;
}

void reg::setMemWithUpdate (uint32_t val){
    mem = val;

    if (isNeg ()){
        (*cond_flags) = (*cond_flags) | 0b00001000;             // Set N flag to high
    }
    else{
        (*cond_flags) = (*cond_flags) & 0b11110111;             // Set N flag to low
    }

    if (isZero()){
        (*cond_flags) = (*cond_flags) | 0b00000100;             // Set Z flag to high
    }
    else{
        (*cond_flags) = (*cond_flags) & 0b11111011;             // Set Z flag to low
    }

    /*if (isCarry ()){
        (*cond_flags) = (*cond_flags) | 0b00000010;             // Set C flag to high
    }
    else{
        (*cond_flags) = (*cond_flags) & 0b11111101;             // Set C flag to low
    }

    if (isOverFlow ()){
        (*cond_flags) = (*cond_flags) | 0b00000001;             // Set V flag to high
    }
    else{
        (*cond_flags) = (*cond_flags) & 0b11111110;             // Set V flag to low
    }*/

    // think it makes sense to do this in instruction
}

void reg::setCondFlags (uint8_t *ptr){
    cond_flags = ptr;
}

bool reg::isZero (){
    if (mem == 0x00000000){
        return true;
    }
    return false;
}

bool reg::isNeg (){
    if ((0x80000000 & mem) != 0x0){
        return true;
    }
    return false;
}
