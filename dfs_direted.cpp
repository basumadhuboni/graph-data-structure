#include <iostream>
#include <vector>

using namespace std;

// Data structure to represent a graph node
struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

// Function to add an edge to the graph
void addEdge(vector<Node*>& vertices, int from, int to) {
    Node* newNode = new Node(to);
    newNode->next = vertices[from];
    vertices[from] = newNode;
}

// Function for Depth-First Search traversal
void DFS(int startVertex, vector<Node*>& vertices, vector<bool>& visited) {
    visited[startVertex] = true;
    cout << startVertex << " ";

    Node* current = vertices[startVertex];
    while (current != nullptr) {
        int nextVertex = current->value;
        if (!visited[nextVertex]) {
            DFS(nextVertex, vertices, visited);
        }
        current = current->next;
    }
}

// Wrapper function for DFS traversal
void DFSTraversal(int numVertices, vector<Node*>& vertices) {
    vector<bool> visited(numVertices, false);

    // Perform DFS from each unvisited vertex
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            DFS(i, vertices, visited);
        }
    }
}

int main() {
    // Example usage
    int numVertices = 5;
    vector<Node*> vertices(numVertices, nullptr);

    // Adding edges to the graph
    addEdge(vertices, 0, 1);
    addEdge(vertices, 0, 2);
    addEdge(vertices, 1, 3);
    addEdge(vertices, 2, 4);

    // Perform DFS traversal
    cout << "DFS Traversal: ";
    DFSTraversal(numVertices, vertices);

    // Cleanup: Free allocated memory
    for (int i = 0; i < numVertices; ++i) {
        Node* current = vertices[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    return 0;
}
