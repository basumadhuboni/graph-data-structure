#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<list<int>>& vertices, int from, int to) {
    vertices[from].push_back(to);
    vertices[to].push_back(from);
}

bool bipartite(int numVertices, vector<list<int>>& vertices) {
    
    vector<int> color(numVertices, -1);
    // -1 - uncolored, 1 - red, 0 - blue
    color[0] = 1; // red
    
    for (int i = 0; i < numVertices; ++i) {
        for (auto e : vertices[i]) {
            if (color[e] == -1) {
                color[e] = 1 - color[i];
            } else if (color[e] == color[i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Example usage
    int numVertices = 7;
    vector<list<int>> vertices(numVertices);

    // Adding edges to the graph
    addEdge(vertices, 1, 0);
    addEdge(vertices, 1, 3);
    addEdge(vertices,0,2);
    addEdge(vertices, 3, 2);
    

    // Check if the graph is bipartite
    if (bipartite(numVertices, vertices)) {
        cout << "The graph is bipartite.\n";
    } else {
        cout << "The graph is not bipartite.\n";
    }

    return 0;
}
