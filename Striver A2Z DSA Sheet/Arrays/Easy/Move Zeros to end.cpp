// 283. Move Zeroes (EASY)
// https://leetcode.com/problems/move-zeroes/description/


//Brute: Use another duplicate array
//Time: O(n)
//Space: O(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1,k=0;
        vector<int> arr(nums.begin(), nums.end());
        
        while(i<=j){
            if(arr[k] == 0){
                nums[j] = 0;
                j--;
            }else{
                nums[i] = arr[k];
                i++;
            }
            k++;
        }
    }
};


//Optimal: Using Two Pointers
//Time: O(n)
//Space: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = -1;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }

        if(j == -1) return;

        for(int i=j+1;i<n;i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
