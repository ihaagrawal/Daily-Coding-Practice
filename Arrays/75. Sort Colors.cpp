// 75. Sort Colors (MEDIUM)
// https://leetcode.com/problems/sort-colors/description/

//Brute
//We can use any sorting algorithms the best Time & Space Complexities will be:
//Space: O(n) & Time: O(nlogn)


//Better: (Space: O(1), Time: O(n))
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0, left=0, right=n-1;
        while(i<=right){
            if(nums[i]==0){
                swap(nums[i], nums[left]);
                left++;
                i++;
            }
            else if(nums[i]==2){
                swap(nums[i], nums[right]);
                right--;
            }
            else i++;
        }
    }
};
