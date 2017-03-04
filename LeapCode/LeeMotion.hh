#ifndef TIME_H
#define TIME_H

class LeeMotion {
    private:
        
        Controller lpm; //LeapMotion
        Frame act;  //Actual Frame
        
    public:
        
        LeeMotion (Controller lpm);
        /*Constructor...*/
        
        bool updateFrame ();
        /* Updates this->act to the 
           real actual frame     */
        
        FingerList getFingers (const Hand &hand);
        /* Get the fingers of a given hand */
        
        Vector getFingerDirection (const Finger &finger);
        /* Get the direction of a given finger */
        
        List<Hand> getHands ();
        /* Get the hands in frame */
        
        Vector getHandNormal (const Hand &hand);
        /* Get the normal of a given hand */
        
        
        
        
};

#endif