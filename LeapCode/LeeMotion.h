#include <iostream>
#include <vector>
#include <map>
#include "Leap.h"
using namespace Leap;

class LeeMotion {
    private:
        
        Controller lpm; //LeapMotion
        Frame act;  //Actual Frame
    public:
        
        bool uFrame();
        /* Updates this->act to the 
           real actual frame     */
        
        
};