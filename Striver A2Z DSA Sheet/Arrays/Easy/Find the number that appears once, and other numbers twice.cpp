// 136. Single Number (EASY)
// https://leetcode.com/problems/single-number/description/


//Brute: Do a linear search for each element and count its frequency
//Time: O(n^2)
//Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(nums[j] == nums[i]) count++;
            }
            if(count == 1) return nums[i];
        }
        return -1;
    }
};


//Better: Using Ordered Map (M->size of map)
//Time: O(nlogM)
//Space: O(M)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;

        for(int i=0;i<n;i++) mp[nums[i]]++;
        for(auto& num : mp){
            if(num.second == 1) return num.first;
        }

        return -1;
    }
};


//Better: Using Unordered Map (M->size of map)
//Time: O(n)
//Space: O(M)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0;i<n;i++) mp[nums[i]]++;
        for(auto& num : mp){
            if(num.second == 1) return num.first;
        }

        return -1;
    }
};


//Optimal: Take xor of the whole array, the single element will be the final xor
//Time: O(n)
//Space: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        for(int i=0;i<n;i++) xr ^= nums[i];
        return xr;
    }
};
