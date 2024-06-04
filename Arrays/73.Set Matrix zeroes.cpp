// 73. Set Matrix Zeroes (MEDIUM)
// https://leetcode.com/problems/set-matrix-zeroes/description/

//Brute (Space: O(1), Time: O(2n^3))
class Solution {
public:

    void setzeroCol(vector<vector<int>>& mat, int col){
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]!=0){
                mat[i][col]=10000009;
            }
        }
    }

    void setzeroRow(vector<vector<int>>& mat, int row){
        for(int j=0;j<mat[row].size();j++){
            if(mat[row][j]!=0){
                mat[row][j]=10000009;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    setzeroCol(matrix, j);
                    setzeroRow(matrix, i);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==10000009){
                    matrix[i][j]=0;
                }
            }
        }
    }
};



//Better (Space: O(m+n), Time: O(2n^2))
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<int> col(n, 0);
        vector<int> row(m, 0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=-1;
                    col[j]=-1;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]==-1 || col[j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};


