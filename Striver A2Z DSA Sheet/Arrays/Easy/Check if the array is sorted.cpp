// 1752. Check if Array Is Sorted and Rotated (EASY)
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

//Brute
//Time: O(n^2)
//Space: O(n)
class Solution {
public:

    bool rotateAndCheck(vector<int> nums, int rotate, int n){
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            int newInd = (i+rotate)%n;
            arr[newInd] = nums[i];
        }

        for(int i=1;i<n;i++){
            if(arr[i] < arr[i-1]) return false;
        }

        return true;
    }

    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(rotateAndCheck(nums, i, n)) return true;
        }
        return false;
    }
};


//Better
//Time: O(n)
//Space: O(1)
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=1;i<n;i++){
            if(nums[i] < nums[i-1]) count++;
        }
        
        if(nums[n-1] > nums[0]) count++;

        if(count > 1) return false;
        return true;
    }
};
