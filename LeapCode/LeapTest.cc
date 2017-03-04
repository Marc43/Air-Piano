#include <iostream>
#include <string.h>
#include "LeeMotion.hh"

int main(){
    LeeMotion leapMotion;
    while(not leapMotion.isConnected()){};
    while (1){
        leapMotion.updateFrame();
        
    }
}