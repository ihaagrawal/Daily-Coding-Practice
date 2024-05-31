// Topological sort (MEDIUM)
// https://www.geeksforgeeks.org/problems/topological-sort/1

//APPROACH
//TOPOLOGICAL SORT:
//Put all the nodes with in degree 0 onto the queue and push them into result
//Take out the element from the queue, and reduce in_deg of adjacent nodes by 1
//check if the new in_deg of adjacent node is 0
//  if yes then push it onto the queue and push it into result

//SOLUTION:

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> result;
	    vector<int> in_deg(V);
	    for (int i = 0; i < V; i++) {
            for (auto node : adj[i]) {
                in_deg[node]++;
            }
        }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(in_deg[i] == 0){
	            q.push(i);
	            result.push_back(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int current = q.front();
	        q.pop();
	        
	        for(auto node : adj[current]){
	            in_deg[node]--;
	            if(in_deg[node] == 0){
	                q.push(node);
	                result.push_back(node);
	            }
	        }
	    }
	    
	    return result;
	}
};
