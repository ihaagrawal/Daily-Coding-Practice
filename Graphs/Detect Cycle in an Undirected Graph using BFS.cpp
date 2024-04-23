// Detect Cycle in an Undirected Graph (MODERATE)
// https://www.naukri.com/code360/problems/detect-cycle-in-an-undirected-graph-_758967?leftPanelTabValue=PROBLEM

class Graph {

public:

    bool detect(int node, vector<bool>& visited, queue<pair<int, int>>& q, vector<int> adj[]){
        visited[node]=true;
        q.push({node, -1});
        
        while(!q.empty()){
            int ind=q.front().first;
            int parent=q.front().second;
            q.pop();

            for(auto j: adj[ind]){
                if(!visited[j]){
                    visited[j]=true;
                    q.push({j, ind});
                }
                else if(parent != j) return true;
            }
        }

        return false;
        
    }

    bool detectCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V+1, false);
        queue<pair<int, int>> q;

        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detect(i, visited, q, adj)) return true;
            }
        }

        return false;
    }
};
