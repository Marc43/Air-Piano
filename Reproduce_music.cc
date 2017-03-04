#include "Reproduce_music.hh"

    Reproduce_music::Reproduce_music(map<int, musical_note_data> base_data) {
        this->musical_note_map = base_data;

        FMOD::System_Create(&system);

        result = system->getVersion(&version);
        cout << FMOD_ErrorString(result) << endl;
        if (version < FMOD_VERSION) {
            cout << "FMOD lib version " << version << " doesn't match header version " << FMOD_VERSION << endl;
        }

        int driverCount = 0;
       system->getNumDrivers(&driverCount);

        if (driverCount == 0)
        {
           cout << "No drivers" << endl;
        }
        result = system->init(32, FMOD_INIT_NORMAL, NULL);
        cout << FMOD_ErrorString(result) << endl;
        map<int, musical_note_data>::iterator it;
        for (it = musical_note_map.begin(); it != musical_note_map.end(); it++) {
            result = system->createSound(it->second.route, FMOD_DEFAULT, 0, &sound[it->first]);
            cout << FMOD_ErrorString(result) << endl;
        }
    }

    Reproduce_music::~Reproduce_music(){}

    void Reproduce_music::update_musical_notes(set<int> new_musical_notes){
          this->actual_notes = new_musical_notes;
    }

    void Reproduce_music::play_musical_notes(){
        set<int>::iterator set_it;
        for (set_it = actual_notes.begin(); set_it != actual_notes.end(); set_it++) {
            result = system->playSound(sound[*set_it], NULL, false, NULL);
            cout << FMOD_ErrorString(result) << endl;
        }
    }

    void Reproduce_music::update_musical_note_data(map<int, musical_note_data> base_data){
        this->musical_note_map = base_data;
    }
