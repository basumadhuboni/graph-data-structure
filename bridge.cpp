#include <iostream>
#include <vector>

using namespace std;

void DFS(int u, int parent, int& time, vector<int>& disc, vector<int>& low, vector<vector<int>>& adjList, vector<pair<int, int>>& bridges) {
    disc[u] = low[u] = ++time;

    for (int v : adjList[u]) {
        if (v == parent) {
            continue; // Skip the edge back to the parent
        }

        if (disc[v] == -1) {
            DFS(v, u, time, disc, low, adjList, bridges);
            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u]) {
                bridges.push_back({u, v});
            }
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findBridges(int numVertices, vector<vector<int>>& adjList, vector<pair<int, int>>& bridges) {
    int time = 0;
    vector<int> disc(numVertices, -1); //array of discovery time
    vector<int> low(numVertices, -1); // array of low values

    for (int i = 0; i < numVertices; ++i) {
        if (disc[i] == -1) {
            DFS(i, -1, time, disc, low, adjList, bridges);
        }
    }

    cout << "Bridges in the graph:\n";
    for (const auto& bridge : bridges) {
        cout << bridge.first << " - " << bridge.second << "\n";
    }
}

int main() {
    // Example usage
    int numVertices = 5;
    vector<vector<int>> adjList(numVertices);

    // Adding edges to the graph
    adjList[0].push_back(1);
    adjList[1].push_back(2);
    adjList[2].push_back(0);
    adjList[1].push_back(3);
    adjList[3].push_back(4);

    vector<pair<int, int>> bridges;
    findBridges(numVertices, adjList, bridges);

    return 0;
}
