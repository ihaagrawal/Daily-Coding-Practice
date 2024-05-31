// BFS of graph (EASY)
// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

//APPROACH:
//Maintain a visited vector to store if node is already visited or not
//Maintain a result vector to store result
//Add the first node to result and the queue and mark it visited
//store front of queue in a variable and pop it
//check its adjacent elments and if they arent visited
//  then mark them visited and add them to queue and result
//do this until queue is not empty


//SOLUTION:

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        //visited, result and queue
        vector<int> visited(V+1, 0);
        vector<int> result;
        queue<int> q;
        
        //mark first as visited, add to result and queue
        visited[0] = 1;
        result.push_back(0);
        q.push(0);
        
        //run a loop till q still has elements in it
        while(!q.empty()){
            
            //take the front of the queue and pop it
            int current = q.front();
            q.pop();
            
            //check the front's adjacent nodes
            for(auto node : adj[current]){
                
                //if not visited, then mark them visited and add to result and queue
                if(visited[node] == 0){
                    visited[node] = 1;
                    q.push(node);
                    result.push_back(node);
                }
            }
        }
        
        return result;
    }
};

