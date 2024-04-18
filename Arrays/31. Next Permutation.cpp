// 31. Next Permutation (MEDIUM)
// https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n=nums.size(), i=0;
       for(i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]) break;
       } 

       if(i==0){
        reverse(nums.begin(), nums.end());
        return;
       }

       int j=n-1;
       while(j>i && nums[j]<=nums[i-1]) j--;
       swap(nums[i-1], nums[j]);
       reverse(nums.begin()+i, nums.end());
    }
};
