// 994. Rotting Oranges (MEDIUM)
// https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));
        queue <pair<pair<int, int>, int>> q;
        int sec=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    visited[i][j]=2;
                    q.push({{i, j}, sec});
                }
            }
        }

        int row[] = {-1, 0, 1, 0};
        int col[] = {0, -1, 0, 1};

        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int s=q.front().second;
            sec = s;

            q.pop();

            for(int l=0;l<4;l++){
                int new_row = i + row[l];
                int new_col = j + col[l];

                if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && visited[new_row][new_col]!=2 && grid[new_row][new_col]==1){
                    q.push({{new_row, new_col}, s+1});
                    visited[new_row][new_col]=2;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]!=2) return -1;
            }
        }
        
        return sec;
    }
};
