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

map<int, musical_note_data> read_data_from_txt(string path_to_read) {
    map<int, musical_note_data> data_map;
    std::ifstream input(path_to_read); //put your program together with thsi file in the same folder.
    cout << "1" << endl;
    if(input.is_open()){
        cout << "2" << endl;
        while(!input.eof()){
            cout << "3" << endl;
            string data;
            getline(input,data);
            cout << data << endl;
            vector<string> splitted_data = split(data, ';'); //convert to integer
            musical_note_data aux;
            aux.finger = atoi(splitted_data[1].c_str());
            aux.hand = atoi(splitted_data[2].c_str());
            aux.height = atoi(splitted_data[3].c_str());
            char* chr = strdup(splitted_data[4].c_str());
            aux.route = chr;
            free(chr);
            data_map[atoi(splitted_data[0].c_str())] = aux;
       }
    }
    return data_map;
}

int main() {
    map<int, musical_note_data> data_map;
    Reproduce_music test(read_data_from_txt("txtDeMierda.txt"));
    int myints[]= {1, 9};
    std::set<int> second (myints,myints+2);
    set<int>::iterator it2;
    for (it2 = second.begin(); it2 != second.end(); ++it2) {
        cout << *it2 << endl;
    }
    test.update_musical_notes(second);
    test.play_musical_notes();
    //map<int, musical_note_data> data_map = read_data_from_txt("txtDeMierda.txt");

    /*map<int, musical_note_data>::iterator it;

    for (it = data_map.begin(); it != data_map.end(); ++it) {
        cout << it->first << " " << it->second.finger << " " << it->second.hand << " " <<it->second.height << " " << it->second.route << endl;
    }*/
}
