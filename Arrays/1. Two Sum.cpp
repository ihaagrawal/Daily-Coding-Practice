// 1. Two Sum (EASY)
// https://leetcode.com/problems/two-sum/description/

//Brute (Space: O(1), Time: O(n^2))
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target)
                    return {i,j};
            }
        }
        return {0,0};
    }
};

//Better (Space: O(n), Time: O(nlogn))
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int, int>mp;
        for(int i=0;i<n;i++){
            auto it=mp.find(target-nums[i]);
            if(it!=mp.end()) return {i, it->second};
            else mp.insert(make_pair(nums[i], i));
        }
        return {-1,-1};
    }
};
