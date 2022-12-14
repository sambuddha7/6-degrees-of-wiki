#pragma once
#include<iostream>
#include <list>
#include <string.h> 
#include <algorithm> 
using namespace std;
 
class EulerGraph
{
    // An array of adjacency lists
    list<int> *arr;  
    // No. of vertices
    int N;    

public:
    // Constructor 
    EulerGraph(int N) {
        this->N = N;
        arr = new list<int>[N];
    }
    // Destructor 
    ~EulerGraph() {
         delete [] arr;
    }
 
    // Add an edge 
    void addEdge(int v, int u) {
        arr[v].push_back(u);
        arr[u].push_back(v);
    }

    // Remove edge u-v from graph. Replace adjcent vertex value with -1. 
    void removeEdge(int u, int v) { 
        // Find v in adjacency list of u and replace it with -1 
        list<int>::iterator iter_v = find(arr[u].begin(), arr[u].end(), v); 
        *iter_v = -1; 
        
        // Find u in adjacency list of v and replace it with -1 
        list<int>::iterator iter_u = find(arr[v].begin(), arr[v].end(), u); 
        *iter_u = -1; 
    } 
  
 
    // Method to check if all non-zero degree vertices are connected
    bool isConnected() {
            // Mark all the vertices as not visited
            bool visited[N];
            int i;
            for (i = 0; i < N; i++)
                visited[i] = false;
        
            // Find a vertex with non-zero degree
            for (i = 0; i < N; i++)
                if (arr[i].size() != 0)
                    break;
        
            // If there are no edges in the EulerGraph, return true
            if (i == N)
                return true;
        
            // Start DFS traversal from a vertex with non-zero degree
            DFSTraverse(i, visited);
        
            // Check if all non-zero degree vertices are visited
            for (i = 0; i < N; i++)
            if (visited[i] == false && arr[i].size() > 0)
                    return false;
        
            return true;
    }
    
    // Method to check if this EulerGraph is Eulerian or not
    /* The function returns
   0 --> If EulerGraph is not Eulerian
   1 --> If EulerGraph has an Euler path (Semi-Eulerian)
   2 --> If EulerGraph has an Euler Circuit (Eulerian)  */
    int isEulerian() {
        // Check if all non-zero degree vertices are connected
        if (isConnected() == false)
            return 0;
    
        // Count vertices with odd degree
        int odd = 0;
        for (int i = 0; i < N; i++)
            if (arr[i].size() & 1)
                odd++;
    
        // If count is more than 2, then EulerGraph is not Eulerian
        if (odd > 2)
            return 0;
    
        // If odd count is 2, then semi-eulerian.
        // If odd count is 0, then eulerian
        // Note that odd count can never be 1 for undirected EulerGraph
        return (odd)? 1 : 2;
    }

    /* The main function that print Eulerian Trail. It first finds an odd 
   degree vertex and then calls printEulerHelper() to print the path */
    void printEulerTrail() {
        // Find a vertex with odd degree 
        int u = 0; 
        for (int i = 0; i < N; i++) 
            if (arr[i].size() & 1) 
                {   u = i; break;  } 
        
        // Print tour starting from oddv 
        printEulerHelper(u); 
        cout << endl; 
    }

    //print Eulerian tour helper function 
    void printEulerHelper(int u) { 
        // Recur for all the vertices adjacent to this vertex 
        list<int>::iterator i; 
        for (i = arr[u].begin(); i != arr[u].end(); ++i) 
        { 
            int v = *i; 
        
            // If edge u-v is not removed and it's a a valid next edge 
            if (v != -1 && isValidNextEdge(u, v)) 
            { 
                cout << u << "-" << v << "  "; 
                removeEdge(u, v); 
                printEulerHelper(v); 
            } 
        } 
    } 
    // Function to do DFS starting from v. Used in isConnected();
    int DFSTraverse(int v, bool visited[]) {
        // Mark the current node as visited 
        visited[v] = true; 
        //start count 
        int count = 1; 

        // Iterate through all vertices adjacent to this vertex, i
        list<int>::iterator i;
        for (i = arr[v].begin(); i != arr[v].end(); ++i)
            if (*i != -1 && !visited[*i])
                count += DFSTraverse(*i, visited);
        return count; 
    }

    //Function to check if edge u-v is a valid next edge in Eulerian trail 
    bool isValidNextEdge(int u, int v) {
        //The count of adjacent vertices
        int count = 0;  

        //check if v is the only adjacent vertex of u 
        list<int>::iterator iter; 
        
        for (iter = arr[u].begin(); iter != arr[u].end(); iter++) {
            if (*iter != -1) {
                count++;
            }
            if (count == 1)  {
                return true;
            }
        }
        // Check if u-v is a bridge 

        // vertCount1 = Count of vertices reachable from u 
        bool visited[N]; 
        memset(visited, false, N); 
        int vertCount1 = DFSTraverse(u, visited); 
        
        // vertCount2 = Count of vertices reachable from u after removing the edge (u, v)
        removeEdge(u, v); 
        memset(visited, false, N); 
        int vertCount2 = DFSTraverse(u, visited); 
        
        // Add the edge back to the graph
        addEdge(u, v); 
        
        // If there are multiple adjacents, then u-v is not a bridge : 
        //If vertCount1 is greater, then edge (u, v) is a bridge 

        if (vertCount1 > vertCount2) {
            return true;
        } else return false; 

    }

    //tester 
    void testEuler(EulerGraph &g) {
        int res = g.isEulerian();
        if (res == 0)
            cout << "graph is not Eulerian\n";
        else if (res == 1)
            cout << "graph has a Euler path\n";
        else
            cout << "graph has a Euler cycle\n";
    }
};

 




