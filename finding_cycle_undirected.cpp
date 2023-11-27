#include <iostream>
#include <list>
#include <vector>
using namespace std;

void addEdge(vector<list<int>>& adj, int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool isCyclicUtil(vector<list<int>>& adj, int v, bool visited[], int parent) {
    visited[v] = true;//this vertex has been visited

    for (int i : adj[v]) {// traversing the adj list of that vertex v
        if (!visited[i]) {
            if (isCyclicUtil(adj, i, visited, v)) // i stores the adjacent vertices of that vertex v
                return true;
        }
        else if (i != parent){
           
            return true;}
    }
    return false;
}

bool isCyclic(vector<list<int>>& adj, int V) {
    bool* visited = new bool[V];//array keeps check whether the vertex hass been visited or not
    for (int i = 0; i < V; i++)
        visited[i] = false; // initializing entire array as false as nono of the vertices are visited

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(adj, i, visited, -1))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 5;
    vector<list<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);

    if (isCyclic(adj, V))
        cout << "Graph contains a cycle";
    else
        cout << "Graph doesn't contain a cycle";

    return 0;
}
