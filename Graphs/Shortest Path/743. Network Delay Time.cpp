// 743. Network Delay Time (MEDIUM)
// https://leetcode.com/problems/network-delay-time/


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto time:times){
            int u=time[0], v=time[1], t=time[2];
            adj[u].push_back({v, t});
        }

        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, k}); 
        dist[k]=0;

        while(!pq.empty()){
            auto it = pq.top();
            int tym=it.first, node=it.second;
            pq.pop();

            for(auto itr:adj[node]){
                int v=itr.first, t=itr.second;
                if(tym+t < dist[v]){
                    dist[v]=tym+t;
                    pq.push({tym+t, v});
                }
            }
        }

        int mx = *max_element(dist.begin()+1, dist.end());
        return mx == INT_MAX ? -1 : mx;
    }
};
