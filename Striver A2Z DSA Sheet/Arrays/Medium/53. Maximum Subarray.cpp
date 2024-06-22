// 53. Maximum Subarray (MEDIUM)
// https://leetcode.com/problems/maximum-subarray/description/


//Brute: Calculate the sum of each subarray and compare with the maxSum
//Will give TLE for large input
//Time: O(n^3)
//Space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum = 0;
                for(int k=i;k<=j;k++){
                    sum += nums[k];
                    maxSum = max(sum, maxSum);
                }
            }
        }

        return maxSum;
    }
};


//Better:  To get the sum of the current subarray we just need to add the current element to the sum of the previous subarray
//Will give TLE for large input
//Time: O(n^2)
//Space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;

        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                maxSum = max(sum, maxSum);
            }
        }

        return maxSum;
    }
};


//Optimal: Kadane's Algorithm -> add the current element to the sum, compare with maxSum, if sum<0 then assign sum = 0
//Time: O(n)
//Space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN, sum = 0;

        for(int i=0;i<n;i++){
            sum += nums[i];
            maxSum = max(sum, maxSum);
            if(sum < 0) sum = 0;
        }

        return maxSum;
    }
};

