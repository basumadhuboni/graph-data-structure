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
    vector<int> indegree;
    vector<int> outdegree;
    int numVertices;
};

// Function to initialize a graph
void initializeGraph(Graph& G, int numVertices) {
    G.numVertices = numVertices;
    G.vertices.resize(numVertices, nullptr);
    G.visited.resize(numVertices, 0);
    G.indegree.resize(numVertices, 0);
    G.outdegree.resize(numVertices, 0);
}

// Function to add an edge to the graph
void addEdge(Graph& G, int from, int to) {
    Node* newNode = new Node{to, G.vertices[from]}; //making the destination node whose value will 
    //be equal to the integer value of "to" and will point to "from" node
    G.vertices[from] = newNode;
    G.indegree[to]++;
    G.outdegree[from]++;
}

void degree(Graph& G, int numvertex) 
{
    int i;
    for(i=0;i<numvertex;i++){
      cout << "indergree for vertex " << i << " is " << G.indegree[i];
      cout << " outdergree for vertex " << i << " is " << G.outdegree[i] << endl;
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

    degree(G,numVertices);

    return 0;
}