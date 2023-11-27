#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
};

struct Graph {
    int V;
    struct AdjList* array;
};

struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; ++i) {
        struct Node* temp = graph->array[i].head;
        printf("Adjacency list of vertex %d\n", i);
        while (temp) {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

struct Graph* getTranspose(struct Graph* graph) {
    struct Graph* transposeGraph = createGraph(graph->V);
    for (int i = 0; i < graph->V; ++i) {
        struct Node* temp = graph->array[i].head;
        while (temp) {
            addEdge(transposeGraph, temp->dest, i);
            temp = temp->next;
        }
    }
    return transposeGraph;
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 3);
    addEdge(graph, 2, 0);
    addEdge(graph, 3, 2);
    addEdge(graph, 4, 1);
    addEdge(graph, 4, 3);

    printf("Original Graph:\n");
    printGraph(graph);

    struct Graph* transposeGraph = getTranspose(graph);
    printf("\nTranspose of the Graph:\n");
    printGraph(transposeGraph);

    return 0;
}