#include "Reproduce_music.hh"

    Reproduce_music::Reproduce_music() {
        map<int, musical_note_data> note_data;

        musical_note_data aux;
        aux.finger = 0;
        aux.hand = 4;
        aux.height = 0;
        aux.route = "/Users/ferranmartinez/Air-Piano/Sounds/Util/-1/39175__jobro__piano-ff-028.wav";
        note_data[1] = aux;

        aux.finger = 0;
        aux.hand = 3;
        aux.height = 0;
        aux.route = "/Users/ferranmartinez/Air-Piano/Sounds/Util/-1/39175__jobro__piano-ff-030.wav";
        note_data[2] = aux;

        aux.finger = 0;
        aux.hand = 2;
        aux.height = 0;
        aux.route = "/Users/ferranmartinez/Air-Piano/Sounds/Util/-1/39175__jobro__piano-ff-032.wav";
        note_data[3] = aux;

        aux.finger = 0;
        aux.hand = 2;
        aux.height = 0;
        aux.route = "./Sounds/Util/-1/39175__jobro__piano-ff-033.wav";
        note_data[4] = aux;

        aux.finger = 1;
        aux.hand = 1;
        aux.height = 0;
        aux.route = "./Sounds/Util/-1/39175__jobro__piano-ff-035.wav";
        note_data[5] = aux;

        aux.finger = 1;
        aux.hand = 2;
        aux.height = 0;
        aux.route = "./Sounds/Util/-1/39175__jobro__piano-ff-037.wav";
        note_data[6] = aux;

        aux.finger = 1;
        aux.hand = 3;
        aux.height = 0;
        aux.route = "./Sounds/Util/-1/39175__jobro__piano-ff-039.wav";
        note_data[7] = aux;

        aux.finger = 1;
        aux.hand = 4;
        aux.height = 0;
        aux.route = "./Sounds/Util/-1/39175__jobro__piano-ff-040.wav";
        note_data[8] = aux;

        aux.finger = 0;
        aux.hand = 4;
        aux.height = 130;
        aux.route = "./Sounds/Util/0/39175__jobro__piano-ff-040.wav";
        note_data[9] = aux;

        aux.finger = 0;
        aux.hand = 3;
        aux.height = 130;
        aux.route = "./Sounds/Util/0/39175__jobro__piano-ff-042.wav";
        note_data[10] = aux;

        aux.finger = 0;
        aux.hand = 4;
        aux.height = 0;
        aux.route = "./Sounds/Util/-1/39175__jobro__piano-ff-028.wav";
        note_data[1] = aux;

        aux.finger = 0;
        aux.hand = 2;
        aux.height = 130;
        aux.route = "./Sounds/Util/0/39175__jobro__piano-ff-044.wav";
        note_data[11] = aux;

        aux.finger = 0;
        aux.hand = 1;
        aux.height = 130;
        aux.route = "./Sounds/Util/0/39175__jobro__piano-ff-045.wav";
        note_data[12] = aux;

        aux.finger = 1;
        aux.hand = 1;
        aux.height = 130;
        aux.route = "./Sounds/Util/0/39175__jobro__piano-ff-047.wav";
        note_data[13] = aux;

        aux.finger = 1;
        aux.hand = 2;
        aux.height = 130;
        aux.route = "./Sounds/Util/0/39175__jobro__piano-ff-049.wav";
        note_data[14] = aux;

        aux.finger = 1;
        aux.hand = 3;
        aux.height = 130;
        aux.route = "./Sounds/Util/0/39175__jobro__piano-ff-051.wav";
        note_data[15] = aux;

        aux.finger = 1;
        aux.hand = 4;
        aux.height = 130;
        aux.route = "./Sounds/Util/0/39175__jobro__piano-ff-052.wav";
        note_data[16] = aux;

        aux.finger = 0;
        aux.hand = 4;
        aux.height = 210;
        aux.route = "./Sounds/Util/1/39175__jobro__piano-ff-052.wav";
        note_data[17] = aux;

        aux.finger = 0;
        aux.hand = 3;
        aux.height = 210;
        aux.route = "./Sounds/Util/1/39175__jobro__piano-ff-054.wav";
        note_data[18] = aux;

        aux.finger = 0;
        aux.hand = 2;
        aux.height = 210;
        aux.route = "./Sounds/Util/1/39175__jobro__piano-ff-056.wav";
        note_data[19] = aux;

        aux.finger = 0;
        aux.hand = 1;
        aux.height = 210;
        aux.route = "./Sounds/Util/1/39175__jobro__piano-ff-057.wav";
        note_data[20] = aux;

        aux.finger = 1;
        aux.hand = 1;
        aux.height = 210;
        aux.route = "./Sounds/Util/1/39175__jobro__piano-ff-059.wav";
        note_data[21] = aux;

        aux.finger = 1;
        aux.hand = 2;
        aux.height = 210;
        aux.route = "./Sounds/Util/1/39175__jobro__piano-ff-061.wav";
        note_data[22] = aux;

        aux.finger = 1;
        aux.hand = 3;
        aux.height = 210;
        aux.route = "./Sounds/Util/1/39175__jobro__piano-ff-063.wav";
        note_data[23] = aux;

        aux.finger = 1;
        aux.hand = 4;
        aux.height = 210;
        aux.route = "./Sounds/Util/1/39175__jobro__piano-ff-064.wav";
        note_data[24] = aux;

        this->musical_note_map = note_data;

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
        map<int, musical_note_data>::iterator it = musical_note_map.begin();
        int i = 1;
        //for (it = musical_note_map.begin(); it != musical_note_map.end(); it++) {
            result = system->createSound(it->second.route, FMOD_DEFAULT, 0, &sound[i]);
            cout << FMOD_ErrorString(result) << " " << it->second.route << " " << sound[i] << " " << it-> first << endl;
            ++i;
        //}
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
