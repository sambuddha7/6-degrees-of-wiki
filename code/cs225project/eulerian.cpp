#include<iostream>
#include <list>
#include "centrality.cpp"
using namespace std;
 
// A class that represents an undirected graph

class EulerGraph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
public:
    // Constructor and destructor
    EulerGraph(int V)   {this->V = V; adj = new list<int>[V]; }
    ~EulerGraph() { delete [] adj; } // To avoid memory leak
 
    // function to add an edge to EulerGraph
    void addEdge(int v, int w);
    // function to remove edge
    void rmvEdge(int v, int u);
 
    // Method to check if this EulerGraph is Eulerian or not
    int isEulerian();
 
    // Method to check if all non-zero degree vertices are connected
    bool isConnected();

    //Methods to print Eulerian tour
    void printEulerTour();
    void printEulerUtil(int s); 
 
    // Function to do DFS starting from v. Used in isConnected();
    void DFSUtil(int v, bool visited[]);

    //
    bool isValidNextEdge(int u, int v);
};


 
void EulerGraph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the EulerGraph is undirected
}
 
void EulerGraph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
// Method to check if all non-zero degree vertices are connected.
// It mainly does DFS traversal starting from
bool EulerGraph::isConnected()
{
    // Mark all the vertices as not visited
    bool visited[V];
    int i;
    for (i = 0; i < V; i++)
        visited[i] = false;
 
    // Find a vertex with non-zero degree
    for (i = 0; i < V; i++)
        if (adj[i].size() != 0)
            break;
 
    // If there are no edges in the EulerGraph, return true
    if (i == V)
        return true;
 
    // Start DFS traversal from a vertex with non-zero degree
    DFSUtil(i, visited);
 
    // Check if all non-zero degree vertices are visited
    for (i = 0; i < V; i++)
       if (visited[i] == false && adj[i].size() > 0)
            return false;
 
    return true;
}
 
/* The function returns one of the following values
   0 --> If EulerGraph is not Eulerian
   1 --> If EulerGraph has an Euler path (Semi-Eulerian)
   2 --> If EulerGraph has an Euler Circuit (Eulerian)  */
int EulerGraph::isEulerian()
{
    // Check if all non-zero degree vertices are connected
    if (isConnected() == false)
        return 0;
 
    // Count vertices with odd degree
    int odd = 0;
    for (int i = 0; i < V; i++)
        if (adj[i].size() & 1)
            odd++;
 
    // If count is more than 2, then EulerGraph is not Eulerian
    if (odd > 2)
        return 0;
 
    // If odd count is 2, then semi-eulerian.
    // If odd count is 0, then eulerian
    // Note that odd count can never be 1 for undirected EulerGraph
    return (odd)? 1 : 2;
}
 
// Function to run test cases
void test(EulerGraph &g)
{
    int res = g.isEulerian();
    if (res == 0)
        cout << "graph is not Eulerian\n";
    else if (res == 1)
        cout << "graph has a Euler path\n";
    else
        cout << "graph has a Euler cycle\n";
}


 
// Driver program to test above function
int main()
{
    // Let us create and test graphs shown in above figures
    EulerGraph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    test(g1);
 
    EulerGraph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    test(g2);
 
    EulerGraph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    test(g3);
 
    // Let us create a EulerGraph with 3 vertices
    // connected in the form of cycle
    EulerGraph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    test(g4);
 
    // Let us create a EulerGraph with all vertices
    // with zero degree
    EulerGraph g5(3);
    test(g5);
 
    return 0;
}
