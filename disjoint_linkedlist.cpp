#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* parent;
    int rank;
};

unordered_map<int, Node*> nodes;

void makeSet(int data) {
    Node* node = new Node();
    node->data = data;
    node->parent = node;
    node->rank = 0;
    nodes[data] = node;
}

Node* findSet(Node* node) {
    if (node != node->parent)
        node->parent = findSet(node->parent);
    return node->parent;
}

bool unionSets(int data1, int data2) {
    Node* node1 = nodes[data1];
    Node* node2 = nodes[data2];

    Node* parent1 = findSet(node1);
    Node* parent2 = findSet(node2);

    if (parent1 == parent2)
        return false;

    if (parent1->rank >= parent2->rank) {
        parent1->rank=parent1->rank+1;
        parent2->parent = parent1;
    } else {
        parent1->parent = parent2;
        parent2->rank=parent2->rank+1;
    }

    return true;
}

int main() {
    // Create sets
    makeSet(1);
    makeSet(2);
    makeSet(3);
    makeSet(4);

    // Merge sets
    unionSets(1, 2);
    unionSets(3, 4);
    unionSets(1, 3);

    // Check if elements are in the same set
    cout << (findSet(nodes[1]) == findSet(nodes[4])) << endl; // Output: 1 (true)

    return 0;
}