
#pragma once
#include <iostream>
#include <queue>
#include<list>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;


// representing node of a graph
class Graph {
    public:
        unordered_map<string, list<string> > new_l;
        // unordered_map<string, Node*> s;
        void addEdge(string x, string y) {
            new_l[x].push_back(y);
            new_l[y].push_back(x);
        }

        bool BFString(string source, string dest, unordered_map<string, string>& parent) {
            queue<string> q;
            // bool visited[new_l.size()];
            unordered_map<string, bool> visited;
            for (auto i : new_l) {
                visited[i.first] = false;
                parent[i.first] = "";
            }
            q.push(source);
            visited[source] = true;
            while (!q.empty()) {
                string temp = q.front();
                // cout << "temp: " << temp << endl;
                q.pop();
                for (string k : new_l[temp]) {
                    
                    if (visited[k] == false) {
                        q.push(k);
                        visited[k] = true;
                        parent[k] = temp;
                        if (k == dest) return true;
                    }
                } 
            }
            return false;
        }
        stack<string> stackPath(string source, string dest) {
            unordered_map<string, string> parent;
            if (BFString(source, dest, parent) == false) {
                return stack<string>();
            }
            stack<string> s;
            while (parent[dest] != "") {
                s.push(dest);
                dest = parent[dest];
            }
            return s;
        }
        void printPath(string source, string dest) {
            
            unordered_map<string, string> parent;
            if (BFString(source, dest, parent) == false) {
                cout << "No possible path" << endl;
            } else {
                cout << "Shortest path is :" << endl;
            }
            stack<string> s;
            while (parent[dest] != "") {
                s.push(dest);
                dest = parent[dest];
            }
            cout << source ;
            while (!s.empty()) {
                cout  << "->" << s.top();
                s.pop();
            }
        }
};
