#include <iostream>
#include <string.h>
#include <set>
#include <cmath>
#include "LeeMotion.hh"

struct DataToTreat {
    int h_id; //Hand id (if -1, does not exist)
    bool right; //Type of hand (true Right, false Left)
    vector<pair <int, Vector> > ftype; //Type of finger and vector pointing out of the finger
    Vector h_position; //Hand position...
    Vector h_normal; //Normal vector of the palm
};

int ObtainIDNoteActiveFinger(bool isRightHand, int fingerType, const Vector& h_position){
    //if ()
    return 1;
}

bool IsFingerPositionActive(const Vector& fingerDirection, const Vector& handNormalDirection){
    float angle = (180 * fingerDirection.AngleTo(VhandNormalDirection))/PI;
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

int main(){
    LeeMotion leapMotion;
    pair<DataToTreat, DataToTreat> data; //Respectively, LEFT AND RIGHT.
    while(not leapMotion.isConnected()){};
    while (1){
        HandList::const_iterator it = hl.begin();
        FingerList fl = leapMotion.getFingers(*it);
        FingerList::const_iterator cit = fl.begin();
        Vector v = leapMotion.getFingerDirection(*cit);
//             cout << "x: " << v.x << " y: " << v.y << " z: " << v.z << endl;
        Vector pos = (*it).palmPosition();
        cout << "x: " << pos.x << " y: " << pos.y << " z: " << pos.z << endl;*/

    /*LeeMotion leapMotion;
    while(not leapMotion.isConnected()){};
    while (1){
        leapMotion.updateFrame();
        //Llammar funcion obtener datos leapMotion
        //set<int> notesToReproduce = ConvertDataToNote(leapMotionData);

    }*/
}
