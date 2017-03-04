#include "LeapMotion.hh"
using namespace Leap;


    LeapMotion::LeapMotion(){
        Controller conexion;
        controller = conexion;
    }

    //Destructores
    LeapMotion::~LeapMotion(){};

    //Consultores

    bool LeapMotion::Is_connected(){
        return controller.isConnected();
    }



    vector<int> LeapMotion::Direction_hand(Hand hand){
        HandList hands = scene.hands();
        Hand hand;
        for (Leap::HandList::const_iterator hl = hands.begin(); hl != hands.end(); hl++){
            hand = *h1;
        }
        vector <int> v = vector<int>(3,0);
        v[0] = hand.x;
        v[1] = hand.y;
        v[2] = hand.z;
        return v;

    }

    vector<vector<int>> LeapMotion::Direction_fingers(Hand hand){

    }

    //Modificadores
    void Update_frame(){
        scene = controller.frame();
    }
};
