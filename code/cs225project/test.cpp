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
            return 0;
        }
};
