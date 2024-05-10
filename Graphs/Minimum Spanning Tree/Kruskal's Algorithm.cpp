// Minimum Spanning Tree (MEDIUM)
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution
{
	public:
	
	void unionBySize(vector<int>& size, vector<int>& parent, int v, int u){
	    int pv=findParent(parent, v), pu=findParent(parent, u);
	    if(pv==pu) return;
	    
	    if(size[pv]>=size[pu]){
	        parent[pu] = pv;
	        size[pv] += size[pu];
	    }else{
	        parent[pv] = pu;
	        size[pu] += size[pv];
	    }
	}
	
	int findParent(vector<int>& parent, int x){
	    if(parent[x]==x) return x;
	    
	    return parent[x] = findParent(parent, parent[x]);
	}
    	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                int u=it[0], wt=it[1];
                edges.push_back({wt,{i, u}});
            }
        }
        sort(edges.begin(), edges.end());
        
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        
        vector<int> size(n,1);
        
        int minwt=0;
        for(auto it:edges){
            int wt=it.first, v=it.second.first, u=it.second.second;
            
            if(findParent(parent, v) != findParent(parent, u)){
                minwt += wt;
                unionBySize(size, parent, v, u);
            }
            
        }
        
        return minwt;
    }
};
