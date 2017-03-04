#include <iostream>
#include <vector>
#include <map>
#include "Leap.h"
using namespace Leap;

LeeMotion::LeeMotion (Controller lpm) {
    this->lpm = lpm;
    act = lpm.frame(); //We get the latest frame of lpm (leapmotion controller)...
}

bool::updateFrame () {
    if (lpm.isConnected()) {act = lpm.frame(); return true;}
    return false;
}

FingerList::getFingers (const Hand &hand) {
    return hand.fingers();
}

Vector::getFingerDirection (const Finger &finger) {
    
}

List<Hand>::getHands () {
    
}

Vector::getHandNormal (const Hand &hand) {
    
}

        
// //         LeeMotion(Controller lpm);
// //         /*Constructor...*/
// //         
// //         bool updateFrame();
// //         /* Updates this->act to the 
// //            real actual frame     */
//         
//         List<Finger> getFingers(const Hand &hand);
//         /* Get the fingers of a given hand */
        
        Vector getFingerDirection(const Finger &finger);
        /* Get the direction of a given finger */
        
        List<Hand> getHands();
        /* Get the hands in frame */
        
        Vector getHandNormal(const Hand &hand);
        /* Get the normal of a given hand */
        
        
        
        
        
