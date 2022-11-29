
#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <set>
using namespace std;

vector<vector<string> > file_to_vector(const std::string & filename);

std::string file_to_string(const std::string & filename);
std::string TrimRight(const std::string & str);
std::string TrimLeft(const std::string & str);
std::string Trim(const std::string & str);

void SplitString(const std::string & str1, char sep, std::vector<std::string> &fields);
