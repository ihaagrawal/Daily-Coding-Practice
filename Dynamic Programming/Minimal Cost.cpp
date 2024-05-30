// Minimal Cost (MEDIUM)
// https://www.geeksforgeeks.org/problems/minimal-cost/1

class Solution {
  public:
  
    int helper(vector<int>& height, int n, int k, vector<int>& dp){
        if(n==0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        int diff = INT_MAX;
        for(int i=1;i<=k;i++){
            int newDiff;
            if(n-i >= 0){
                newDiff = helper(height, n-i, k, dp) + abs(height[n] - height[n-i]);
                diff = min(diff, newDiff);
            }
        }
        
        return dp[n] = diff;
    }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n, -1);
        return helper(height, n-1, k, dp);
    }
};
