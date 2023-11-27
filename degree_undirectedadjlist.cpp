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
void degree(Graph& G, int numvertex) {
    int c,i; 
    for(i=0;i<numvertex;i++){
        c=0;
        Node* current=G.vertices[i];
        cout << "the degree of vertex " << i << " is ";
        while(current!=NULL){
            c=c+1;
            current=current->next;
        }
        cout << c << endl;
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