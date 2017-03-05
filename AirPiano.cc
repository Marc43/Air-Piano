#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <iterator>
#include <string>
#include <string.h>
#include <set>
#include <cstring>
#include <cmath>
#include "LeeMotion.hh"
#include "Reproduce_music.hh"

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

map<int, musical_note_data> read_data_from_txt(string path_to_read) {
    map<int, musical_note_data> data_map;
    std::ifstream input(path_to_read); //put your program together with thsi file in the same folder.
    if(input.is_open()){
        while(!input.eof()){
            string data;
            getline(input,data);
            vector<string> splitted_data = split(data, ';'); //convert to integer
            musical_note_data aux;
            aux.finger = atoi(splitted_data[1].c_str());
            aux.hand = atoi(splitted_data[2].c_str());
            aux.height = atoi(splitted_data[3].c_str());
            char* chr = strdup(splitted_data[4].c_str());
            aux.route = chr;
            free(chr);
            data_map[atoi(splitted_data[0].c_str())] = aux;
       }
    }
    return data_map;
}

int ObtainIDNoteActiveFinger(bool isRightHand, int fingerType, const Vector& h_position, const map<int, musical_note_data>& infoFinger){
    map<int, musical_note_data>::const_iterator it = infoFinger.begin();
    bool idFound = false;
    int idValue = -1;
    while(!idFound && it != infoFinger.end()){
        if (it->second.hand == isRightHand && it->second.finger == fingerType && it->second.height){
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

set<int> ConvertDataToNote(const vector<DataToTreat>& leapMotionData, const set<int>& notesToReproduceAnterior, const map<int, musical_note_data>& infoFinger){
    set<int> ActiveFingers;
    for (int i = 0; i < leapMotionData.size(); i++){
        DataToTreat handInformation = leapMotionData[i];
        if (handInformation.h_id != -1){
            for (int j = 0; j < handInformation.ftype.size(); j++){
                if (IsFingerPositionActive(handInformation.ftype[j].second, handInformation.h_normal)){
                    bool isRightHand = handInformation.right;
                    int fingerType = handInformation.ftype[j].first;
                    Vector h_position = handInformation.h_position;
                    int id_note = ObtainIDNoteActiveFinger(isRightHand, fingerType, h_position, infoFinger);
                    if (notesToReproduceAnterior.find(id_note) == notesToReproduceAnterior.end()){
                        ActiveFingers.insert(id_note);
                    }
                }
            }
        }
    }
    return ActiveFingers;
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
    map<int, musical_note_data> note_data = read_data_from_txt("DB_sounds.txt");
    LeeMotion leapMotion;
    Reproduce_music music_player(note_data);
    pair<DataToTreat, DataToTreat> data; //Respectively, LEFT AND RIGHT.
    while(!leapMotion.isConnected()){};
    set<int> notesToReproduce;
    set<int> notesToReproduceAnterior;

    while (1){
        notesToReproduceAnterior = notesToReproduce;
        leapMotion.updateFrame();
        GetNewStruct(leapMotion, data);
        vector<DataToTreat> leapMotionData = ConvertPairToVector(data);
        notesToReproduce = ConvertDataToNote(leapMotionData, notesToReproduceAnterior, note_data);
        music_player.update_musical_notes(notesToReproduce);
        music_player.play_musical_notes();
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
