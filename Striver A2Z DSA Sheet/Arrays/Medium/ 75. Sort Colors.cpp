// 75. Sort Colors (MEDIUM)
// https://leetcode.com/problems/sort-colors/description/


//Brute: Sort the array
//Time: O(nlogn)
//Space: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

//Better: Count the frequency of each element 
//Time: O(2n)
//Space: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = 0, one = 0, two = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == 0) zero++;
            else if(nums[i] == 1) one++;
            else two++;
        } 

        for(int i=0;i<zero;i++) nums[i] = 0;
        for(int i=zero;i<zero+one;i++) nums[i] = 1;
        for(int i=zero+one;i<zero+one+two;i++) nums[i] = 2;
    }
};


//Optimal: Using Dutch National Flag Algorithm (Two Pointers)
//Time: O(n)
//Space: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1, i = 0;
        while(i <= right){
            if(nums[i] == 0){
                swap(nums[left], nums[i]);
                left++;
                i++;
            }else if(nums[i] == 2){
                swap(nums[right], nums[i]);
                right--;
            }else i++;
        }
    }
};
