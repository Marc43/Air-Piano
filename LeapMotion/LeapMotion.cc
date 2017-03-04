#include <iostream>
#include "Leap.h"
#include <vector>
#include <map>

using namespace Leap;

class LeapMotion {
    private:
        Controller dispositivo;
        vector<Finger>

    public:
        virtual void onConnect(const Controller&);
        virtual void onDisconnect(const Controller&);
        virtual void onFrame(const Controller&);
};

void LeapEventListener::onConnect(const Controller& controller) {
    std::cout << "Connected" << std::endl;
    // Enable gestures, set Config values:
    controller.enableGesture(Gesture::TYPE_SWIPE);
    controller.config().setFloat("Gesture.Swipe.MinLength", 200.0);
    controller.config().save();
}

//Not dispatched when running in a debugger
void LeapEventListener::onDisconnect(const Controller& controller) {
    std::cout << "Disconnected" << std::endl;
}

void LeapEventListener::onFrame(const Controller& controller) {
    std::cout << "New frame available" << std::endl;
    Frame frame = controller.frame();
    // Process this frame's data...
}
