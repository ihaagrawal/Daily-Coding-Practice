// 1091. Shortest Path in Binary Matrix (MEDIUM)
// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

class Solution {
public:

    struct CompareThird {
        bool operator()(const pair<pair<int,int>, int>& a, const pair<pair<int,int>, int>& b) {
            return a.second > b.second; // Compare based on the third element of the pair
        }
    };

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, CompareThird> pq;

        if(grid[0][0]==1) return -1;

        dist[0][0]=1;
        pq.push({{0,0},1});

        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

        while(!pq.empty()){
            int i = pq.top().first.first;
            int j = pq.top().first.second;
            int dis = pq.top().second;
            pq.pop();

            for(int k=0;k<8;k++){
                int new_row = i + dir[k][0];
                int new_col = j + dir[k][1];

                if(new_row>=0 && new_row<n && new_col>=0 && new_col<n && grid[new_row][new_col]==0){
                    if(dist[new_row][new_col] > dis + 1){
                        dist[new_row][new_col] = dis + 1;
                        pq.push({{new_row, new_col}, dis+1});
                    }
                }
            }
        }

        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1];

    }
};
