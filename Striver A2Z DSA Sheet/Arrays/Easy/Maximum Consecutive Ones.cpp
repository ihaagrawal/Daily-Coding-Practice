// 485. Max Consecutive Ones (EASY)
// https://leetcode.com/problems/max-consecutive-ones/description/


//Brute, Better, Optimal: Increase count if 1 is found, if 0 is found make count=0, keep track of maxCount
//Time: O(n)
//Space: O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxCount = 0, count = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == 1) count++;
            else count = 0;
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};
