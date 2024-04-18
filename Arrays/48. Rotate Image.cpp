// 48. Rotate Image (MEDIUM)
// https://leetcode.com/problems/rotate-image/description/

//Brute (Space: O(n^2), Time: O(2n^2))
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> result(n, vector<int>(n, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                result[j][n-i-1]=matrix[i][j];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=result[i][j];
            }
        }
    }
};


//Better (Space: O(1), Time: O(2n^2))
class Solution {
public:

    void swapColumns(vector<vector<int>>& mat, int col1, int col2) {
        for (int i = 0; i < mat.size(); ++i) {
            swap(mat[i][col1], mat[i][col2]);
        }
    }

    void transposeMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        transposeMatrix(matrix);
        for(int i=0;i<n/2;i++)
            swapColumns(matrix, i, n-i-1);
    }
};


//Better Approach-2 (Space:O(1), Time:O(n^2))
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};
