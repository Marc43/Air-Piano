#include "LeeMotion.hh"

int main(){
    while (1){
        LeeMotion leapMotion;
        while(!leapMotion.isConnected()){};
        leapMotion.updateFrame();
        cout << "COORDENADAS XYZ: " << endl;
        cout << leapMotion.directionHand().x << endl;
        cout << leapMotion.directionHand().y << endl;
        cout << leapMotion.directionHand().z << endl;
    }
}
