// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/

//Brute (Space: O(1), Time: O(2n^2))
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(), i=0, j;
        while(i<n){
            while(i<n && nums[i]!=0) i++;
            if(i<n) j=i+1;
            else return;
            while(j<n && nums[j]==0) j++;
            if(j<n) swap(nums[i], nums[j]);
            i++;
        }
    }
};


//Better (Space: O(1), Time: O(2n))
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int j=0, i=0;
        for(i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }

        if(i==n) return;

        for(i=j+1;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
