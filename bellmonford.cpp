#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to perform the Bellman-Ford algorithm
void bellmanFord(vector<Edge>& edges, int numVertices, int source) {
    vector<int> distance(numVertices, INT_MAX); // forstoring min dist needed to reach that vertex
    distance[source] = 0;

    // Relax edges repeatedly
    for (int i = 1; i < numVertices; ++i) {
        for (const Edge& edge : edges) {
            if (distance[edge.src] != INT_MAX && distance[edge.src] + edge.weight < distance[edge.dest]) {
                distance[edge.dest] = distance[edge.src] + edge.weight;
            }
        }
    }

    // Check for negative weight cycles
    for (const Edge& edge : edges) {
        if (distance[edge.src] != INT_MAX && distance[edge.src] + edge.weight < distance[edge.dest]) { //here we do jut one iterartion
            cout << "Graph contains negative weight cycle. Bellman-Ford cannot solve this case.\n";
            return;
        }
    }

    // Print the distances
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": " << distance[i] << "\n";
    }
}

int main() {
    // Example usage
    int numVertices = 5;
    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int source = 0;
    bellmanFord(edges, numVertices, source);

    return 0;
}
