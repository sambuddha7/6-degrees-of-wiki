
#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <set>

#include "BFS.cpp"
#include "eulerian.cpp"
using namespace std;

vector<vector<string> > file_to_vector_csv(const std::string & filename);
vector<vector<string> > file_to_vector_txt(const std::string & filename);
Graph vector_to_graph(vector<vector<string> > csv, vector<vector<string> > txt);
std::string file_to_string(const std::string & filename);
std::string TrimRight(const std::string & str);
std::string TrimLeft(const std::string & str);
std::string Trim(const std::string & str);
std::string brackTrim(std::string & str);
// EulerGraph vector_to_euler(vector<vector<string> > txt);

void SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);
