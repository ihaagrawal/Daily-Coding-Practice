// 268. Missing Number (EASY)
// https://leetcode.com/problems/missing-number/description/

//Brute (Space: O(n), Time: O(2n))
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int> count (n+1, 0);
        for(int i=0;i<n;i++)
            count[nums[i]]++;

        for(int i=0;i<=n;i++){
            if(count[i]==0)
                return i;
        }
        return n;
    }
};

//Better (Space: O(1), Time: O(n))
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*(n+1))/2;
        int ele_sum=0;
        for(int i=0;i<n;i++)
            ele_sum += nums[i];
        return sum-ele_sum;
    }
};
