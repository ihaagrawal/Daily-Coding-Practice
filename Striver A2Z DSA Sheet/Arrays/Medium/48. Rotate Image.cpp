// 48. Rotate Image (MEDIUM)
// https://leetcode.com/problems/rotate-image/description/


//Brute: Take another dummy matrix of same dimensions as matrix
//then do dummy[j][n-i-1] = matrix[i][j], then copy dummy onto matrix
//Time: O(n^2)
//Space: O(n^2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dummy(n+1, vector<int>(m+1, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dummy[j][n-i-1] = matrix[i][j];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j] = dummy[i][j];
            }
        }
    }
};


//Better: Transpose the matrix, then reverse each row individually
//Time: O(n^2)
//Space: O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
