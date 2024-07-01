// 81. Search in Rotated Sorted Array II (MEDIUM)
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/


//Brute: Using Linear Search
//Time: O(n)
//Space: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == target) return true;
        }
        return false;
    }
};


//Better: Using Binary Search
//Time: O(logn)
//Space: O(1)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return true;
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            else if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums [mid]) high = mid - 1;
                else low = mid + 1;
            }else{
                if(nums[mid] <= target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }

        return false;
    }
};
