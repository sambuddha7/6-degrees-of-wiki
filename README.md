
## Contributors
Sambuddha Biswas and Mia Erdenebileg

# Overview

Our project looks at the wikipedia dataset obtained from http://snap.stanford.edu/data/twitch-social-networks.html. The undirected, unweighted dataset is given through a CSV file and a text, and the data format is an unordered map with a node mapping to an adjacency list . Our goal was to write a program to find the shortest path between wikipedia articles and to check whether the graph contains a eulerian cycle or path to check the efficiency of traversals such that the same node isn’t traversed over twice.
To compile the code we use the clang++ compiler. The command for compiling is:
``` clang++ main.cpp BFS.cpp dataparsing.cpp eulerian.cpp test.cpp -o wiki ```

And to get the output on the console we input two articles such as “Hitler” , “Pikachu”
```./wiki "Hitler" "Pikachu"	```

### Presentation video:

https://www.youtube.com/watch?v=85v2-yvjIPg
# Repository Layout

## code
This folder contains all of the code written for this project. Details about what subfolders and files contain can be found in code/readme.md

## documents
This contains all of our documents, including the team contract and weekly progress logs. 

## data
This contains all of our data, as well as preprocessing code used to read it into a usable form. 

## Testing

All testing was done through main.cpp. All the test cases are in test.cpp
## BFS for shortest path 


### Files: BFS.cpp

We create a graph object and then input two nodes in the graph the starting and the end node. We find the shortest path from the starting node to the end node using an iterative bfs traversal using queues. The output is a vector of nodes containing the shortest path which is outputted in the console log.

Eulerian Path: 

Files: eulerian.cpp 

Input : An undirected graph with number of vertices and a dynamic array of adjacency 
Output: Eulerean paths and cycles and Eulerean tour starting from odd vertex 
 
Given the undirected graph that includes the number of vertices and a dynamic array of adjacency list, we determine if there are eulerian cycles or eulerian paths and then print the eulerian trail. 
 
An undirected graph has Eulerian cycle if: 
 
All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to the Eulerian Cycle or Path (we only consider all edges).
All vertices have even degree.
 
An undirected graph has Eulerian Path if: 
Same first condition for Eulerian Cycle and 
If zero or two vertices have odd degree and all other vertices have even degree. 
 
We are also counting that a graph with no edges is considered Eulerian because there are no edges to traverse.
 
How it works: 
In the Eulerian path, each time we visit a vertex, we walk through two unvisited edges with one endpoint as v. Therefore, all middle vertices in the Eulerian Path must have even degree.
For the Eulerian Cycle, any vertex can be a middle vertex, therefore all vertices must have even degree.
 
In our implementation: 
We implemented the following: isConnected, isEulerian, and printEulerTour(). 
 
We compute a function to do DFS which will be used in isConnected() function which is a Method to check if all non-zero degree vertices are connected.
The isEulerian function returns
  0 --> If graph is not Eulerian
  1 --> If graph has an Euler path (Semi-Eulerian)
  2 --> If graph has an Euler Circuit (Eulerian) 
 
The printEulerTour is the main function that prints the Eulerian Trail. It first finds an odd degree vertex (if there is any) and then calls its helper function printEulerUtil()to print the path 
 
time complexity: polynomial time : O(V+E)




## DFS for graph traversal: 

Field: eulerean.cpp 

DFS - void DFSUtil(int v, bool visited[])
 
DFS function used to traverse the graph which will be used in isConnected() function to check if all non-zero degree vertices are connected. In the DFS algorithm, we mark the current node as visited and print that node and we recur the same procedure for all vertices adjacent to our current vertex. This function will be used inside isConnected() function to continue DFS traversal from an avertex with non-zero degree every time we find one that exists inside our isConnected function. 

## Results: 

### Eulerean path and cycle: 
 
For the small amount of dataset we retrieved from the large dataset we found there to be several eulerian cycles and paths considering there were many vertices with an even degree. Eulerian paths however were less common considering that it is not often that there are zero or two vertices with odd degree and all other vertices have even degree. We also took into account that only one vertex with odd degree is not possible in an undirected graph. 



### BFS
It was found that the highest degree of separation was 6.
Even irrelevant articles such as “Hitler” and “Pikachu” had a 3 degree of separation.

## Areas we would like to improve
Implement a non case sensitive input program
Since the data is huge, we could improve the data parsing by only parsing through more central nodes by using betweenness centrality algorithms which would’ve been possible with a bigger team.

