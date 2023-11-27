#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<list<int>>& vertices, int from, int to) {
    vertices[from].push_back(to);
}

// Function for Depth-First Search traversal
void DFS(int i, stack<int>& s, vector<list<int>>& vertices, vector<bool>& visited) {
    visited[i] = true;
    for (auto e : vertices[i]) {
        if (!visited[e]) {
            DFS(e, s, vertices, visited);
        }
    }
    // this dfs stops when we have reached a child node
    s.push(i); // we push the vertex into the stack when we reach a child node
}

void topo(int numVertices, vector<list<int>>& vertices) {
    vector<bool> visited(numVertices, false);
    stack<int> s;
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            DFS(i, s, vertices, visited);
        }
    }
    // we have finished traversing all the vertices
    cout << "Topological Order Traversal: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    // Example usage
    int numVertices = 7;
    vector<list<int>> vertices(numVertices);

    // Adding edges to the graph
    addEdge(vertices, 1, 0);
    addEdge(vertices, 1, 3);
    addEdge(vertices, 0, 3);
    addEdge(vertices, 3, 2);
    addEdge(vertices, 3, 4);
    addEdge(vertices, 6, 3);
    addEdge(vertices, 6, 5);

    // Perform DFS traversal
    topo(numVertices, vertices);

    return 0;
}