// Geek Jump (EASY)
// https://www.geeksforgeeks.org/problems/geek-jump/1

class Solution {
  public:
    int helper(vector<int>& height, int n, vector<int>& dp) {
        if(n==0) return dp[n] = 0;
        if(dp[n] != -1) return dp[n];
        
        int left = helper(height, n-1, dp) + abs(height[n] - height[n-1]);
        int right = INT_MAX;
        if(n>1){
            right = helper(height, n-2, dp) + abs(height[n] - height[n-2]);
        }
        
        return dp[n] = min(left, right);
    }
    
    int minimumEnergy(vector<int>& height, int n){
        vector<int> dp(n+1, -1);
        return helper(height, n-1, dp);
    }
};
