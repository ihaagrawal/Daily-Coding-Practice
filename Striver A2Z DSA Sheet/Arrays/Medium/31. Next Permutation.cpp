// 31. Next Permutation (MEDIUM)
// https://leetcode.com/problems/next-permutation/description/


//Brute: Generate all the permutations, sort them and look for the next permutation 
//Gives TLE for large input
//Time: O(n!*n)
//Space: O(n^2)
class Solution {
public:

    void permute(vector<int>& st, vector<int>& freq, vector<int>& nums, set<vector<int>>& result){
        if(st.size() == nums.size()){
            result.insert(st);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                st.push_back(nums[i]);
                freq[i] = 1;
                permute(st, freq, nums, result);
                st.pop_back();
                freq[i] = 0;
            }
        }
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> result;
        vector<int> st;
        vector<int> freq(n, 0);
        permute(st, freq, nums, result);

        auto it = find(result.begin(), result.end(), nums);
        if(it != result.end() && next(it) != result.end()) nums = *next(it);
        else nums = *result.begin();
    }
};


//Better: Using the built in function of C++ next_permutation()
//Time: O(n)
//Space: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};


//Optimal: Traverse from the end find the break point where nums[i] < nums[i-1]
//traverse from back again and find the element nums[j] just greater than nums[i-1]
//swap nums[i-1] & nums[j], reverse the array from i+1 to the end
//Time: O(n)
//Space: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int i = n-1;
        while(i>0 && nums[i] <= nums[i-1]) i--;

        if(i > 0){
            int j = n-1;
            while(nums[j] <= nums[i-1]) j--;
            swap(nums[i-1], nums[j]);
            reverse(nums.begin() + i, nums.end());
        }else sort(nums.begin(), nums.end());

    }
};
