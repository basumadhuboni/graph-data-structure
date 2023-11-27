#include <iostream>
#include <vector>
#include <list>
#include <climits>
using namespace std;

const int INF = INT_MAX;

struct Edge {
    int u, v, weight;

     Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {} //constructor 
};

struct Vertex {
    int vertexId; // indicates the ultimate parent of that vertex
    int key;// indicates the shortest distance needed to go to that vertex from the source node
    int predecessor;

     Vertex(int vertexId, int key, int predecessor) : vertexId(vertexId), key(key), predecessor(predecessor) {} // constructor
};

void addEdge(vector<list<Edge>>& adjList, int u, int v, int weight) {
    adjList[u].push_back(Edge(u, v, weight)); // assigning values to edge using constructor call
}

void Dijkstra(vector<Vertex>& vertices, vector<list<Edge>>& adjList, int noVertices) {
    list<int> S; // for storingsource nodes
    list<int> S_Prime; // for storing nodes that have not been added to source nodes list

    for (int i = 0; i < noVertices; i++) {
        S_Prime.push_back(i); // adding all the vertices to S_Prime as iniatially none is added to source nodes
    }

    vertices[0].key = 0; //initializing the source node as 0

    while (!S_Prime.empty()) { // keep traversing till all nodes have been added to source node array
        int u = S_Prime.front(); // initializing the first vertex of S_Prime as having min key value,we will update it in the loop below
        for (int vertex : S_Prime) {  // traversing the adj list of  vertex u(vertex with min key value) 
            if (vertices[vertex].key < vertices[u].key) {
                u = vertex; // if any of u's neighbour has key value less than u then u becomes that neighbour vertex
            }
        }

        S.push_back(u); // we add the vertex having min key value to list of source nodes and remove it from S_Prime
        S_Prime.remove(u);

        for (Edge& edge : adjList[u]) { // traversing the adj list of the vertices of the  graph
            int v = edge.v;
            int weight = edge.weight;
             // if the neighbour of the current min vertex u has key value greater than u's key value+their connecting edge length
             // then we update the key value of the neighbour with that smallerr value and update its predecessor as u
            if (vertices[v].key > vertices[u].key + weight) {
                vertices[v].key = vertices[u].key + weight;
                vertices[v].predecessor = u;
            }
        }
    }

    cout << "\nVertices = [";
    for (const Vertex& vertex : vertices) {
        cout << "{vertexId=" << vertex.vertexId << ", key=" << vertex.key << ", predecessor=" << vertex.predecessor << "}, ";
    }
    cout << "]" << endl;
}

int main() {
    int n = 5;
    vector<list<Edge>> adjList(n);
    vector<Vertex> vertices(n, Vertex(0, INF, -1)); // we cant initialize with a triplet ere so we use constructor

    addEdge(adjList, 0, 1, 1);
    addEdge(adjList, 0, 4, 5);
    addEdge(adjList, 1, 2, 2);
    addEdge(adjList, 1, 3, 7);
    addEdge(adjList, 2, 3, 3);
    addEdge(adjList, 4, 1, 6);
    addEdge(adjList, 4, 3, 4);

    cout << "Adjancy list is..." << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex-" << i << ": [";
        for (const Edge& edge : adjList[i]) {
            cout << "{u=" << edge.u << ", v=" << edge.v << ", weight=" << edge.weight << "}, ";
        }
        cout << "]" << endl;
    }
    cout << endl;

    Dijkstra(vertices, adjList, n);

    return 0;
}