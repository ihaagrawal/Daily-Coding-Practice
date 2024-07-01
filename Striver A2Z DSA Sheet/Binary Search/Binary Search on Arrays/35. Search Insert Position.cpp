// 35. Search Insert Position (EASY)
// https://leetcode.com/problems/search-insert-position/description/


//Brute: Linear Search for Upper Bound
//Time: O(n)
//Space: O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] >= target) return i;
        }

        return n;
    }
};


//Better: Binary Search for Upper Bound
//Time: O(logn)
//Space: O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};
