#pragma once
#include <iostream>
// #include "utils.h"
#include <vector>
#include <string>
#include <cassert>
#include "BFS.cpp"
#include "dataparsing.h"
#include <map>
#include "eulerian.cpp"
using namespace std;
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Enter two inputs" << endl;
        return 1;
    }
    // //input entered by the user
    string start_node = argv[1];
    string end_node = argv[2];


    vector<vector<string> > csv = file_to_vector_csv("dataset/test1.csv");
    vector<vector<string> > txt = file_to_vector_txt("dataset/test1.txt");
    Graph g = vector_to_graph(csv, txt);
    g.printPath(start_node, end_node);
    // int res = g1.isEulerian();
    //     if (res == 0)
    //         cout << "graph is not Eulerian\n";
    //     else if (res == 1)
    //         cout << "graph has a Euler path\n";
    //     else
    //         cout << "graph has a Euler cycle\n";
    // g1.printEulerTrail(); 
    return 0;
}
