#include <iostream>
#include <string.h>
#include <set>
#include <cmath>
#include "LeeMotion.hh"

int finger; int hand; int height;

int ObtainIDNoteActiveFinger(bool isRightHand, int fingerType, const Vector& h_position){
    map<int, musical_note_data> infoFinger = ;
    map<int, musical_note_data>::const_iterator it = infoFinger.begin();
    bool idFound = false;
    int idValue = -1;
    while(!idFound && it != infoFinger.end()){
        if (it->second.hand == isRightHand && it->second.finger == fingerType && it->second){
            idValue = it->first;
            idFound = true;
        }
        it++;
    }
    return idValue;
}

bool IsFingerPositionActive(const Vector& fingerDirection, const Vector& handNormalDirection){
    float angle = (180 * fingerDirection.angleTo(handNormalDirection))/PI;
    return angle <= 60;
}

set<int> ConvertDataToNote(const vector<DataToTreat>& leapMotionData, const set<int>& notesToReproduceAnterior){
    set<int> ActiveFingers;
    for (int i = 0; i < leapMotionData.size(); i++){
        DataToTreat handInformation = leapMotionData[i];
        if (handInformation.h_id != -1){
            for (int j = 0; j < handInformation.ftype.size(); j++){
                if (IsFingerPositionActive(handInformation.ftype[j].second, handInformation.h_normal)){
                    bool isRightHand = handInformation.right;
                    int fingerType = handInformation.ftype.first;
                    int h_position = h_position.y;
                    int id_note = ObtainIDActiveFinger(isRightHand, fingerType, h_position);
                    if (notesToReproduceAnterior.find(id_note) == notesToReproduceAnterior.end()){
                        ActiveFingers.insert(id_note);
                    }
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

vector<DataToTreat> ConvertPairToVector (const pair<DataToTreat, DataToTreat> data) {
    vector <DataToTreat> dtt(2);
    dtt [0] = data.first;
    dtt [1] = data.second;

    return dtt;
}

int main(){
    LeeMotion leapMotion;
    pair<DataToTreat, DataToTreat> data; //Respectively, LEFT AND RIGHT.
    while(!leapMotion.isConnected()){};
    set<int> notesToReproduce;
    set<int> notesToReproduceAnterior;

    while (1){
        notesToReproduceAnterior = notesToReproduce;
        leapMotion.updateFrame();
        GetNewStruct(leapMotion, data);
        vector<DataToTreat> leapMotionData = ConvertPairToVector(data);
        notesToReproduce = ConvertDataToNote(leapMotionData, notesToReproduceAnterior);
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