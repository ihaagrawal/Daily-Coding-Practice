// Distance from the Source (Bellman-Ford Algorithm)
// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1


class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> distTo(V, 1e8);
        vector<int> parent(V, -1);
        
        distTo[S]=0;
        
        for(int i=0;i<V-1;i++){
            for(auto it: edges){
                int u=it[0], v=it[1], wt=it[2];
                if(distTo[u]!=1e8 && distTo[u]+wt<distTo[v]){
                    distTo[v]=distTo[u]+wt;
                    parent[v]=u;
                }
            }
        }
        
        for(auto it:edges){
            int u=it[0], v=it[1], wt=it[2];
                if(distTo[u]!=1e8 && distTo[u]+wt<distTo[v]) return { -1};
        }
        
        return distTo;
    }
};
