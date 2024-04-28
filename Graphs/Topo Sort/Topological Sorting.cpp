// Topological Sorting (MODERATE)
// https://www.naukri.com/code360/problems/topological-sorting_973003?leftPanelTabValue=PROBLEM


//Using DFS
#include <bits/stdc++.h>

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& st){
    visited[node]=1;
    for(auto adjnode:adj[node]){
        if(!visited[adjnode]){
            dfs(adjnode, adj, visited, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<vector<int>> adj(nodes);
    for(auto edge: graph){
        adj[edge[0]].push_back(edge[1]);
    }

    stack<int> st;
    vector<int> visited(nodes, 0);

    for(int i=0;i<nodes;i++){
        dfs(i, adj, visited, st);
    }

    vector<int> result;
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }
    return result;
}


//Using BFS
//Kahn's Algorithm
#include <bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<int> in_deg(nodes, 0);
    vector<vector<int>> adj(nodes);
    queue<int> q;

    for(auto edge: graph){
        adj[edge[0]].push_back(edge[1]);
        in_deg[edge[1]]++;
    }

    for(int i=0;i<nodes;i++){
        if(in_deg[i]==0){
            q.push(i);
        }
    }

    vector<int> result;
    while(!q.empty()){
        int num = q.front();
        q.pop();
        result.push_back(num);
        for(auto adjnode:adj[num]){
            in_deg[adjnode] -= 1;
            if(in_deg[adjnode]==0) q.push(adjnode);
        }
    }

    return result;
}
