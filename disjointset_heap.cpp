#include <iostream>
#include <vector>

// Initialize sets with single elements
void initializeSets(std::vector<int>& parent, std::vector<int>& rank) {
    for (int i = 0; i < parent.size(); ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find the representative element of the set containing x with path compression
int find(std::vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]); // Path compression
    }
    return parent[x];
}

// Union two sets based on rank to maintain balance
void unionSets(std::vector<int>& parent, std::vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Print the representative element of each set
void printSets(const std::vector<int>& parent) {
    for (int i = 0; i < parent.size(); ++i) {
        std::cout << "Element " << i << " belongs to set with representative element: " << find(parent, i) << std::endl;
    }
}

int main() {
    // Create a disjoint-set with 6 elements
    int size = 6;
    std::vector<int> parent(size);
    std::vector<int> rank(size);

    // Initialize sets
    initializeSets(parent, rank);

    // Perform union operations
    unionSets(parent, rank, 0, 1);
    unionSets(parent, rank, 1, 2);
    unionSets(parent, rank, 3, 4);

    // Print the representative elements of sets
    printSets(parent);

    return 0;
}
