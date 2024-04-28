///Made by: Abdalla Osman & Breck Neal
//CSE310 ASU Spring 2024

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <cassert>
#define INF INT_MAX

using namespace std;

#include <iostream>
#include <cassert> // For assert in operator[]
//vector container
template<typename T>
class IntVector {
private:
    int* data;      // Pointer to the array of integers
    size_t capacity; // Total capacity of the allocated array
    size_t size;     // Current number of elements in the array

public:
 // Default constructor
    IntVector() : capacity(10), size(0) {  // Default capacity can be set to a reasonable starting value
        data = new T[capacity];
    }
    // Constructor that also initializes elements to a default value
    IntVector(size_t initial_size, int default_value) : capacity(initial_size), size(initial_size) {
        data = new int[capacity];
        for (size_t i = 0; i < size; i++) {
            data[i] = default_value;
        }
    }

    // Destructor
    ~IntVector() {
        delete[] data;
    }

    // Copy constructor (deep copy)
    IntVector(const IntVector& other) : capacity(other.capacity), size(other.size) {
        data = new int[capacity];
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Assignment operator (deep copy)
    IntVector& operator=(const IntVector& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            size = other.size;
            data = new int[capacity];
            for (size_t i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Access elements
    int& operator[](size_t index) {
        assert(index < size); // Ensure index is within the current size
        return data[index];
    }

    const int& operator[](size_t index) const {
        assert(index < size); // Ensure index is within the current size
        return data[index];
    }

    // Add elements
    void push_back(int value) {
        if (size >= capacity) {
            resize(capacity * 2); // Double the capacity if needed
        }
        data[size++] = value;
    }

    // Get size
    size_t get_size() const {
        return size;
    }

    // Helper function to resize the array
    void resize(size_t new_capacity) {
        if (new_capacity > capacity) {
            int* new_data = new int[new_capacity];
            for (size_t i = 0; i < size; i++) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
    }
};
//bool vector container
template<typename T>
class BoolVector {
private:
    bool* data;      // Pointer to the array of booleans
    size_t capacity; // Total capacity of the allocated array
    size_t size;     // Current number of elements in the array

public:
    // Constructor
     // Constructor that also initializes all elements to a given value
    BoolVector(size_t initial_size, T initial_value = T()) : capacity(initial_size), size(initial_size) {
        data = new T[capacity];
        for (size_t i = 0; i < size; i++) {
            data[i] = initial_value;
        }
    }

    // Destructor
    ~BoolVector() {
        delete[] data;
    }

    // Copy constructor (deep copy)
    BoolVector(const BoolVector& other) : capacity(other.capacity), size(other.size) {
        data = new bool[capacity];
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Assignment operator (deep copy)
    BoolVector& operator=(const BoolVector& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            size = other.size;
            data = new bool[capacity];
            for (size_t i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Access elements
    bool& operator[](size_t index) {
        assert(index < size); // Ensure index is within the current size
        return data[index];
    }

    const bool& operator[](size_t index) const {
        assert(index < size); // Ensure index is within the current size
        return data[index];
    }

    // Add elements
    void push_back(bool value) {
        if (size >= capacity) {
            resize(capacity * 2); // Double the capacity if needed
        }
        data[size++] = value;
    }

    // Get size
    size_t get_size() const {
        return size;
    }

    // Helper function to resize the array
    void resize(size_t new_capacity) {
        if (new_capacity > capacity) {
            bool* new_data = new bool[new_capacity];
            for (size_t i = 0; i < size; i++) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
    }
};

class Graph {
public:
    int vertices;
    int** adjMatrix;

    Graph(int v) : vertices(v) {
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = (i == j) ? 0 : INF;
            }
        }
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    void addEdge(int src, int dest) {
        // Since it's an undirected graph
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }
    void printAdjacencyMatrix(){
        cout<< "\nThe adjacency matrix of G:\n";
        for(int i = 0; i < vertices;i++){
            for(int j = 0; j < vertices; j++){
                cout<<(adjMatrix[i][j] == INF ? 0 : adjMatrix[i][j]) << " ";
            }
            cout<<endl;
        }
    }
   IntVector<int> findOddDegreeVertices() {
    
    IntVector<int> degrees(vertices, 0);  // Assuming your IntVector supports initialization with size and default value
    IntVector<int> oddDegreeVertices;     // To store vertices with odd degrees

    // Calculate the degrees of each vertex
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (adjMatrix[i][j] == 1) {  // Assuming adjMatrix[i][j] == 1 represents an edge
                degrees[i]++;
            }
        }
    }

    // Collect odd degree vertices
    cout << "The odd degree vertices in G:\nO = { ";
    bool first = true;
    for (int i = 0; i < vertices; i++) {
        if (degrees[i] % 2 != 0) {  // Check if the degree is odd
            if (!first) cout << " ";
            cout << i + 1;  // Output 1-based index
            oddDegreeVertices.push_back(i + 1);  // Store 1-based index
            first = false;
        }
    }
    cout << " }\n";

    return oddDegreeVertices;  // Return the collection of odd-degree vertices
}


    void dijkstra(int src) {
    IntVector<int> dist(vertices, INF);
    BoolVector<bool> visited(vertices, false);
    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, visited);
        if (u == -1 || dist[u] == INF) break;  // No valid minimum distance or remaining vertices unreachable

        visited[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && adjMatrix[u][v] != INF && dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    printSolution(dist, src);
}

private:
    int minDistance(const IntVector<int>& dist, const BoolVector<bool>& visited) {
    int min = INF, min_index = -1;
    for (int v = 0; v < dist.get_size(); v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}


   void printSolution(const IntVector<int>& dist, int src) {
    cout << "Single source shortest path lengths from node " << src + 1 << endl;
    for (int i = 0; i < dist.get_size(); i++) { // Use dist.size() instead of vertices
        if (dist[i] == INF) {
            cout << "  " << i + 1 << ": Unreachable" << endl;
        } else {
            cout << "  " << i + 1 << ": " << dist[i] << endl;
        }
    }
}
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <graph.txt>" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if (!file) {
        cout << "File could not be opened." << endl;
        return 1;
    }

    int n, m;
    file >> n >> m;

    Graph g(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        file >> u >> v;
        g.addEdge(u - 1, v - 1); // adjusting 1-based index
    }
    file.close();  // It's good practice to close the file after done reading

    // Print the adjacency matrix of the graph
    g.printAdjacencyMatrix();

    // Find odd-degree vertices and store them
    IntVector<int> oddDegreeVertices = g.findOddDegreeVertices();

for (int i = 0; i < oddDegreeVertices.get_size(); i++) {
    int vertex = oddDegreeVertices[i];
    g.dijkstra(vertex - 1);  // Adjust for 0-based index if necessary
}

    return 0;
}
