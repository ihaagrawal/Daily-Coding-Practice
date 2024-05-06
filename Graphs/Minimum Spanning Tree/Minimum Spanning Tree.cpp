// Minimum Spanning Tree (MODERATE)
// https://www.naukri.com/code360/problems/minimum-spanning-tree_631769?leftPanelTabValue=PROBLEM


//PRIM'S Algorithm (giving TLE)
#include <bits/stdc++.h>
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    vector<vector<int>> adj[n];
    for(auto edge:edges){
        int u=edge[0], v=edge[1], wt=edge[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    vector<int> visited(n, 0);
    vector<vector<int>> mst;
    int sum=0;

    pq.push(make_tuple(0,0,-1)); //weight, node, parent

    while(!pq.empty()){
        auto it = pq.top();
        int wt=get<0>(it), node=get<1>(it), parent=get<2>(it);
        pq.pop();
        
        if(visited[node]==1) continue;
        visited[node]=1;
        sum+=wt;

        for(auto adjNode:adj[node]){
            int v=adjNode[0], wt=adjNode[1];
            if(visited[v]==0){
                pq.push(make_tuple(wt, v, node));
            }
        }
    } 
    return sum;
}
