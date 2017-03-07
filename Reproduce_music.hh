#include "Headers/fmod.hpp"
#include "Headers/fmod_errors.h"
#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;

//Struct used to store the data obtained by our "Database" (.txt)
struct musical_note_data {
    char * route; int finger; int hand; int height;
};
class Reproduce_music {
private:
  //set that contains the next notes to play. The ints stored are ids associated to the real notes.
  set<int> actual_notes;
  
  //map that contains different information about the notes (id, path, etc)
  map<int, musical_note_data> musical_note_map;

  //FMOD variables.  
  FMOD::System       *system;
  FMOD::Sound        *sound[32];
  FMOD_RESULT         result;
  unsigned int        version;

public:
  //Constructor of the class. When it's called, it fills the attribute "musical_note_map" with the information obtained
  //from the .txt, initializates *system and preload all the sounds that are we going to play
  Reproduce_music();

  //Destructor of the class. It does nothing.
  ~Reproduce_music();

  //Function that swap the content of the attribute "actual_notes" with the content used as parameter
  void update_musical_notes(set<int> new_musical_notes);

  //Function that use the sounds stored in the system variable to play the sounds wich ids are stored in "actual_notes"  
  void play_musical_notes();

  //Function that actualizes the content of "musical_note_map" with the content used as parameter.  
  void update_musical_note_data(map<int, musical_note_data> base_data);
};
