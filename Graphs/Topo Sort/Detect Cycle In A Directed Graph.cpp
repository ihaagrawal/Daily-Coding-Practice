// Detect Cycle In A Directed Graph (MODERATE)
// https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTabValue=PROBLEM


//Using Kahn's Algorithm (BFS)
#include <bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<vector<int>> adj(n);
    vector<int> in_deg(n, 0);
    queue<int> q;

    for(auto edge:edges){
      adj[edge.first-1].push_back(edge.second-1);
      in_deg[edge.second-1]++;
    }

    for(int i=0;i<n;i++){
      if(in_deg[i]==0) q.push(i);
    }

    int count=0;
    while(!q.empty()){
      int num = q.front();
      q.pop();
      count++;

      for(auto adjnode:adj[num]){
        in_deg[adjnode] -= 1;
        if(in_deg[adjnode]==0) q.push(adjnode);
      }
    }

    if(count==n) return 0;

    return 1;
}
