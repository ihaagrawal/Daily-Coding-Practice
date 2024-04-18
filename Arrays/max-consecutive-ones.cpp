// 485. Max Consecutive Ones (EASY)
// https://leetcode.com/problems/max-consecutive-ones/description/


//Brute-Better-Optimal (Space: O(1), Time: O(n))
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0, j=0, n=nums.size(), max_count=0;
        while(j<n){
            if(nums[j]==1)
                count++;
            else{
                max_count=max(count, max_count);
                count=0;
            }
            j++;
        }
        max_count=max(count, max_count);
        return max_count;
    }
};
