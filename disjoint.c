#include <stdio.h>
#define MAX 100

int parent[MAX];
int rank[MAX];
//the indices of the arrays represent the vertices of the graph
void makeSet(int n) {
    // initalizing the arrays
    for (int i = 0; i < n; i++) {
        parent[i] = i; // this array stores the parent (the ultimateparent) of that particular vertex
        rank[i] = 0;// this array stores the height of that verter
    }
}

int find(int x) {
    if (x != parent[x])
        parent[x] = find(parent[x]);// recursively finds the ultimate parent of that vertex and return it
    return parent[x];
}

void unionSets(int x, int y) {
    // finding the ultimate parents of the vertices x and y
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {//x and y belong to diffrent components
        if (rank[rootX] < rank[rootY])  // height of y's tree is more so y becomes parent
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;// if x and y both have same height the height of the parent increases by one
        }
    }
}

int main() {
    int n = 5; // Number of elements
    makeSet(n);

    // Perform some union operations
    unionSets(0, 1);
    unionSets(2, 3);
    unionSets(0, 4);

    // Check if elements belong to the same set
    printf("0 and 2 are in the same set: %s\n", (find(0) == find(2)) ? "true" : "false");
    printf("1 and 4 are in the same set: %s\n", (find(1) == find(4)) ? "true" : "false");

    return 0;
}