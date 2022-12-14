
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include "dataparsing.h"
#include <algorithm>
#include "unordered_map"
using namespace std;

vector<vector<string> > file_to_vector_csv(const std::string & filename){
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
    for (vector<string> & i : to_return) {
        i[1] = brackTrim(i[1]);
    }
    
    return to_return;
}
vector<vector<string> > file_to_vector_txt(const std::string & filename){
    vector<vector<string> > to_return;
    std::ifstream istream(filename);
    string line;
    while (std::getline(istream, line)) {
        vector<string> vect;
        SplitString(line, ' ', vect);
        for (unsigned i = 0; i < vect.size(); ++i) {
            vect[i] = Trim(vect[i]);
        }
        to_return.push_back(vect);
    }
    
    return to_return;
}

Graph vector_to_graph(vector<vector<string> > csv, vector<vector<string> > txt)  {
    Graph g;
    unordered_map<string, string> id_to_name;
    for (vector<string> vect : csv) {
        id_to_name[vect[0]] = vect[1];
    }
    for (vector<string> vect : txt) {
        Node* node_one = new Node(id_to_name[vect[0]]);
        Node* node_two = new Node(id_to_name[vect[1]]);
        g.addEdge(node_one, node_two);
        delete node_one;
        delete node_two;
    }
    return g;
}
EulerGraph vector_to_euler(vector<vector<string> > txt) {
    EulerGraph g(txt.size());
    for (vector<string> i : txt) {
        g.addEdge(stoi(i[0]), stoi(i[1]));
    }
    return g;
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
std::string brackTrim(std::string & str) {
    return str.substr(1, str.size() - 2);
}
