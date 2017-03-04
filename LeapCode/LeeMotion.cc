#include "LeeMotion.hh"

LeeMotion::LeeMotion () {
    Controller lpm;
    this->lpm = lpm; //lEApmOTION
    Frame act;
    this->act = act; //Null instance (we have to wait until the asynchronous connexion is done...)
}

Frame LeeMotion::updateFrame () {
    act = lpm.frame();
    
    return act;
}

bool LeeMotion::isConnected () {
    return lpm.isConnected();
}

FingerList LeeMotion::getFingers (const Hand &hand) {
    return hand.fingers();
}

Vector LeeMotion::getFingerDirection (const Finger &finger) {
    Vector vector;
    return vector;
}

list<Hand> LeeMotion::getHands () {
    list<Hand> lh;
    return lh;
}

Vector LeeMotion::getHandNormal (const Hand &hand) {
    Vector vector;
    return vector;
}

Vector LeeMotion::directionHand() {
        HandList hands = act.hands();
        Hand hand;
        for (Leap::HandList::const_iterator hl = hands.begin(); hl != hands.end(); hl++) hand = *hl;
        Vector dir = hand.direction();
        
        return dir;
}

        
    