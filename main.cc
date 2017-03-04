#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

struct musical_note_data {
    string route;
};

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
        data_aux.route = line_readed[1];
        data_map[atoi(line_readed[0].c_str())] = data_aux;
    }
    return data_map;
}
