#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int vertices, vector<vector<int>>& adjList) {
    vector<int> result;
    vector<int> inDegree(vertices, 0);

    // Calculate in-degrees
    for (int i = 0; i < vertices; ++i) {
        for (int neighbor : adjList[i]) {
            inDegree[neighbor]++;
        }
    }

    queue<int> q;

    // Enqueue vertices with in-degree 0
    for (int i = 0; i < vertices; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        result.push_back(currentVertex);

        for (int neighbor : adjList[currentVertex]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (result.size() != vertices) {
        cout << "Graph contains a cycle, topological sort not possible." << endl;
        return {};
    }

    return result;
}

int main() {
    int vertices = 6;
    vector<vector<int>> adjList(vertices);

    // Add edges to the adjacency list
    adjList[5].push_back(2);
    adjList[5].push_back(0);
    adjList[4].push_back(0);
    adjList[4].push_back(1);
    adjList[2].push_back(3);
    adjList[3].push_back(1);

    cout << "Topological Sort: ";
    vector<int> result = topologicalSort(vertices, adjList);
    for (int vertex : result) {
        cout << vertex << " ";
    }

    return 0;
}
