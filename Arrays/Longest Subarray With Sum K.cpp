// Longest Subarray With Sum K (EASY)
// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399?leftPanelTabValue=PROBLEM

//Two Pointer (Space: O(1), Time: O(2n))
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n=a.size(), max_count=0, count=0, i=0, j=0;
    long long sum=a[0];
    while(j<n){
        while(i<=j && sum>k){
            sum -= a[i];
            i++;
        }
        if(sum==k){
            max_count = max(max_count, j-i+1);
        }
        j++;
        if(j<n){
            sum += a[j];
        }
    }
    return max_count;
}


