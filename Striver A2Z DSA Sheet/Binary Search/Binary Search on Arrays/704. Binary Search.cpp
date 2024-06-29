// 704. Binary Search (EASY)
// https://leetcode.com/problems/binary-search/description/


//Brute: Linear Search -> Traverse through the array checking each element 
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


//Better: Recursive Binary Search -> Check the mid element of the array, if greater than target check the left half else right half
//Time: O(logn)
//Space: O(logn)
class Solution {
public:

    int bs(vector<int>& nums, int left, int right, int target){
        if(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) return bs(nums, left, mid-1, target);
            else return bs(nums, mid+1, right, target);
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        return bs(nums, left, right, target);
    }
};


//Optimal: Iterative Binary Search -> Check the mid element of the array, if greater than target check the left half else right half
//Time: O(logn)
//Space: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};
