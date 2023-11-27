#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

void addEdge(vector<list<int>>& adjList, int from, int to) {
    adjList[from].push_back(to);
}

void DFS(int v, vector<list<int>>& adjList, vector<bool>& visited, stack<int>& order) {
    visited[v] = true;
    for (int neighbor : adjList[v]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adjList, visited, order);
        }
    }
    order.push(v);
}

void DFSReverse(int v, vector<list<int>>& reverseAdjList, vector<bool>& visited) {
    visited[v] = true;
    for (int neighbor : reverseAdjList[v]) {
        if (!visited[neighbor]) {
            DFSReverse(neighbor, reverseAdjList, visited);
        }
    }
}

bool isStronglyConnected(int numVertices, vector<list<int>>& adjList) {
    // Step 1: Perform DFS and store the order of vertices in a stack
    stack<int> order;
    vector<bool> visited(numVertices, false);
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            DFS(i, adjList, visited, order);
        }
    }

    // Step 2: Reverse the graph
    vector<list<int>> reverseAdjList(numVertices); // making the adj list of the reversed graph
    for (int i = 0; i < numVertices; ++i) 
    {
        for (int neighbor : adjList[i]) {
            reverseAdjList[neighbor].push_back(i);
        }
    }

    // Step 3: Perform DFS on the reversed graph using the order obtained in Step 1
    
    fill(visited.begin(), visited.end(), false); // resetting the visited array
    while (!order.empty()) {
        int v = order.top();
        order.pop();
        if (!visited[v]) {
            DFSReverse(v, reverseAdjList, visited);
            break;  // Break after the first DFS on the reversed graph
        }
    }

    // Step 4: Check if all vertices are visited in the reversed graph
    for (bool vertexVisited : visited) {
        if (!vertexVisited) {
            return false;
        }
    }

    // If all vertices are visited in both directions, the graph is strongly connected
    return true;
}

int main() {
    // Example usage
    int numVertices = 5;
    vector<list<int>> adjList(numVertices);

    // Adding edges to the directed graph
    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 0);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 3, 4);

    if (isStronglyConnected(numVertices, adjList)) {
        cout << "The directed graph is strongly connected.\n";
    } else {
        cout << "The directed graph is not strongly connected.\n";
    }

    return 0;
}
