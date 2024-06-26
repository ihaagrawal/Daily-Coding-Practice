// 560. Subarray Sum Equals K (MEDIUM)
// https://leetcode.com/problems/subarray-sum-equals-k/description/


//Brute: Check the sum of each subarray
//Time: O(n^3)
//Space: O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum = 0;
                for(int l=i;l<=j;l++){
                    sum += nums[l];
                }
                if(sum==k) count++;
            }
        }

        return count;
    }
};


//Better: To find sum of subarray we just need to add the next element
//Time: O(n^2)
//Space: O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                if(sum==k) count++;
            }
        }

        return count;
    }
};


//Optimal: Using map 
//Time: Unordered_map -> O(n), Ordered_map -> O(nlogn)
//Space: O(n)
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
