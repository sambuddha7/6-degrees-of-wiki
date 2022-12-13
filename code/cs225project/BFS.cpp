
#pragma once
#include <iostream>
#include <queue>
#include<list>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


// representing node of a graph
class Node {
public:
    //Adjacency List of the vertex
    list<Node*> neighbors;
    string name;
    bool visited = false;
    Node* prev = nullptr;

    Node(string name) { this->name = name; }

    //Method to connect vertices
    void addNeighbour(Node* v) {
        this->neighbors.push_back(v);
        v->neighbors.push_back(this);
    }
};
class Graph {
    public:
        unordered_map<Node*, list<Node*> > l;
        unordered_map<string, Node*> s;
        void addEdge(Node* x, Node* y) {
            l[x].push_back(y);
            s[x->name] = x;
            s[y->name] = y;
        }
        

        int size() {
            return l.size();
        }
        unordered_map<Node*, list<Node*> > getAdjacencyList() {
            return l;
        } 
        unordered_map<string, Node*> getString() {
            return s;
        }
        list<Node*> getNeighbors(Node* node) {
            return l[node];
        }
};
class BFS {
    Node* start;
    Node* end;
    Graph graph;
public:
    BFS(Node* start, Node* end, Graph g) {
        this->start = start;
        this->end = end;
        graph = g;
    }

    vector<string> findPath() {

        queue<Node*> Queue;
        bool reached_end = false;
        //Visit start node and add to queue
        start->visited = true;
        Queue.push(start);

        //BFS until queue is empty

        while (!Queue.empty() && !reached_end) {
            //Pop a node from queue for search operation
            Node* current_node = Queue.front();
            Queue.pop();
            //Loop through neighbors nodes to find the 'end' node
            //Node* node : current_node->neighbors
            for (Node* node : graph.getNeighbors(current_node)) {
                if (!node->visited) {
                    //Visit and add neighbor nodes to the queue

                    node->visited = true;
                    Queue.push(node);
                    node->prev = current_node;
                    //stop BFS if the end node is found
                    if (node == end) {
                        reached_end = true;
                        break;
                    }
                }
            }
        }
        return trace_route();
    }

    //Function to trace back route
    vector<string> trace_route() {
        list<Node*> route;
        Node* node = end;
        //start.prev is always null 
         //so loop until node->prev is null to trace route
        //finding spanning tree
        while (node != nullptr) {
            route.push_front(node);
            node = node->prev;
        }
        //Display the spaning  and shortest path
        // cout << "Shortest Path Between Nodes is" << endl;
        vector<string> to_return;
        for (Node* n : route) {
            // cout << n->name << " ";
            to_return.push_back(n->name);
        }
        return to_return;
    }
    

};
