// 493. Reverse Pairs (HARD)
// https://leetcode.com/problems/reverse-pairs/description/

//Brute (Space: O(1), Time: O(n^2))
//Gives TIME LIMIT EXCEEDED
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size(), count=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                long long num=2LL*nums[j];
                if(nums[i]>num) count++;
            }
        }
        return count;
    }
};

