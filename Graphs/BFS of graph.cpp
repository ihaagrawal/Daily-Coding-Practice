// BFS of graph (EASY)
// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// https://www.naukri.com/code360/problems/bfs-in-graph_973002?leftPanelTabValue=PROBLEM

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V+1, false);  //visited array to keep track if node is visited or not
        vector<int> result;
        queue<int> q;
        q.push(0);
        visited[0]=true;
        
        while(!q.empty()){
            int ind=q.front();
            q.pop();
            result.push_back(ind);
            for(auto j:adj[ind]){
                if(!visited[j]){
                    q.push(j);
                    visited[j]=true;
                }
            }
        }
        return result;
    }
};
