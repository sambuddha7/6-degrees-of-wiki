#include <iostream>
#include "wikigraph.h"
// #include "utils.h"
#include "BFS.cpp"
#include <vector>
#include <string>
using namespace std;
int main() {
    std::string filename = "tests/wikitest1.csv";
    vector<vector<string> > data_vector = file_to_vector(filename);

    //creating nodes
    Node node_A('A'), node_B('B'), node_C('C'), node_D('D'), node_E('E');
    //connect nodes (i.e. create graph)
    node_A.addNeighbour(&node_B);
    node_B.addNeighbour(&node_C);
    node_C.addNeighbour(&node_C);
    node_D.addNeighbour(&node_D);
    node_B.addNeighbour(&node_E);


    BFS bfs(&node_A, &node_E);
    bfs.findPath();

    return 0;
}