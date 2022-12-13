#include <iostream>
#include <queue>
#include<list>
#include <vector>
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

class BFS {
    Node* start;
    Node* end;

public:
    BFS(Node* start, Node* end) {
        this->start = start;
        this->end = end;
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

            for (Node* node : current_node->neighbors) {
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
        //finding spaning tree
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
