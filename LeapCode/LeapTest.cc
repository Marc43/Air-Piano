#include <iostream>
#include <string.h>
#include <set>
#include <cmath>
#include "LeeMotion.hh"

int ObtainIDNoteActiveFinger(bool isRightHand, int fingerType, const Vector& h_position){
    //if ()
    return 1;
}

bool IsFingerPositionActive(const Vector& fingerDirection, const Vector& handNormalDirection){
    float angle = (180 * fingerDirection.angleTo(handNormalDirection))/PI;
    return angle <= 60;
}

set<int> ConvertDataToNote(const vector<DataToTreat>& leapMotionData){
    set<int> ActiveFingers;
    for (int i = 0; i < leapMotionData.size(); i++){
        DataToTreat handInformation = leapMotionData[i];
        if (handInformation.h_id != -1){
            for (int j = 0; j < handInformation.ftype.size(); j++){
                if (IsFingerPositionActive(handInformation.ftype[j].second, handInformation.h_normal)){
                    //ObtainIDActiveFinger();
                }
            }
        }
    }
}

void GetNewStruct (LeeMotion &leapMotion, pair<DataToTreat, DataToTreat> &data) {
    HandList hl = leapMotion.getHands();
    data.first.h_id = data.second.h_id = -1; //In first case, does not exist or is not valid...
    if (hl.begin() != hl.end()) {
        HandList::const_iterator hdit = hl.begin();
        Hand lh, rh;
        while (hdit != hl.end()) {
            if ((*hdit).isLeft()) {
                lh = *hdit;
                data.first.h_id = lh.id();
                data.first.right = false;
            }
            else {
                rh = *hdit;
                data.second.h_id = rh.id();
                data.second.right = true;
            }
            ++hdit;
        }
        cout << "valido? " << lh.isValid() << ' ' << "valido?" << rh.isValid() << endl; 
        FingerList left_fl = leapMotion.getFingers(lh);
        FingerList right_fl = leapMotion.getFingers(rh);
        FingerList::const_iterator it1 = left_fl.begin();
        FingerList::const_iterator it2 = right_fl.begin();
        cout << "id: " << lh.id() << ' ' << rh.id() << endl;
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
        
        Vector mi = data.first.h_position;
        Vector md = data.second.h_position;
        cout << "Mano Izquierda: " << mi.x << ' ' << mi.y << ' ' << mi.z << endl;
        cout << "Mano Derecha: " << md.x << ' ' << md.y << ' ' << md.z << endl;
        
    }
}

int main(){
    LeeMotion leapMotion;
    pair<DataToTreat, DataToTreat> data; //Respectively, LEFT AND RIGHT.
    while(not leapMotion.isConnected()){};
    while (1){
        leapMotion.updateFrame();
        GetNewStruct(leapMotion, data);
        vector<DataToTreat> leapMotionData = ConvertPairToVector(data);
        set<int> notesToReproduce = ConvertDataToNote(leapMotionData);
    }
}

/*while(not leapMotion.isConnected()){};
    while (1){
        leapMotion.updateFrame();
        HandList hl = leapMotion.getHands();
        HandList::const_iterator it = hl.begin();
        FingerList fl = leapMotion.getFingers(*it);
        FingerList::const_iterator cit = fl.begin();
        Vector v = leapMotion.getFingerDirection(*cit);
        //cout << "x: " << v.x << " y: " << v.y << " z: " << v.z << endl;
        Vector pos = (*it).palmPosition();
        cout << "x: " << pos.x << " y: " << pos.y << " z: " << pos.z << endl;
}*/ 