// Find the Number of Provinces (MODERATE)
// https://www.naukri.com/code360/problems/find-the-number-of-states_1377943?leftPanelTabValue=PROBLEM

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
    visited[node]=true;
    for(auto j:adj[node]){
            if(!visited[j]){
                dfs(j, adj, visited);
            }
        }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    vector<bool> visited(n, false);
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(roads[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i, adj, visited);
            count++;
        }
    }
    return count;
}
