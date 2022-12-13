#include <iostream>
// #include "utils.h"
#include <vector>
#include <string>
#include <cassert>
using namespace std;
#include "centrality.cpp"
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Enter two inputs" << endl;
        return 1;
    }
    //input entered by the user

    string start_node = argv[1];
    string end_node = argv[2];
    //creating nodes
    Graph g;
    Node node_A("A"), node_B("B"), node_C("C"), node_D("D"), node_E("E");
    //connect nodes (i.e. create graph)
    // node_A.addNeighbour(&node_B);
    // node_B.addNeighbour(&node_C);
    // node_C.addNeighbour(&node_C);
    // node_D.addNeighbour(&node_D);
    // node_B.addNeighbour(&node_E);
    g.addEdge(&node_A, &node_B);
    g.addEdge(&node_B, &node_C);
    g.addEdge(&node_C, &node_C);
    g.addEdge(&node_D, &node_D);
    g.addEdge(&node_B, &node_E);
    



    BFS bfs(&node_A, &node_E);
    vector<string> test1 = bfs.findPath();
    //testing of case 1
    cout << "Shortest path is:" << endl;
    for (string c : test1) {
        cout << c << endl;
    }
    vector<string> expected_test1;
    expected_test1.push_back("A");
    expected_test1.push_back("B");
    expected_test1.push_back("E");

    //test1
    assert(test1 == expected_test1);

    return 0;
}
