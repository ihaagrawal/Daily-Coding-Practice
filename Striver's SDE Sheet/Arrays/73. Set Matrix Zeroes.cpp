// 73. Set Matrix Zeroes (MEDIUM)
// https://leetcode.com/problems/set-matrix-zeroes/description/


//Time Complexity: O(n^2 * (n+m))
//Space Complexity: O(n x m)
class Solution {
public:

    void setRow(vector<vector<int>>& matrix, int row, vector<vector<bool>>& changed){
        for(int j=0;j<matrix[row].size();j++){
            if(matrix[row][j] != 0){
                matrix[row][j] = INT_MIN;
                changed[row][j] = true;
            }
        }
    }

    void setColumn(vector<vector<int>>& matrix, int col, vector<vector<bool>>& changed){
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][col] != 0){
                matrix[i][col] = INT_MIN;
                changed[i][col] = true;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<bool>> changed(n, vector<bool>(m, false));
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    changed[i][j] = true;
                    setRow(matrix, i, changed);
                    setColumn(matrix, j, changed);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(changed[i][j] && matrix[i][j] == INT_MIN){
                    matrix[i][j] = 0;
                }
            }
        }

    }
};
