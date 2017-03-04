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
    int h_id; //Hand id (if -1, does not exist)
    bool right; //Type of hand (true Right, false Left)
    vector<pair <int, Vector> > ftype; //Type of finger and vector pointing out of the finger
    Vector h_position; //Hand position...
    Vector h_normal; //Normal vector of the palm
};

class LeeMotion {
    
    private:
        
        Controller lpm; //LeapMotion
        Frame act;  //Actual Frame 
        
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
        
        HandList getHands ();
        /* Get the hands in frame */
        
        Vector getHandNormal (const Hand &hand);
        /* Get the normal of a given hand */
        
};

#endif