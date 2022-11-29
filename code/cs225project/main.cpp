#include <iostream>
// #include "utils.h"
#include <vector>
#include <string>
#include <cassert>
using namespace std;
#include "BFS.cpp"
int main() {
    

    //creating nodes
    Node node_A('A'), node_B('B'), node_C('C'), node_D('D'), node_E('E');
    //connect nodes (i.e. create graph)
    node_A.addNeighbour(&node_B);
    node_B.addNeighbour(&node_C);
    node_C.addNeighbour(&node_C);
    node_D.addNeighbour(&node_D);
    node_B.addNeighbour(&node_E);


    BFS bfs(&node_A, &node_E);
    vector<char> test1 = bfs.findPath();
    //testing of case 1
    cout << "Shortest path is:" << endl;
    for (char c : test1) {
        cout << c << endl;
    }
    vector<char> expected_test1;
    expected_test1.push_back('A');
    expected_test1.push_back('B');
    expected_test1.push_back('E');

    //test1
    assert(test1 == expected_test1);

    //test 2 no common neighbors
    // Node node_F('F'), node_G('G'), node_H('H'), node_I('I'), node_J('J');
    // //connect nodes (i.e. create graph)
    // node_F.addNeighbour(&node_G);
    // node_G.addNeighbour(&node_H);
    // node_H.addNeighbour(&node_I);
    // node_I.addNeighbour(&node_J);
    //  BFS bfs2(&node_F, &node_J);
    // vector<char> test2 = bfs2.findPath();
    // //testing of case 2
    // cout << "Shortest path test 2 is:" << endl;
    // for (char c : test2) {
    //     cout << c << endl;
    // }
    // vector<char> expected_test2;
    // expected_test2.push_back('F');
    // expected_test2.push_back('G');
    // expected_test2.push_back('H');
    // expected_test2.push_back('I');
    // expected_test2.push_back('J');

    // //test2
    // assert(test2 == expected_test2);
    // //test 3 completely connected graph
    // Node node_X('X'), node_Y('Y'), node_Z('Z');
    // node_X.addNeighbour(&node_Y);
    // node_X.addNeighbour(&node_Z);
    // node_Y.addNeighbour(&node_Z);
    // BFS bfs3(&node_Y, &node_Z);
    // vector<char> test3 = bfs3.findPath();
    // cout << "Shortest path test 3 is:" << endl;
    // for (char c : test3) {
    //     cout << c << endl;
    // }
    // vector<char> expected_test3;
    // expected_test3.push_back('Y');
    // expected_test3.push_back('Z');
    // assert(test3 == expected_test3);
    return 0;
}
