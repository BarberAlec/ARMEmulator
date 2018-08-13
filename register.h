//#include "useful-functions.h"
#include <string>
/**
 * 
 * 
 * 
 * 
 **/

class reg{
public:
    reg ();

    void setMem (uint32_t val);

    void setMemWithUpdate (uint32_t val);

    uint32_t getMem ();

    void setCondFlags (uint8_t *ptr);

private:

    bool isZero ();

    bool isNeg ();

    //bool isCarry ();

    //bool isOverFlow ();


    uint32_t mem;

    uint8_t *cond_flags;
};
