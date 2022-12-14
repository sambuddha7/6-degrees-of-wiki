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

   
    //creating nodes
    // Graph g;
    // Node node_A("A"), node_B("B"), node_C("C"), node_D("D"), node_E("E");
    // //connect nodes (i.e. create graph)
   
    // g.addEdge("A", "B");
    // g.addEdge("B", "C");
    // g.addEdge("C", "C");
    // g.addEdge("D", "D");
    // g.addEdge("B", "E");
    // g.printPath("A", "E");



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

    // // //test1
    // // assert(test1 == expected_test1);
    // string start_node = argv[1];
    // string end_node = argv[2];


    vector<vector<string> > csv = file_to_vector_csv("dataset/test1.csv");
    vector<vector<string> > txt = file_to_vector_txt("dataset/test1.txt");
    Graph g = vector_to_graph(csv, txt);
    g.printPath("Yo", "Hello");
    // unordered_map<string, Node*> mapp = g.getString();
    // for (auto i : mapp) {
    //     cout << i.first << endl;
    // }
    // Node* start = mapp["Hi"];
    // Node* end = mapp["Hello"];
    // BFS bfs(start, end, g);

    // vector<string> test1 = bfs.findPath();
    // // testing of case 1
    // cout << "Shortest path is:" << endl;
    // for (string c : test1) {
    //     cout << c << endl;
    // }

    // EulerGraph e = vector_to_euler(txt);
    //  int res = e.isEulerian();
    //     if (res == 0)
    //         cout << "graph is not Eulerian\n";
    //     else if (res == 1)
    //         cout << "graph has a Euler path\n";
    //     else
    //         cout << "graph has a Euler cycle\n";
    // e.printEulerTrail(); 
    // EulerGraph g1(5);
    // g1.addEdge(1, 0);
    // g1.addEdge(0, 2);
    // g1.addEdge(2, 1);
    // g1.addEdge(0, 3);
    // g1.addEdge(3, 4);
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
