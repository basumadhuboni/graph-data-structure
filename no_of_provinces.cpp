#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<list<int>>& vertices, int from, int to) {
    vertices[from].push_back(to);
    vertices[to].push_back(from);
}

// Function for Depth-First Search traversal
void DFS(int i, vector<list<int>>& vertices, vector<bool>& visited) {
    visited[i] = true;
    for (auto e : vertices[i]) {
        if (!visited[e]) {
            DFS(e, vertices, visited);
        }
    }
}

void province(int numVertices, vector<list<int>>& vertices) {
    vector<bool> visited(numVertices, false);
    int ct = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            ct++;
            DFS(i, vertices, visited);
        }
    }
    // we have finished traversing all the vertices
    cout << "Number of provinces is: " << ct << endl;
}

int main() {
    // Example usage
    int numVertices = 9;  // Adjusted the number of vertices
    vector<list<int>> vertices(numVertices);

    // Adding edges to the graph
    addEdge(vertices, 0, 1);
    addEdge(vertices, 1, 2);
    addEdge(vertices, 3, 4);
    addEdge(vertices, 4, 5);
    addEdge(vertices, 5, 6);
    addEdge(vertices, 7, 8);

    // Perform DFS traversal
    province(numVertices, vertices);

    return 0;
}
