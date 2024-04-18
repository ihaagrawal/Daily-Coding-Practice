// 136. Single Number (EASY)
// https://leetcode.com/problems/single-number/description/

// Brute (Space: O(n), Time: O(nlogn))
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second==1)
                return it->first;
        }
        return -1;
    }
};

//Better (Space: O(1), Time: O(n))
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr=0;
        for(int i=0;i<nums.size();i++)
            xorr=xorr^nums[i];
        return xorr;
    }
};
