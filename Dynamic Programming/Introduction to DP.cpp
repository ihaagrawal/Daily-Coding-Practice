// Introduction to DP (MEDIUM)
// https://www.geeksforgeeks.org/problems/introduction-to-dp/1

class Solution {
  public:
    const long long int MOD = 1e9+7;
    
    long long int helper(int n, vector<int>& dp) {
        if(n <= 1) return dp[n] = n;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (helper(n-1, dp) + helper(n-2, dp)) % MOD;
    }
    
    long long int topDown(int n){
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
    
    long long int bottomUp(int n) {
        vector<long long int> dp1(n+1, -1);
        
        dp1[0] = 0;
        dp1[1] = 1;
        
        for(int i=2;i<=n;i++){
            dp1[i] = (dp1[i-1] + dp1[i-2]) % MOD;
        }
        
        return dp1[n];
    }
};
