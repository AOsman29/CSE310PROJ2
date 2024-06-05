# Dijkstra's Algorithm Implementation with Custom Containers

Authors: Abdalla Osman & Breck Neal
Course: CSE310, ASU Spring 2024

## Introduction
This project demonstrates the implementation of Dijkstra's algorithm without using built-in containers such as std::vector or arrays. Instead, we have created our own dynamically sized containers: IntVector and BoolVector. These custom containers manage memory and provide essential functionalities required for the algorithm.

Custom Containers
IntVector
IntVector is a dynamically resizable array designed to store integers. It includes the following features:

Dynamic Resizing: The container automatically doubles its capacity when needed.
Deep Copy: Both the copy constructor and the assignment operator perform deep copies to ensure data integrity.
Element Access: Overloaded operator[] provides access to elements with bounds checking.
Push Back: Adds elements to the end of the container, resizing if necessary.
BoolVector
BoolVector is a similar container but specialized for storing boolean values. It includes:

Dynamic Resizing
Deep Copy
Element Access
Push Back
These containers ensure efficient memory management and provide the necessary interface for implementing the algorithm.

Graph Representation
The graph is represented using an adjacency matrix:

Adjacency Matrix: A 2D array adjMatrix stores the edges between vertices. The matrix is initialized such that adjMatrix[i][j] is 0 for no edge and 1 for an edge between vertex i and vertex j.
Dijkstra's Algorithm
The dijkstra method finds the shortest paths from a given source vertex to all other vertices in the graph. It utilizes the custom containers IntVector for distances and BoolVector for the visited status of vertices.

Steps in the Algorithm:
Initialization: Set the distance to the source vertex as 0 and all other distances to infinity.
Find Minimum Distance: In each iteration, select the unvisited vertex with the smallest distance.
Update Distances: For the selected vertex, update the distances to its adjacent vertices if a shorter path is found.
Repeat: Continue until all vertices are processed or the remaining vertices are unreachable.
Helper Functions:
minDistance: Finds the unvisited vertex with the minimum distance.
printSolution: Prints the shortest path distances from the source vertex.
Execution
The program reads the graph from a file specified as a command-line argument. It constructs the graph, prints its adjacency matrix, finds vertices with odd degrees, and applies Dijkstra's algorithm to each of these vertices.

Main Function:
File Input: Reads the number of vertices and edges, and constructs the graph.
Adjacency Matrix: Prints the adjacency matrix.
Odd Degree Vertices: Finds and prints vertices with odd degrees.
Dijkstra's Algorithm: Applies the algorithm to each odd-degree vertex.
Sample Output
yaml
Copy code
The adjacency matrix of G:
0 1 0
1 0 1
0 1 0

The odd degree vertices in G:
O = { 1 3 }

Single source shortest path lengths from node 1
  1: 0
  2: 1
  3: 2

Single source shortest path lengths from node 3
  1: 2
  2: 1
  3: 0
This implementation showcases the use of custom containers for educational purposes, emphasizing manual memory management and algorithm implementation without relying on standard library conveniences.
