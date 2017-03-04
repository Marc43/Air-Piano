#include <iostream>
#include "Leap.h"
#include <vector>
#include <map>

using namespace Leap;

class LeapMotion {
    private:
        Controller controller;
        Frame scene;

    public:
        //Constructores
        LeapMotion();

        //Destructores
        ~LeapMotion();

        //Consultores

        bool Is_connected();

        vector<int> Direction_hand(Hand hand);

        vector<vector<int>> Direction_fingers(Hand hand);

        //Modificadores
        void Update_frame();
};
