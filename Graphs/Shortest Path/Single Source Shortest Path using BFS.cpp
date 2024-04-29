// Single Source Shortest Path (EASY)
// https://www.naukri.com/code360/problems/single-source-shortest-path_8416371?leftPanelTabValue=PROBLEM

vector<int> shortestPath(int n, vector<vector<int>>& edges, int src) {
    vector<vector<int>> adj(n); 
    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    vector<int> dist(n, INT_MAX);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == INT_MAX) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX) dist[i]=-1;
    }

    return dist;
}
