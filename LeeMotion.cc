#include "LeeMotion.hh"

LeeMotion::LeeMotion () {
    Controller lpm;
    this->lpm = lpm; //lEApmOTION
    Frame act;
    this->act = act; //Null instance (we have to wait until the asynchronous connexion is done...)
}

void LeeMotion::updateFrame () {
    act = lpm.frame();
}

bool LeeMotion::isConnected () {
    return lpm.isConnected();
}

FingerList LeeMotion::getFingers (const Hand &hand) {
    return hand.fingers();
}

Vector LeeMotion::getFingerDirection (const Finger &finger) {
    Bone b = finger.bone(Leap::Bone::TYPE_DISTAL);
    return b.direction();
}

HandList LeeMotion::getHands () {
    HandList hl = act.hands();
    return hl;
}

Vector LeeMotion::getHandNormal (const Hand &hand) {
    return hand.palmNormal();
}