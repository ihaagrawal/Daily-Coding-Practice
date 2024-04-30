// Shortest Path in DAG (MODERATE)
// https://www.naukri.com/code360/problems/shortest-path-in-dag_8381897?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[n];
    for(auto edge:edges){
        int u=edge[0], v=edge[1], w=edge[2];
        adj[u].push_back({v, w});
    }

    vector<int> dist(n, INT_MAX);
    queue<pair<int, int>> q;
    dist[0]=0;
    q.push({0,0});

    while(!q.empty()){
        int num = q.front().first, d = q.front().second;
        q.pop();

        for(auto adjnode: adj[num]){
            int v=adjnode.first, w=adjnode.second;
            if(dist[v]>dist[num]+w){
                dist[v]=dist[num]+w;
                q.push({v, dist[num]+w});
            }
        }
    }

    for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }

        return dist;
}
