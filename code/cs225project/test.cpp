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
class Test {
    public:
        int test() {
            // test case 1
            // output from input testing is 
            //Greatest Remix Hits->Greatest Remix Hits (2 Unlimited album)->The Complete History (album)
            vector<vector<string> > csv = file_to_vector_csv("dataset/test1.csv");
            vector<vector<string> > txt = file_to_vector_txt("dataset/test1.txt");
            Graph g = vector_to_graph(csv, txt);
            stack<string> exp1 = g.stackPath("Greatest Remix Hits", "The Complete History (album)");
            stack<string> test1;

            test1.push("The Complete History (album)");
            test1.push("Greatest Remix Hits (2 Unlimited album)");
            
            assert(test1 ==  exp1);
            //test case 2 another 2 degree connection
            // Shortest path is :
            // University of Michigan Library->Committee on Institutional Cooperation->McNair SROP Michigan State Universit
            //test case 2
            stack<string> exp2 = g.stackPath("University of Michigan Library", "McNair SROP Michigan State University");
            stack<string> test2;
            test2.push("McNair SROP Michigan State University");
            test2.push("Committee on Institutional Cooperation");
            assert(test2 == exp2);

            //test case 3 1 degree connection
            //Shortest path is: 
            // Alexander Seton (d. 1332)->Battle of Wester Kinghorn% 
            stack<string> exp3 = g.stackPath("Alexander Seton (d. 1332)", "Battle of Wester Kinghorn");
            stack<string> test3;
            test3.push("Battle of Wester Kinghorn");
            assert(test3 == exp3);

            // testing for eulerian in different graphs
            EulerGraph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.testEuler(g1);
    g1.printEulerTrail(); 



    EulerGraph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    g2.testEuler(g2);
    g2.printEulerTrail(); 
 
    EulerGraph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    g3.testEuler(g3);
    g3.printEulerTrail(); 
 
    // EulerGraph with 3 vertices connected in the form of cycle
    EulerGraph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    g4.testEuler(g4);
    g4.printEulerTrail(); 


 
    // Let us create a EulerGraph with all vertices
    // with zero degree
    EulerGraph g5(3);
    g5.testEuler(g5);
    g5.printEulerTrail();
        return 0;
    }
};
