// 785. Is Graph Bipartite? (MEDIUM)
// https://leetcode.com/problems/is-graph-bipartite/description/

//APPROACH:
//make the adjacency list of the graph
//make a vector color to store the color assigned to the index
//initialise color with -1
//run dfs on nodes of the graph, if the color[node] == -1, i.e. no color
//assign the current node with a color
//now check its adjacent nodes and, if they have -1 in them then run dfs on each node
//if the color[adjNode] == col col->current color, then return false
//assign 0 and 1 to alternate nodes


//SOLUTION

class Solution {
public:

    bool dfs(int node, int col, vector<int> adj[], vector<int>& color){
        //assign col to color[node]
        color[node] = col;

        //check the adjacent nodes
        for(auto adjNode : adj[node]){

            //if the adjacent node is -1, then run dfs on it,
            //if color[adjNode] == col then return false
            if(color[adjNode] == -1){
                if(dfs(adjNode, !col, adj, color) == false) return false;
            }else if(color[adjNode] == col) return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(), m = graph[0].size();
        vector<int> adj[n];

        //make the adjacency list
        for(int i=0;i<n;i++){
            for(auto g : graph[i]){
                adj[i].push_back(g);
            }
        }

        //make a vector color, initialised with -1
        vector<int> color(n, -1);

        //traverse over the color array, if we find -1 tun dfs on it
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(dfs(i, 0, adj, color) == false) return false;
            }
        }

        return true;
    }
};



