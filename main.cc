#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>
#include <map>
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

map<int, musical_note_data> read_data_from_txt(string path_to_read) {
    map<int, musical_note_data> data_map;
    std::ifstream infile(path_to_read);
    string next_read;
    while (infile >> next_read) {
        vector<string> line_readed = split(next_read, ';');
        musical_note_data data_aux;
        data_aux.route = new char[line_readed[1].length() + 1];
        data_map[atoi(line_readed[0].c_str())] = data_aux;
    }
    return data_map;
}

int main() {
    Reproduce_music test(read_data_from_txt("musical_notes_data.txt"));
    cout << "Data llegida i classe creada" << endl;
}
