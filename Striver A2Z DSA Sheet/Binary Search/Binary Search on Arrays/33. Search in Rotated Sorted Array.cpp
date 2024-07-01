// 33. Search in Rotated Sorted Array (MEDIUM)
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/


//Brute: Linear Search
//Time: O(n)
//Space: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == target) return i;
        }
        return -1;
    }
};


//Better: Binary Search -> Find the sorted half, check if target lies in that half, and move high or low accordingly
//Time: O(logn)
//Space: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums [mid]) high = mid - 1;
                else low = mid + 1;
            }else{
                if(nums[mid] <= target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }

        return -1;
    }
};
