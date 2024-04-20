// 547. Number of Provinces (MEDIUM)
// https://leetcode.com/problems/number-of-provinces/description/
// https://www.naukri.com/code360/problems/find-the-number-of-states_1377943

class Solution {
public:

    void dfs(int node, vector<bool>& visited,vector<vector<int>>& adj){
        visited[node]=true;
        for(auto j:adj[node]){
            if(!visited[j]){
                dfs(j, visited, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i, visited, adj);
                count++;
            }
        }

        return count;
    }
};
