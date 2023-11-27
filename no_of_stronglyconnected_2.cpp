#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void addEdge(vector<vector<int>>& adjList, int src, int dest) {
    adjList[src].push_back(dest);
    
}

void DFS(const vector<vector<int>>& adjList, int vertex, vector<bool>& visited) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int neighbor : adjList[vertex]) {
        if (!visited[neighbor]) {
            DFS(adjList, neighbor, visited);
        }
    }
}

void fillOrder(const vector<vector<int>>& adjList, int vertex, vector<bool>& visited, stack<int>& stack) {
    visited[vertex] = true;

    for (int neighbor : adjList[vertex]) {
        if (!visited[neighbor]) {
            fillOrder(adjList, neighbor, visited, stack);
        }
    }

    stack.push(vertex);
}

vector<vector<int>> getTranspose(const vector<vector<int>>& adjList, int vertices) {
    vector<vector<int>> transpose(vertices);

    for (int v = 0; v < vertices; v++) {
        for (int neighbor : adjList[v]) {
            transpose[neighbor].push_back(v);
        }
    }

    return transpose;
}

void printSCCs(const vector<vector<int>>& adjList, int vertices) {
    vector<bool> visited(vertices, false);
    stack<int> stack;

    // Fill vertices in stack according to their finishing times
    for (int v = 0; v < vertices; v++) {
        if (!visited[v]) {
            fillOrder(adjList, v, visited, stack);
        }
    }

    // Create a reversed graph (transpose)
    vector<vector<int>> transpose = getTranspose(adjList, vertices);

    // Mark all vertices as not visited again
    visited.assign(vertices, false);

    // Process all vertices in order defined by stack
    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();

        if (!visited[v]) {
            DFS(transpose, v, visited);
            cout << endl;
        }
    }
}

int main() {
    int vertices = 5;
    vector<vector<int>> adjList(vertices);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 0);
    addEdge(adjList, 2, 4);

    cout << "Strongly Connected Components:\n";
    printSCCs(adjList, vertices);

    return 0;
}
