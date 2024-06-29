// 152. Maximum Product Subarray (MEDIUM)
// https://leetcode.com/problems/maximum-product-subarray/description/


//Brute: Check the product for each subarray
//Time: O(n^3)
//Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = INT_MIN;
        for(int i=0;i<nums.size()-1;i++) {
            for(int j=i+1;j<nums.size();j++) {
                int prod = 1;
                for(int k=i;k<=j;k++){
                    prod *= nums[k];
                }
                result = max(result,prod);    
            }
        }
        return (int)result;
    }
};


//Better: Optimisation of the Brute force, using only two loops
//Time: O(n^2)
//Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), maxpdt = 0;
        for(int i=0;i<n;i++){
            int pdt = 1;
            for(int j=i;j<n;j++){
                pdt *= nums[j];
                maxpdt = max(pdt, maxpdt);
            }
        }
        return maxpdt;
    }
};



//Optimal: Using suffix and prefix
//Time: O(n)
//Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        double result = INT_MIN;
        double prefix = 1, suffix = 1;
        for(int i=0;i<n;i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n-i-1];

            result = max(result, max(prefix, suffix));
        }

        return result;
    }
};
