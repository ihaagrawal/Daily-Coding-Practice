// DFS of Graph (EASY)
// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1


//APPROACH:
//Maintain a visited vector to store if the node is already visited or not
//Maintain a result vector to store the result of the traversal
//Apply DFS recursively on the 1st node
//Check each node's adjacent node
//If the adjacent node is not visited 
//  then mark it visited, add to the result vector and call DFS on it


//SOLUTION:

class Solution {
  public:
  
    void dfs(int node, vector<int> adj[], vector<int>& visited, vector<int>& result){
        
        //check the adjacent nodes of the current node
        for(auto adjNode : adj[node]){
            
            //if adjacent node is not visited
            if(visited[adjNode] == 0){
                
                //push it back into result and mark it as visited
                result.push_back(adjNode);
                visited[adjNode] = 1;
                
                //call dfs on it
                dfs(adjNode, adj, visited, result);
            }
        }
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        //result and visited vector
        vector<int> visited(V+1, 0);
        vector<int> result;
        
        //push the first node into result and mark it as visited
        result.push_back(0);
        visited[0] = 1;
        
        //dfs on the first node
        dfs(0, adj, visited, result);
        return result;
    }
};
