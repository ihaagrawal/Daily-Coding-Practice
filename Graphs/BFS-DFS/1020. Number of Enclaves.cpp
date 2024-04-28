// 1020. Number of Enclaves (MEDIUM)
// https://leetcode.com/problems/number-of-enclaves/description/

class Solution {
public:

    void dfs(int i, int j, vector<vector<int>>& grid){
        int m=grid.size(), n=grid[0].size();
        grid[i][j]=0;
        int rows[]={-1, 0, 1, 0};
        int cols[]={0, -1, 0, 1};

        for(int k=0;k<4;k++){
            int nrow=i+rows[k];
            int ncol=j+cols[k];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                dfs(nrow, ncol, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int total = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && (i==0 || i==m-1 || j==0 || j==n-1)){
                    dfs(i, j, grid);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    total++;
                }
            }
        }
        
        return total;
    }
};
