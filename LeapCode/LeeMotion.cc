#include "LeeMotion.hh"

LeeMotion::LeeMotion () {
    Controller lpm;
    this->lpm = lpm; //lEApmOTION
    Frame act;
    this->act = act; //Null instance (we have to wait until the asynchronous connexion is done...)
}

void LeeMotion::updateFrame () {
    act = lpm.frame(); //We get the actual LPM Frame
}

bool LeeMotion::isConnected () {
    return lpm.isConnected(); //If the asynchronous connection is done, true, otherwise, false
}

FingerList LeeMotion::getFingers (const Hand &hand) {
    return hand.fingers(); //We get the FingerList
}

Vector LeeMotion::getFingerDirection (const Finger &finger) {
    Bone b = finger.bone(Leap::Bone::TYPE_DISTAL); //Returns the finger direction associated to the finger bone
    return b.direction();
}

HandList LeeMotion::getHands () {
    HandList hl = act.hands(); //We get the HandList
    return hl;
}

Vector LeeMotion::getHandNormal (const Hand &hand) {
    return hand.palmNormal(); //The Normal of the hand
}
