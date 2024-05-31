// 200. Number of Islands (MEDIUM)
// https://leetcode.com/problems/number-of-islands/description/

//APPROACH:
//Run DFS on the first cell which is 1 and mark all its connected 1's as -1
//Do this for multiple compnents
//The number of components will be the required number of island


//SOLUTION:

class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j){

        //if i or j are outside bounds or the cell value is not 1, then return
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0 || grid[i][j] != '1') return;

        //change the value of cell from 1 to -1
        //so that the loop in calling function does not count extra islands
        grid[i][j] = -1;

        //call dfs on each cell surrounding current cell
        dfs(grid, i+1, j);
        dfs(grid, i-1, j); 
        dfs(grid, i, j+1); 
        dfs(grid, i, j-1); 

    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m=grid[0].size();
        int island = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                //run dfs on cell with value 1
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    island++;
                }
            }
        }

        return island;
    }
};

