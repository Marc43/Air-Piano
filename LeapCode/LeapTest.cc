#include <iostream>
#include <string.h>
#include "LeeMotion.hh"

int main(){
    while (1){
        LeeMotion leapMotion;
        while(not leapMotion.isConnected()){};
        Frame frame = leapMotion.updateFrame();
        cout << "Frame id: " << frame.id()
          << ", timestamp: " << frame.timestamp()
          << ", hands: " << frame.hands().count()
          << ", fingers: " << frame.fingers().count();
        /*cout << "COORDENADAS XYZ: " << endl;
        cout << leapMotion.directionHand().x << endl;
        cout << leapMotion.directionHand().y << endl;
        cout << leapMotion.directionHand().z << endl;*/
    }
}