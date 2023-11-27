#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int rad = INT_MAX;  // Corrected from INT_MIN to INT_MAX
int dia = INT_MIN;  // Corrected from INT_MAX to INT_MIN

// Data structure to represent a graph node
struct Node {
    int value;
    Node* next;
};

// Data structure to represent a graph
struct Graph {
    vector<Node*> vertices;
    vector<int> visited;
    int numVertices;
};

// Function to initialize a graph
void initializeGraph(Graph& G, int numVertices) {
    G.numVertices = numVertices;
    G.vertices.resize(numVertices, nullptr);
    G.visited.resize(numVertices, 0);
}

// Function to add an edge to the graph
void addEdge(Graph& G, int from, int to) {
    Node* newNode = new Node{to, G.vertices[from]};
    G.vertices[from] = newNode;
}

// Breadth-First Search function
void BFS(Graph& G, int startVertex) {
    queue<int> q;
    G.visited[startVertex] = 1;
    q.push(startVertex);
    int minDist = 0;  // Corrected variable name from min to minDist
    int maxDist = INT_MIN;  // Corrected from INT_MAX to INT_MIN

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        minDist++;
        maxDist = max(maxDist, minDist);

        Node* current = G.vertices[currentVertex];
        while (current != nullptr) {
            int nextVertex = current->value;
            if (G.visited[nextVertex] == 0) {
                G.visited[nextVertex] = 1;
                q.push(nextVertex);
            }
            current = current->next;
        }
    }

    if (minDist < rad) {
        rad = minDist;
    }
    if (maxDist > dia) {
        dia = maxDist;
    }
}

int main() {
    Graph G;
    int numVertices = 5;
    int i;
    initializeGraph(G, numVertices);

    // Add edges to the graph
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 1, 3);
    addEdge(G, 2, 4);

    // Perform BFS from each vertex
    for (i = 0; i < numVertices; i++) {
        // fill(G.visited.begin(), G.visited.end(), 0);
        BFS(G, i);
    }

    cout << "Radius is " << rad << endl;
    cout << "Diameter is " << dia << endl;

    return 0;
}