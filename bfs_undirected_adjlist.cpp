#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
    Node* newNode = new Node{to, G.vertices[from]}; //making the destination node whose value will 
    //be equal to the integer value of "to" and will point to "from" node
    G.vertices[from] = newNode;

    newNode = new Node{from, G.vertices[to]};//making source node whose value will 
    // be equal to the integer value of "from" and will point to "to" node
    G.vertices[to] = newNode;
}

// Breadth-First Search function
void BFS(Graph& G, int startVertex) {
    queue<int> q;
    G.visited[startVertex] = 1;
    q.push(startVertex);//index numbers are being pushed 

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << " ";//printing the dfs

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
}

int main() {
    Graph G;
    int numVertices = 5; // Adjust based on your graph

    initializeGraph(G, numVertices);

    // Add edges to the graph
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 1, 3);
    addEdge(G, 2, 4);

    // Perform BFS from vertex 0
    BFS(G, 0);

    return 0;
}