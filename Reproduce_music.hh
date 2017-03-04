#include "fmod.hpp"
#include "common.h"
#include <set>
#include <map>
#include <string>
using namespace std;

struct musical_note_data {
    string route;
}

class Reproduce_music {
private:
  set<int> previous_notes;

  set<int> actual_notes;

  map<int, musical_note_data> musical_note_map;

  FMOD::System       *system;
  FMOD::Sound        *sound[32];
  FMOD::Channel      *channel[32];
  FMOD_RESULT         result;
  int                 count;
  unsigned int        version;
  void               *extradriverdata;

public:
  Reproduce_music(map<int, musical_note_data> base_data);

  ~Reproduce_music();

  void update_musical_notes(set<int> new_musical_notes);

  void play_musical_notes();

  void update_musical_note_data(map<int, musical_note_data> base_data);
};
