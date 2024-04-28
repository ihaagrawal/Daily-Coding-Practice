// 210. Course Schedule II (MEDIUM)
// https://leetcode.com/problems/course-schedule-ii/description/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        vector<int> in_deg(n, 0);
        for(auto pre:prerequisites){
            adj[pre[0]].push_back(pre[1]);
            in_deg[pre[1]]++;
        }
        
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in_deg[i]==0) q.push(i);
        }

        while(!q.empty()){
            int num = q.front();
            q.pop();
            topo.push_back(num);

            for(auto adjnode:adj[num]){
                in_deg[adjnode] -= 1;
                if(in_deg[adjnode]==0) q.push(adjnode);
            }
        }

        if(topo.size()==n){
            reverse(topo.begin(), topo.end());
            return topo;
        }
        return {};
    }
};
