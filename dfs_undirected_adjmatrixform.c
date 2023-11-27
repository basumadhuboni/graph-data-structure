#include <stdio.h>

// Function to perform DFS traversal
void DFS(int graph[5][5], int visited[5], int start) {
    printf("%d ", start);
    visited[start] = 1;
    
    for (int i = 0; i < 5; i++) {
        if (graph[start][i] && !visited[i]) {
            DFS(graph, visited, i);
        }
    }
}

int main() {
    int graph[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };
    
    int visited[5] = {0};
    
    printf("DFS Traversal starting from vertex 0:\n");
    DFS(graph, visited, 0);

    return 0;
}