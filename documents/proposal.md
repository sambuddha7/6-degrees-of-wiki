
## Leading Question
Wikipedia can be modeled as a directed graph as follows: each page is represented by a vertex and each link from one page to another is represented by a directed edge. Using this representation we can ask the question, what would the shortest path between any two wikipedia articles be? With the tools to answer that we can then ask what is the diameter of wikipedia? In practical terms, given any page what is the maximum number of links one would have to follow to get to any other page? We can also examine what nodes are frequently passed through on traversals. What nodes are infrequently visited? In specific: what is the betweenness centrality of each node? 

## Algorithms: 
1. **In order to find the shortest path between any two nodes:**  
Breadth first search from start to end.  
Time complexity: O(n), Space requirement: O(n)  
Inputs: directed unweighted graph, start node, end node.  
Outputs: A set of equal length shortest paths from the start to the end page.  
2. **To find the span of the graph:**  
For each node run BFS and return longest. Return max over the nodes.  
Time complexity: O(n^2), Space requirement O(n)  
Inputs: directed unweighted graph  
3. **For finding betweenness centrality: **  
**Fast Approximate Betweenness Centrality:** KADABRA (from KADABRA is an ADaptive Algorithm for Betweenness via Random Approximation)
Time Complexity: m^(0.5 + O(1))  
Inputs: directed unweighted graph  
**Exact Betweenness Centrality:** Brandes' Algorithm  
Time Complexity: O(mn)  
Inputs: directed unweighted graph  

## Dataset Acquisition and Cleaning
We will use the Stanford Network Analysis Project dataset of wikipedia circa 2013, as well as publicly available dumps from both Simple English WIkipedia and the full English Language Wikipedia project. The SNAP dataset is already formatted as a directed graph, while publicly available dumps are compressed xml and html. The SNAP dataset also includes node labels. We will process the xml/html files to extract a labeled directed unweighted graph for our usage. The graph will be stored as an adjacency list, and as such with have storage requirements of O(n + m) where n is the number of pages and m the number of links. The only form of error correction we will do is ensure that a page can not link to itself. Effort will not necessarily be made to keep our graphs up to date with the publicly available wikipedia project at wikipedia.org. 


## Timeline
Week 1 goals: (11/03 - 11/10)
 - Create infrastructure to process data into a usable form. 
 - Create an efficient graph representation 
 - Start work on BFS between two nodes

Week 2 goals: (11/10 - 11/17)
 - Complete work on BFS
 - Find shortest algorithm work
 - Diameter algorithm done. 

Week 3 goals: (11/17 - 11/24)
 - Start implementation of Brandes' Algorithm
 - Start implementation of KADABRA  

Week 4 goals: (11/24 - 12/01)
 - Finish implementation of betweenness centrality algorithms 
 - Analysis of results. 
 - Visualization of results. 

Week 5 (12/01 - 12/07) 
 - Writeup
 - Presentation

