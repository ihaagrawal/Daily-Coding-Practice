// 560. Subarray Sum Equals K (MEDIUM)
// https://leetcode.com/problems/subarray-sum-equals-k/description/

//Brute (Space: O(1), Time: O(n^2))
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(), sum=0, count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                sum += nums[j];
                if(sum==k) count++;
            }
            sum=0;
        }
        return count;
    }
};

//Better (Space: O(n), Time: O(nlogn))
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(), sum=0, count=0;
        map<int, int> mp;
        mp[0] = 1;
        for(int i=0;i<n;i++){
            sum+=nums[i]; 
            int diff=sum-k;
            if(mp.find(diff)!=mp.end()) count+=mp[diff];
            mp[sum]++;
        }
        return count;
    }
};

