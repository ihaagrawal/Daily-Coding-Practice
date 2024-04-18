// 1752. Check if Array Is Sorted and Rotated
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/


// Brute Force
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size(), point=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]) continue;
            if(nums[i]>nums[i+1]){
                if(point==-1)
                    point=i+1;
                else 
                    return false;

                while(point+1<n && nums[point+1]==nums[point] )
                    point++;
                
                while(point<n){
                    if(nums[point]<=nums[0])
                        point++;
                    else return false;
                }
            }
            
        }
        return true;
    }
};


//Better

class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0, n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]) count++;
        }
        if(nums[n-1]>nums[0]) count++;
        return count<=1;
    }
};
