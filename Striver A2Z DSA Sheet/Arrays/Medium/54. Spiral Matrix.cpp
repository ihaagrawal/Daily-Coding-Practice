// 54. Spiral Matrix (MEDIUM)
// https://leetcode.com/problems/spiral-matrix/description/


//Brute, Better, Optimal: Take four variables left, right, top and bottom
//Time: O(m*n)
//Space: O(n)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, top = 0, right = m-1, bottom = n-1;
        vector<int> result;

        while(top <= bottom && left <= right){
            for(int j=left;j<=right;j++) result.push_back(matrix[top][j]);
            top++;
            
            for(int i=top;i<=bottom;i++) result.push_back(matrix[i][right]);
            right--;

            if(top <= bottom){
                for(int j=right;j>=left;j--) result.push_back(matrix[bottom][j]);
                bottom--;           
            }
            
            if(left <= right){
                for(int i=bottom;i>=top;i--) result.push_back(matrix[i][left]);
                left++;
            }
        }
        return result;
    }
};
