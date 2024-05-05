// 787. Cheapest Flights Within K Stops (MEDIUM)
// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto flight:flights){
            int u=flight[0], v=flight[1], p=flight[2];
            adj[u].push_back({v, p});
        }

        queue<tuple<int,int,int>> q;
        vector<int> dist(n, INT_MAX);

        q.push({0, src, 0}); //stops, node, cost
        dist[src]=0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops=get<0>(it), node=get<1>(it), cost=get<2>(it);

            if(stops>k) continue;

            for(auto itr:adj[node]){
                int v=itr.first, p=itr.second;
                if(cost+p < dist[v] && stops<=k){
                    dist[v]=cost+p;
                    q.push({stops+1, v, cost+p});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};
