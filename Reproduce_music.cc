#include "Reproduce_music.hh"

class Reproduce_music {
    Reproduce_music::Reproduce_music(map<int, musical_note_data> base_data) {
        this->musical_note_map = base_data;

        *extradriverdata = 0;
        Common_Init(&extradriverdata);

        result = FMOD::System_Create(&system);
        ERRCHECK(result);

        if (version < FMOD_VERSION) {
            Common_Fatal("FMOD lib version %08x doesn't match header version %08x", version, FMOD_VERSION);
        }

        result = system->init(10, FMOD_INIT_NORMAL, extradriverdata);
        ERRCHECK(result);

        map<int, musical_note_data>::iterator it;
        int i = 0;
        for (it = musical_note_map.begin(); it != musical_note_map.end(); it++) {
            result = system->createSound(Common_MediaPath(it->second.route), FMOD_LOOP_NORMAL, 0, &sound[i]);
            ERRCHECK(result);
            ++i;
        }
    }

    Reproduce_music::~Reproduce_music(){}

    void Reproduce_music::update_musical_notes(set<int> new_musical_notes){
          this->previous_notes = actual_notes;
          this->actual_notes = new_musical_notes;
    }

    void Reproduce_music::play_musical_notes(){
        set<int>::iterator set_it;
        for (set_it = actual_notes.begin(); set_it != actual_notes.end(); it++) {
            set<int>::iterator find_it;
            find_it = previous_notes.find(*set_it);
            if (find_it == previous_notes.end()) {
                result = system->playSound(sound[*set_it], 0, true, &channel[*set_it]);
                ERRCHECK(result);

                result = channel[count]->setPaused(false);
                ERRCHECK(result);
            }
        }
    }

    void Reproduce_music::update_musical_note_data(map<int, musical_note_data> base_data){
        this->musical_note_map = base_data;
    }
}
