// 73. Set Matrix Zeroes (MEDIUM)
// https://leetcode.com/problems/set-matrix-zeroes/description/


//Brute: Traverse over the matrix, if 0 is found set corresponding row and col to 1e9
//After traversal, traverse it again, if 1e9 is found convert it to zero
//Time: O(n^3)
//Space: O(1)
class Solution {
public:

    void setRow(vector<vector<int>>& matrix, int row){
        int m = matrix[0].size();
        for(int j=0;j<m;j++){
            if(matrix[row][j] != 0) matrix[row][j] = 1e9;
        }
    }

    void setCol(vector<vector<int>>& matrix, int col){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            if(matrix[i][col] != 0) matrix[i][col] = 1e9;
        }
    }


    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    setRow(matrix, i);
                    setCol(matrix, j);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 1e9){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


//Better: Keep a row and col vector, traverse the matrix, if 0 is found, mark corresponding i & j as 0 in row and col
//Travers the matrix, row and col, if any of the row and col is zero marks matrix[i][j] = 0
//Time: O(n^2)
//Space: O(n) + O(m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> row(n, -1), col(m, -1);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]==0 || col[j]==0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


//Optimal: Take the first column as the row vector and the first row as the column vector and a variable col0 for 0th index of column vector
//Do as the better solution, if zero is found mark corresponding row and column as 0
//then traverse the matrix apart from the first row and column, and change to zero if required
//then traverse the column vector (0th index row), and after that the row vector (0th indexed column)
//Time: O(n^2)
//Space: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int col0 = 1;

      //traversing complete matrix;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j == 0 && matrix[i][j] == 0) col0 = 0;
                else if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

      //traversing the matrix except the 0th indexed row and column
        for(int i=n-1;i>0;i--){
            for(int j=m-1;j>0;j--){
                if(matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }

      //traversing the 0th indexed row
        for(int j=m-1;j>0;j--){
            if(matrix[0][0] == 0) matrix[0][j] = 0; 
        }

      //traversing the 0th indexed column
        for(int i=0;i<n;i++){
            if(col0 == 0) matrix[i][0] = 0;
        }
    }
};
