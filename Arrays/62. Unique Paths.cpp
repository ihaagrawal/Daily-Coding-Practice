// 62. Unique Paths (MEDIUM)
// https://leetcode.com/problems/unique-paths/description/

//Using recursion
//Brute (Space: O(2^n), Time: O(2^n))
//Gives TIME LIMIT EXCEEDED 
class Solution {
public:

    int unique(int i, int j, int m, int n){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        else return unique(i+1, j, m, n) + unique(i, j+1, m, n);
    }

    int uniquePaths(int m, int n) {
        return unique(0, 0, m, n);
    }
};

//Using Dynamic Programming
//Better (Space: O(nxm), Time: O(nxm))
class Solution {
public:

    int unique(int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        else return dp[i][j] = unique(i+1, j, m, n, dp) + unique(i, j+1, m, n, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return unique(0, 0, m, n, dp);
    }
};

//Using Combinatorics
//Optimal (Space: O(1), Time: O(m-1))
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int r = m - 1;
        double result = 1;
        for (int i = 1; i <= r; i++)
            result = result * (N - r + i) / i;
        return static_cast<int>(result);
    }
};
