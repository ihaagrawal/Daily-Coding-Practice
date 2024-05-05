// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance (MEDIUM)
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX));

        for(auto it : edges){
            adj[it[0]][it[1]] = it[2];
            adj[it[1]][it[0]] = it[2];
        }

        for(int i=0;i<n;i++) adj[i][i]=0;

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k]==INT_MAX || adj[k][j]==INT_MAX){
                        continue;
                    }
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }

        int cntCity=n;
        int cityNo=-1;

        for(int city=0;city<n;city++){
            int cnt=0;
            for(int adjCity=0;adjCity<n;adjCity++){
                if(adj[city][adjCity]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<cntCity || (cnt==cntCity && city>cityNo)){
                cntCity=cnt;
                cityNo=city;
            }
        }

        return cityNo;
    }
};
