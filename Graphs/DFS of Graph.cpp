// DFS of Graph (EASY)
// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// https://www.naukri.com/code360/problems/dfs-traversal_630462?leftPanelTabValue=PROBLEM

class Solution {
  public:

    void dfs(int node, vector<int> adj[], vector<bool>& visited, vector<int>& result){
        visited[node]=true;
        result.push_back(node);
        
        for(auto j: adj[node]){
            if(!visited[j]){
                dfs(j, adj, visited, result);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V+1, false);
        vector<int> result;
        dfs(0, adj, visited, result);
        return result;
    }
};
