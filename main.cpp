#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

using namespace std;

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

    void dijkstra(int src) {
        int dist[vertices];
        bool visited[vertices];

        for (int i = 0; i < vertices; i++) {
            dist[i] = INF;
            visited[i] = false;
        }

        dist[src] = 0;

        for (int count = 0; count < vertices - 1; count++) {
            int u = minDistance(dist, visited);
            visited[u] = true;

            for (int v = 0; v < vertices; v++)
                if (!visited[v] && adjMatrix[u][v] && dist[u] != INF && dist[u] + adjMatrix[u][v] < dist[v])
                    dist[v] = dist[u] + adjMatrix[u][v];
        }

        printSolution(dist, src);
    }

private:
    int minDistance(int dist[], bool visited[]) {
        int min = INF, min_index;
        for (int v = 0; v < vertices; v++)
            if (visited[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;
        return min_index;
    }

    void printSolution(int dist[], int src) {
        cout << "Single source shortest path lengths from node " << src + 1 << endl;
        for (int i = 0; i < vertices; i++)
            cout << "  " << i + 1 << ": " << ((dist[i] == INF) ? "INF" : to_string(dist[i])) << endl;
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

    // You should determine odd degree vertices and call dijkstra for each of them
    // Here we call dijkstra from a single source for simplicity
    g.dijkstra(0);  // Running dijkstra from vertex 0 (adjust according to your needs)

    return 0;
}
