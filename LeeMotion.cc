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
    return b.nextJoint();
    //return b.direction();

}

HandList LeeMotion::getHands () {
    HandList hl = act.hands();
    return hl;
}

Vector LeeMotion::getHandNormal (const Hand &hand) {
    //return hand.direction();
    //Vector v = hand.palmPosition();
    //v.y = -v.y;
    //return v;
    //return hand.palmNormal();
    //return hand.direction();

    FingerList f = hand.fingers();
    FingerList::const_iterator cit = f.begin();

    return (*cit).bone(Leap::Bone::TYPE_DISTAL).nextJoint();
    //return hand.palmPosition();
}

Vector LeeMotion::getHandDirection (const Hand &hand) {
    //return hand.direction();
    //Vector v = hand.palmPosition();
    //v.y = -v.y;
    //return v;
    return hand.direction();
}
