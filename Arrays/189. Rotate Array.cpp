// 189. Rotate Array
// https://leetcode.com/problems/rotate-array/description/

//Brute (TLE for large input, 37/38 cases successful on leetcode)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size(), j=0;
        while(j<k){
            int num=nums[n-1];
            for(int i=n-1;i>0;i--) nums[i] = nums[i-1];
            nums[0]=num;
            j++;
        }
    }
};



//Better (Space: O(n), Time:O(2n))
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==k) return;
        if(k>n) k=k%n;
        int left=0, right=n-k;
        vector<int> result;
        for(int i=right;i<n;i++)
            result.push_back(nums[i]);
        for(int i=0;i<right;i++)
            result.push_back(nums[i]);
        int i=0;
        for(int element: result){
            nums[i] = element;
            i++;
        }
    }
};


//Optimal (Space: O(1), Time: O(2n))
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};




