#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void dfs(int node, vector<int> &visited,vector<vector<int>> &adj,stack<int> &s){
    visited[node]=1;
    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(i,visited,adj,s);
        }
    }
    s.push(node);
}

void kosarajuUtil(int node,vector<int> &visited,vector<vector<int>> &adjT,stack<int> &s){
    visited[node]=1;
    cout<<node<<" ";
    for(auto it:adjT[node]){
        if(!visited[it]){
            kosarajuUtil(it,visited,adjT,s);
        }
    }
}

int kosaraju(int v,vector<vector<int>> &adj){
    vector<int> visited(v,0);
    stack<int> s;

    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,visited,adj,s);
        }
    }

    vector<vector<int>> adjT(v);
    for(int i=0;i<v;i++){
        visited[i]=0;
        for(int j:adj[i]){
            adjT[j].push_back(i);
        }
    }

    int scc=0;
    while(!s.empty()){
        int node=s.top();
        s.pop();
        if(!visited[node]){
            kosarajuUtil(node,visited,adjT,s);
            scc++;
            cout<<endl;
        }
    }
    return scc;
}

int main(){
    int v,e;
    cout<<"Enter the number of vertices and number of edges you want to have in the graph "<<endl;
    cin>>v>>e;
    vector<vector<int>> adj(v);
    cout<<"Please enter the value of v1 and v2 corresponding to each edge "<<endl;
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);3 2
    }

    cout<<"The strongly connected components are as follows each on separate line"<<endl;
    int ans=kosaraju(v,adj);

    cout<<"The number of strongly connected components in the graph is "<<ans<<endl;

    if(ans==1){
        cout<<"The directed graph is a strongly connected graph "<<endl;
    }else{
        cout<<"The given graph is not a strongly connected graph "<<endl;
    }
    return 0;
}