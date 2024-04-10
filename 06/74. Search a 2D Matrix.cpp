// 74. Search a 2D Matrix (MEDIUM)
// https://leetcode.com/problems/search-a-2d-matrix/description/

//Brute (Space: O(1), Time: O(n^2))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==target) return true;
            }
        }
        return false;
    }
};

//Better (Space: O(1), Time: O(nlog(m*n))
class Solution {
public:

    bool binary(vector<int>& matrix, int target){
        int low=0, high=matrix.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid]==target) return true;
            else if(matrix[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            if(binary(matrix[i], target))
                return true;
        }
        return false;
    }
};
