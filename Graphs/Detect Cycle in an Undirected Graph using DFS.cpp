// Detect Cycle in an Undirected Graph (MODERATE)
// https://www.naukri.com/code360/problems/detect-cycle-in-an-undirected-graph-_758967?leftPanelTabValue=PROBLEM

class Graph {

public:

    bool dfs(int node, vector<bool>& visited, vector<int> adj[], int parent){
        visited[node]=true;

        for(auto j: adj[node]){
            if(!visited[j]){
                if(dfs(j, visited, adj, node)) return true;;
            }
            else if(parent!=j) return true;
        }

        return false;
    }

    bool detectCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i, visited, adj, -1)) return true;
            }
        }
        return false;
    }
};
