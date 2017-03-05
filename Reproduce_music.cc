#include "Reproduce_music.hh"

    Reproduce_music::Reproduce_music() {
        map<int, musical_note_data> note_data;

        musical_note_data aux;
        aux.finger = 0;
        aux.hand = 4;
        aux.height = 0;
        aux.route = "piano28.wav";
        note_data[1] = aux;

        aux.finger = 0;
        aux.hand = 3;
        aux.height = 0;
        aux.route = "piano30.wav";
        note_data[2] = aux;

        aux.finger = 0;
        aux.hand = 2;
        aux.height = 0;
        aux.route = "piano32.wav";
        note_data[3] = aux;

        aux.finger = 0;
        aux.hand = 2;
        aux.height = 0;
        aux.route = "piano33.wav";
        note_data[4] = aux;

        aux.finger = 1;
        aux.hand = 1;
        aux.height = 0;
        aux.route = "piano35.wav";
        note_data[5] = aux;

        aux.finger = 1;
        aux.hand = 2;
        aux.height = 0;
        aux.route = "piano37.wav";
        note_data[6] = aux;

        aux.finger = 1;
        aux.hand = 3;
        aux.height = 0;
        aux.route = "piano39.wav";
        note_data[7] = aux;

        aux.finger = 1;
        aux.hand = 4;
        aux.height = 0;
        aux.route = "piano40.wav";
        note_data[8] = aux;

        aux.finger = 0;
        aux.hand = 4;
        aux.height = 130;
        aux.route = "piano40.wav";
        note_data[9] = aux;

        aux.finger = 0;
        aux.hand = 3;
        aux.height = 130;
        aux.route = "piano42.wav";
        note_data[10] = aux;

        aux.finger = 0;
        aux.hand = 2;
        aux.height = 130;
        aux.route = "piano44.wav";
        note_data[11] = aux;

        aux.finger = 0;
        aux.hand = 1;
        aux.height = 130;
        aux.route = "piano45.wav";
        note_data[12] = aux;

        aux.finger = 1;
        aux.hand = 1;
        aux.height = 130;
        aux.route = "piano47.wav";
        note_data[13] = aux;

        aux.finger = 1;
        aux.hand = 2;
        aux.height = 130;
        aux.route = "piano49.wav";
        note_data[14] = aux;

        aux.finger = 1;
        aux.hand = 3;
        aux.height = 130;
        aux.route = "piano51.wav";
        note_data[15] = aux;

        aux.finger = 1;
        aux.hand = 4;
        aux.height = 130;
        aux.route = "piano52.wav";
        note_data[16] = aux;

        aux.finger = 0;
        aux.hand = 4;
        aux.height = 210;
        aux.route = "piano52.wav";
        note_data[17] = aux;

        aux.finger = 0;
        aux.hand = 3;
        aux.height = 210;
        aux.route = "piano54.wav";
        note_data[18] = aux;

        aux.finger = 0;
        aux.hand = 2;
        aux.height = 210;
        aux.route = "piano56.wav";
        note_data[19] = aux;

        aux.finger = 0;
        aux.hand = 1;
        aux.height = 210;
        aux.route = "piano57.wav";
        note_data[20] = aux;

        aux.finger = 1;
        aux.hand = 1;
        aux.height = 210;
        aux.route = "piano59.wav";
        note_data[21] = aux;

        aux.finger = 1;
        aux.hand = 2;
        aux.height = 210;
        aux.route = "piano61.wav";
        note_data[22] = aux;

        aux.finger = 1;
        aux.hand = 3;
        aux.height = 210;
        aux.route = "piano63.wav";
        note_data[23] = aux;

        aux.finger = 1;
        aux.hand = 4;
        aux.height = 210;
        aux.route = "piano64.wav";
        note_data[24] = aux;

        this->musical_note_map = note_data;

        FMOD::System_Create(&system);

        result = system->getVersion(&version);
        cout << FMOD_ErrorString(result) << endl;
        if (version < FMOD_VERSION) {
            cout << "FMOD lib version " << version << " doesn't match header version " << FMOD_VERSION << endl;
        }

        result = system->init(32, FMOD_INIT_NORMAL, NULL);
        cout << FMOD_ErrorString(result) << endl;
        map<int, musical_note_data>::iterator it;
        for (it = note_data.begin(); it != note_data.end(); it++) {
            result = system->createSound(it->second.route, FMOD_DEFAULT, 0, &sound[it->first]);
            cout << FMOD_ErrorString(result) << " " << it->second.route << " " << sound[it->first] << " " << it->first << endl;
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
