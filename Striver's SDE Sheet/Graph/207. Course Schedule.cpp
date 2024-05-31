// 207. Course Schedule (MEDIUM)
// https://leetcode.com/problems/course-schedule/description/

//APPROACH
//TOPOLOGICAL SORT:
//Put all the nodes with in degree 0 onto the queue
//Take out the element from the queue, and reduce in_deg of adjacent nodes by 1
//check if the new in_deg of adjacent node is 0
//  if yes then push it onto the queue
//if at the end the queue is empty but at least 1 in degree is not 0, return false
//else return true


//SOLUTION

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       
       //adjacency list & in_deg vector
       vector<int> adj[numCourses];
       vector<int> in_deg(numCourses);

        //initialising adjacency list & in_deg
        for(auto it : prerequisites){
                adj[it[0]].push_back(it[1]);
                in_deg[it[1]]++;
        } 

        //put all the nodes with in_deg 0 onto the queue
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in_deg[i] == 0){
                q.push(i);
            }
        }

        //run a loop while q has elements
        while(!q.empty()){

            //take the front element of q and pop it
            int current = q.front();
            q.pop();

            //check the adjacent nodes of the current node
            for(int node : adj[current]){

                //reduce their in degree by one, if it becomes 0 add the node to queue
                in_deg[node]--;
                if(in_deg[node] == 0){
                    q.push(node);
                }
            }
        }

        //check if at the end if at least 1 indegree is not 0, then return false
        for(int i=0;i<numCourses;i++){
            if(in_deg[i] != 0){
                return false;
            }
        }

        return true;
    }
};

