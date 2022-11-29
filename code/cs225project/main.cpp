#include <iostream>
#include "wikigraph.h"
#include "utils.h"
#include <vector>
#include <string>
using namespace std;
int main() {
    std::string filename = "tests/wikitest1.csv";
    vector<vector<string> > data_vector = file_to_vector(filename);
    return 0;
}