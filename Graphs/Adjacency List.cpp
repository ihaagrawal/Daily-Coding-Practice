#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges: " << endl;
    cin >> m;

    bool direction;
    cout << "Enter 0 for undirected and 1 for directed: " << endl;
    cin >> direction;

    //storing the adjacency list using a map
    unordered_map<int, vector<int>> adj;
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        if(direction==0) adj[v].push_back(u);
    }

    //printing out the list
    for(auto i:adj){
        cout << i.first << " -> ";
        for(auto j:i.second){
            cout << j << ", ";
        }cout << endl;
    }

    return 0;
}
