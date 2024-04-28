// 542. 01 Matrix (MEDIUM)
// https://leetcode.com/problems/01-matrix/description/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        queue<pair<pair<int,int>, int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                    distance[i][j]=0;
                }
            }
        }

        int row[]={-1, 0, 1, 0};
        int col[]={0, -1, 0, 1};

        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dist=q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int new_row=i+row[k];
                int new_col=j+col[k];

                if(new_row<0 || new_row>=m || new_col<0 || new_col>=n || visited[new_row][new_col]!=0) continue;

                visited[new_row][new_col] = 1;
                distance[new_row][new_col] = dist + 1;
                q.push({{new_row, new_col}, dist + 1});
            }
        }

        return distance;

    }
};
