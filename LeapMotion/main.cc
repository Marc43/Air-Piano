#include <iostream>
#include <vector>
#include "Leap.h"
#include "LeapMotion.hh"

using namespace std;
using namespace Leap;

int main(){
    while (1){
        LeapMotion leapMotion;
        while(!leapMotion.Is_connected()){};
        leapMotion.Update_frame();
        Hand hand;
        cout << leapMotion.Direction_hand(hand)[0] << endl;
    }
}
