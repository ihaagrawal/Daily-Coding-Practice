// Dijkstra's shortest path (EASY)
// https://www.naukri.com/code360/problems/dijkstra's-shortest-path_985358?leftPanelTabValue=PROBLEM


//Using Priority Queue
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>>& edges, int n, int m, int src) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<pair<int, int>> adj[n];
    for(auto edge:edges){
            int v=edge[0], u=edge[1], w=edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int num = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for (auto adjnode : adj[num]) {
            int v = adjnode.first;
            int w = adjnode.second;
            if (dist[v] > dis + w) {
                dist[v] = dis + w;
                pq.push({dist[v], v});
            }
        }
    }
  return dist;
}


//Using Set
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>>& edges, int n, int m, int src) {
    set<pair<int, int>> st;

    vector<pair<int, int>> adj[n];
    for(auto edge:edges){
            int v=edge[0], u=edge[1], w=edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    st.insert({0, src});

    while (!st.empty()) {
        auto it=st.begin();
        int num = it->second;
        int dis = it->first;
        st.erase(it);

        for (auto adjnode : adj[num]) {
            int v = adjnode.first;
            int w = adjnode.second;
            if (dist[v] > dis + w) {
                auto found = st.find({dist[v], v});
                if(found != st.end())
                    st.erase(found);
                dist[v] = dis + w;
                st.insert({dist[v], v});
            }
        }
    }

    return dist;
}




  


