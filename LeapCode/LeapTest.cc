#include <iostream>
#include <string.h>
#include "LeeMotion.hh"

int main(){
    LeeMotion leapMotion;
    pair<DataToTreat, DataToTreat> data; //Respectively, LEFT AND RIGHT.
    while(not leapMotion.isConnected()){};
    while (1){
        leapMotion.updateFrame();
        HandList hl = leapMotion.getHands();
        if (hl.begin() != hl.end()) {
            Hand rh = hl.rightmost();
            Hand lh = hl.leftmost();
            data.first.h_id = lh.id();
            data.second.h_id = rh.id(); //ID's of both hands...
            data.first.right = false;
            data.first.right = true; //bool right
            FingerList left_fl = leapMotion.getFingers(lh);
            FingerList right_fl = leapMotion.getFingers(rh);
            FingerList::const_iterator it1 = left_fl.begin();
            FingerList::const_iterator it2 = right_fl.begin();
            
            int i = 0;
            while (it1 != left_fl.end() and i < 5) {
                Finger f = *it1;
                pair<int, Vector> to_push;
                to_push.first = f.type();
                to_push.second = leapMotion.getFingerDirection(f);
                data.first.ftype.push_back(to_push);
                ++i; ++it1;
            }
            
            i = 0;
            while (it2 != right_fl.end() and i < 5) {
                Finger f = *it2;
                pair<int, Vector> to_push;
                to_push.first = f.type();
                to_push.second = leapMotion.getFingerDirection(f);
                data.second.ftype.push_back(to_push);;
                ++i; ++it2;
            }
            
            data.first.h_position = lh.palmPosition();
            data.second.h_position = rh.palmPosition();
            
            data.first.h_normal = lh.palmNormal();
            data.second.h_normal = rh.palmNormal();
            
            
        }
    }
}


          /*  HandList::const_iterator it = hl.begin();
            FingerList fl = leapMotion.getFingers(*it);
            FingerList::const_iterator cit = fl.begin();
            Vector v = leapMotion.getFingerDirection(*cit);
//             cout << "x: " << v.x << " y: " << v.y << " z: " << v.z << endl;
            Vector pos = (*it).palmPosition();
            cout << "x: " << pos.x << " y: " << pos.y << " z: " << pos.z << endl;*/