// 1. Two Sum (EASY)
// https://leetcode.com/problems/two-sum/description/


//Brute: For each index check with every other index
//Time: O(n^2)
//Space: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] + nums[j] == target) return{i, j};
            }
        }
        return {-1, -1};
    }
};


//Better: Using map to store the elements 
//Using Ordered Map
//Time: O(nlogn)
//Space: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> mp;

        for(int i=0;i<n;i++){
            int num = nums[i];
            int diff = target - num;
            if(mp.find(diff) != mp.end()) return {mp[diff], i};
            if(mp.find(num) == mp.end()) mp[num] = i;
        }

        return {-1, -1};
    }
};

//Using Unordered Map
//Time: O(n)  (O(n^2) in the worst case)
//Space: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            int num = nums[i];
            int diff = target - num;
            if(mp.find(diff) != mp.end()) return {mp[diff], i};
            if(mp.find(num) == mp.end()) mp[num] = i;
        }

        return {-1, -1};
    }
};

