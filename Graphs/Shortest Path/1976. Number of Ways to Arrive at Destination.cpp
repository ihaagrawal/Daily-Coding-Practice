// 1976. Number of Ways to Arrive at Destination (MEDIUM)
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for(auto road:roads){
            int u=road[0], v=road[1], t=road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<long long> visited(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;

        pq.push({0, 0});
        dist[0]=0;
        visited[0]=1;

        while(!pq.empty()){
            auto it = pq.top();
            long long time=it.first, city=it.second;
            pq.pop();

            if(time>dist[city]) continue;

            for(auto itr:adj[city]){
                long long v=itr.first, t=itr.second;
                if(dist[v]>time+t){
                    visited[v]=visited[city];
                    dist[v]=time+t;
                    pq.push({dist[v], v});
                }else if(time+t==dist[v]){
                    visited[v] = (visited[v] + visited[city]) % 1000000007;
                }
            }
        }
        return visited[n-1];
    }
};
