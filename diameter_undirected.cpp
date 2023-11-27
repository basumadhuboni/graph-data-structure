#include <iostream>
#include <list>
#include <vector>
#include <limits.h>
using namespace std;

void addEdge(vector<list<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<list<int>>& adj, int v, bool visited[], int dist, int& maxDist, int& farthestVertex) {
    visited[v] = true;

    if (dist > maxDist) {
        maxDist = dist;
        farthestVertex = v;
    }

    for (int u : adj[v]) { // traversing adjacency list of vetex v
        if (!visited[u]) {
            dfs(adj, u, visited, dist + 1, maxDist, farthestVertex);
        }
    }
}

int diameter(vector<list<int>>& adj, int V) {
    int maxDist = INT_MIN;
    int farthestVertex = 0;

    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    dfs(adj, 0, visited, 0, maxDist, farthestVertex); // we pass addresses of the farthest vertex and integer storing max dist

    for (int i = 0; i < V; i++)
        visited[i] = false;

    maxDist = INT_MIN;

    dfs(adj, farthestVertex, visited, 0, maxDist, farthestVertex);

    delete[] visited;

    return maxDist;
}

int main() {
    int V = 6;
    vector<list<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);

    int diam = diameter(adj, V);

    cout << "The diameter of the graph is: " << diam << endl;

    return 0;
}