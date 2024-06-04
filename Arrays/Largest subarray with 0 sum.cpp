// Largest subarray with 0 sum (MEDIUM)
// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

//Brute (Space: O(1), Time: O(n^2))
//Gives TIME LIMIT EXCEEDED
class Solution{
public:
    int maxLen(vector<int>&A, int n)
    {   
        int max_len = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += A[j];
                if(sum == 0){
                    int len = j - i + 1;
                    max_len = max(len, max_len);
                }
            }
        }
        return max_len;
    }
};

//Better (Space: O(n))
//Time: Unordered Map -> Best: O(n), Worst: O(n^2)
//      Ordered Map -> O(nlogn)

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        int k=0, sum=0, diff=0, len=0, max_len=0;
        map<int, int> mp;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k) max_len=max(max_len, i+1);
            diff=sum-k;
            if(mp.find(diff)!=mp.end()){
                len = i-mp[diff];
                max_len=max(max_len, len);
            }
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        return max_len;
    }
};
