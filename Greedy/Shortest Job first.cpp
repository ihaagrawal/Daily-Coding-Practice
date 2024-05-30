// Shortest Job first (MEDIUM)
// https://www.geeksforgeeks.org/problems/shortest-job-first/1

class Solution {
  public:
    long long solve(vector<int>& bt) {
        int n = bt.size();
        sort(bt.begin(), bt.end());
        int t = 0, wt=0;
        for(int i=0;i<n;i++){
            wt += t;
            t += bt[i];
        }
        return wt/n;
    }
};
