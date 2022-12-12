
## Contributors
Sambuddha Biswas and Mia Erdenebileg

# Overview

Our project looks at the wikipedia dataset obtained from http://snap.stanford.edu/data/twitch-social-networks.html. The undirected, unweighted dataset is given through a CSV file and a text, and the data format is __. Our goal was to write a program to find the shortest path between wikipedia articles and find the betweenness centrality of wikipedia.

Our presentation video: __

To compile the code we use the clang++ compiler. The command for compilig is:
``` clang++ main.cpp BFS.cpp centrality.cpp -o Wiki ```

# Repository Layout

## code
This folder contains all of the code written for this project. Details about what subfolders and files contain can be found in code/readme.md

## documents
This contains all of our documents, including the team contract and weekly progress logs. 

## data
This contains all of our data, as well as preprocessing code used to read it into a usable form. 

## BFS for shortest path

### Files: BFS.cpp

## Centrality using brandes algorithm 

### Files: centrality.cpp
