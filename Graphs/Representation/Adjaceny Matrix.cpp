#include <iostream>
#include <vector>
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

    int adj[n+1][n+1]={0};
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        if(direction==0) adj[v][u]=1; 
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout << adj[i][j] << " ";
        }cout << endl;
    }

    return 0;
}
