/**
 * @file schedule.cpp
 * Exam scheduling using graph coloring
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>

#include "wikigraph.h"
#include <algorithm>
using namespace std;

vector<vector<string> > file_to_vector(const std::string & filename){
    vector<vector<string> > to_return;
    std::ifstream istream(filename);
    string line;
    while (std::getline(istream, line)) {
        vector<string> vect;
        SplitString(line, ',', vect);
        for (unsigned i = 0; i < vect.size(); ++i) {
            vect[i] = Trim(vect[i]);
        }
        to_return.push_back(vect);
    }
    
    return to_return;
}



std::string TrimRight(const std::string & str) {
    std::string tmp = str;
    return tmp.erase(tmp.find_last_not_of(" ") + 1);
}

std::string TrimLeft(const std::string & str) {
    std::string tmp = str;
    return tmp.erase(0, tmp.find_first_not_of(" "));
}

std::string Trim(const std::string & str) {
    std::string tmp = str;
    return TrimLeft(TrimRight(str));
}

void SplitString(const std::string & str1, char sep, std::vector<std::string> &fields) {
    std::string str = str1;
    std::string::size_type pos;
    while((pos=str.find(sep)) != std::string::npos) {
        fields.push_back(str.substr(0,pos));
        str.erase(0,pos+1);  
    }
    fields.push_back(str);
}