// 802. Find Eventual Safe States
// https://leetcode.com/problems/find-eventual-safe-states/description/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        vector<int> in_deg(n, 0);
        vector<int> result;

        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                in_deg[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(in_deg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int num = q.front();
            q.pop();
            result.push_back(num);
            for(auto adjnode:adj[num]){
                in_deg[adjnode]--;
                if(in_deg[adjnode]==0) q.push(adjnode);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};
