#ifndef LEEMOTION_H
#define LEEMOTION_H

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include "Leap.h"

using namespace std;
using namespace Leap;

struct DataToTreat {
    int f_id; //Hand id
    int ftype; //Type of finger
    float height; //Hand height
    Vector h_normal; //Normal vector of the palm
    Vector f_normal; //Vector pointing out of the finger
};

class LeeMotion {
    
    private:
        
        Controller lpm; //LeapMotion
        Frame act;  //Actual Frame 
        pair<DataToTreat, DataToTreat> hands;

        
    public:
        
        LeeMotion ();
        /*Constructor...*/
        
        void updateFrame ();
        /* Updates this->act to the 
           real actual frame     */
        
        bool isConnected ();
        /* true if LM is connected, otherwise, false */
        
        FingerList getFingers (const Hand &hand);
        /* Get the fingers of a given hand */
        
        Vector getFingerDirection (const Finger &finger);
        /* Get the direction of a given finger */
        
        list<Hand> getHands ();
        /* Get the hands in frame */
        
        Vector getHandNormal (const Hand &hand);
        /* Get the normal of a given hand */
        
        Vector directionHand();
        
        
};

#endif