#include <unordered_map>
#include <list>
#include <queue>
#include <string>
#include "BFS.cpp"
#include <vector>
using namespace std;
class Graph {
    
    public:
        unordered_map<Node*, list<Node*> > l;
        void addEdge(Node* x, Node* y) {
            l[x].push_back(y);
            l[y].push_back(x);
        }
        int size() {
            return l.size();
        }
        list<Node*> getNeighbors(Node* node) {
            return l[node];
        }
};
