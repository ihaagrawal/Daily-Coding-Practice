// 1631. Path With Minimum Effort (MEDIUM)
// https://leetcode.com/problems/path-with-minimum-effort/description/

class Solution {
public:

    struct CompareThird {
        bool operator()(const pair<pair<int,int>, int>& a, const pair<pair<int,int>, int>& b) {
            return a.second > b.second; // Compare based on the third element of the pair
        }
    };

    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size(), m=grid[0].size(), max_dist = -1;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, CompareThird> pq;

        dist[0][0] = 0;
        pq.push({{0,0}, 0});

        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!pq.empty()) {
            int i = pq.top().first.first;
            int j = pq.top().first.second;
            int dis = pq.top().second;
            pq.pop();

            if(i==n-1 && j==m-1) return dis;

            for (int k = 0; k < 4; k++) {
                int new_row = i + dir[k][0];
                int new_col = j + dir[k][1];

                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m) {
                    int new_dis = max(abs(grid[i][j] - grid[new_row][new_col]), dis);
                    if (dist[new_row][new_col] > new_dis) {
                        dist[new_row][new_col] = new_dis;
                        pq.push({{new_row, new_col}, new_dis});
                    }
                }
            }
        }

        return 0;
    }
};
