#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <cstring>
#include "Reproduce_music.hh"
using namespace std;

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

map<int, musical_note_data> read_data_from_txt(const char* const path_to_read) {
    map<int, musical_note_data> data_map;
    std::ifstream infile(path_to_read);
    string next_read;
    if( !infile ) {
        std::cout << "Can't open file " << path_to_read << std::endl;
        std::exit( -1 );
    }
    else {
        while (infile >> next_read) {
        }
    }
    return data_map;
}

int main() {
    map<int, musical_note_data> data_map;
    musical_note_data aux;
    aux.route = "./Sounds/drumloop.wav";
    data_map[1] = aux;
    aux.route = "./Sounds/singing.wav";
    data_map[2] = aux;
    Reproduce_music test(data_map);
    int myints[]= {1, 2};
    std::set<int> second (myints,myints+2);
    set<int>::iterator it2;
    /*for (it2 = second.begin(); it2 != second.end(); ++it2) {
        cout << *it2 << endl;
    }*/
    test.update_musical_notes(second);
    test.play_musical_notes();
    while(1);
    /*map<int, musical_note_data>::iterator it;

    for (it = data_map.begin(); it != data_map.end(); ++it) {
        cout << it->first << " " << it->second.route << endl;
    }*/
}
