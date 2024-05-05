// Floyd Warshall (MODERATE)
// https://www.naukri.com/code360/problems/floyd-warshall_2041979?leftPanelTabValue=PROBLEM

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Create an adjacency matrix
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 1e9));

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u][v] = w;
    }

    for (int i = 1; i <= n; i++) {
        adj[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (adj[i][k] != 1e9 && adj[k][j] != 1e9)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    return adj[src][dest];
}
