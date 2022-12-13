#pragma once
#include <iostream>
// #include "utils.h"
#include <vector>
#include <string>
#include <cassert>
#include "BFS.cpp"
#include "dataparsing.h"
#include <map>
using namespace std;
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Enter two inputs" << endl;
        return 1;
    }
    // //input entered by the user

   
    // //creating nodes
    // Graph g;
    // Node node_A("A"), node_B("B"), node_C("C"), node_D("D"), node_E("E");
    // //connect nodes (i.e. create graph)
   
    // g.addEdge(&node_A, &node_B);
    // g.addEdge(&node_B, &node_C);
    // g.addEdge(&node_C, &node_C);
    // g.addEdge(&node_D, &node_D);
    // g.addEdge(&node_B, &node_E);
    



    // BFS bfs(&node_A, &node_C, g);
    // vector<string> test1 = bfs.findPath();
    // //testing of case 1
    // cout << "Shortest path is:" << endl;
    // for (string c : test1) {
    //     cout << c << endl;
    // }
    // vector<string> expected_test1;
    // expected_test1.push_back("A");
    // expected_test1.push_back("B");
    // expected_test1.push_back("E");

    // //test1
    // assert(test1 == expected_test1);
    string start_node = argv[1];
    string end_node = argv[2];


    vector<vector<string> > csv = file_to_vector_csv("dataset/test1.csv");
    vector<vector<string> > txt = file_to_vector_txt("dataset/test1.txt");
    Graph g = vector_to_graph(csv, txt);
    unordered_map<string, Node*> mapp = g.getString();
    Node* start = mapp[start_node];
    Node* end = mapp[end_node];
    BFS bfs(start, end, g);

    vector<string> test1 = bfs.findPath();
    // testing of case 1
    cout << "Shortest path is:" << endl;
    for (string c : test1) {
        cout << c << endl;
    }

    // EulerGraph e = vector_to_euler(txt);
    // test(e);
    // e.printEulerTrail(); 
    return 0;
}
