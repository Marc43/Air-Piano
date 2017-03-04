#include "Headers/fmod.hpp"
#include "Headers/fmod_errors.h"
#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;

struct musical_note_data {
    char * route; int finger; int hand; int height;
};

class Reproduce_music {
private:
  set<int> actual_notes;

  map<int, musical_note_data> musical_note_map;

  FMOD::System       *system;
  FMOD::Sound        *sound[32];
  FMOD_RESULT         result;
  int                 count;
  unsigned int        version;

public:
  Reproduce_music(map<int, musical_note_data> base_data);

  ~Reproduce_music();

  void update_musical_notes(set<int> new_musical_notes);

  void play_musical_notes();

  void update_musical_note_data(map<int, musical_note_data> base_data);
};
