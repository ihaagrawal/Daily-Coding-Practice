// 34. Find First and Last Position of Element in Sorted Array (MEDIUM)
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/


//Brute: Search from the beginning for first index and from the back for the second index
//Time: O(n)
//Space: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1, second = -1;
        for(int i=0;i<n;i++){
            if(nums[i] == target){
                first = i;
                break;
            }
        }

        for(int i=n-1;i>=0;i--){
            if(nums[i] == target){
                second = i;
                break;
            }
        }
        
        return {first, second};
    }
};



//Better: Using Binary Search
//Time: O(logn)
//Space: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1, second = -1;
        int low = 0, high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] <= target){
                if(nums[mid] == target) second = mid;
                low = mid + 1;
            }else high = mid - 1;
        }

        low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] >= target){
                if(nums[mid] == target) first = mid;
                high = mid -1;
            }else low = mid + 1;
        }

        if(first == -1 && second != -1) first = second;
        else if (second == -1 && first != -1) second = first;

        return {first, second};
    }
};
