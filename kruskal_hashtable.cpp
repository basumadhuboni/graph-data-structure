#include <iostream>
#include <unordered_map>
using namespace std;
struct Node {
    int data;
    Node* parent;
    int rank;
};
struct edge{
   int vertex1;
   int vertex2;
   int length;
};
unordered_map<int, Node*> nodes;

void merge(struct edge arr[], int lb, int mid, int ub) {//the array a[]has two sorted subarrays within itself
    int i = lb;
    int j = mid + 1;
    int k = lb;
    struct edge a[ub + 1];//creating a temporary array for storing sorted elements
    
    while (i <= mid && j <= ub) {// i will run till mid and j will run from mid+1 till end
        // merging and sorting the two sorted subarrays  and storing it in a[]
        if (arr[i].length <= arr[j].length) {
            a[k] = arr[i];
            i++;
        } else {
            a[k] = arr[j];
            j++;
        }
        k++;
    }
    // for storing the remaining elements from the subarryas
    if (i > mid) {// but j is<ub
        while (j <= ub) {
            a[k] = arr[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {// but i<mid
            a[k] = arr[i];
            i++;
            k++;
        }
    }
    //copying back elemts from temp array a[] to org array arr[]
    for (int x = lb; x <= ub; x++) {
        arr[x] = a[x];
    }
}

void merge_sort(struct edge arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        //sorting the subarrays
        merge_sort(arr, lb, mid);
        merge_sort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

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

void unionSets(int data1, int data2) {
    Node* node1 = nodes[data1];
    Node* node2 = nodes[data2];

    Node* parent1 = findSet(node1);
    Node* parent2 = findSet(node2);

    /*if (parent1 == parent2)
        return false;*/

    if (parent1->rank >= parent2->rank) {
        parent1->rank=parent1->rank+1;
        parent2->parent = parent1;
    } else {
        parent1->parent = parent2;
        parent2->rank=parent2->rank+1;
    }

    //return true;
}

int main() {
    int i,v,e,v1,v2,l;
    cout << "enter no of vertices ";
    cin >> v;
    for(i=0;i<v;i++){
        makeSet(i); //creating the sets with single elements(vertices)
    }
    cout << "enter the no of edges ";
    cin >> e;
    struct edge arr[e];
    for(i=0;i<e;i++){
        cout << "enter the connecting vertices for edge " << (i+1);
        cin >> v1 >> v2;
        cout << "enter the edge length ";
        cin >> l;
        arr[i].vertex1=v1;
        arr[i].vertex2=v2;
        arr[i].length=l;
    }
    // sorting depending on edge length;
    merge_sort(arr,0,(e-1));
    // printing the sorted vertices
    for(i=0;i<e;i++){
        cout << arr[i].vertex1 << " " << arr[i].vertex2 << " " << arr[i].length << endl;
    }
    // merging sets
    for(i=0;i<e;i++){
       unionSets(arr[i].vertex1,arr[i].vertex2);
    }
     cout << nodes[3]->parent->data;
    /*unionSets(1, 2);
    unionSets(3, 4);
    unionSets(1, 3);*/
    return 0;
}