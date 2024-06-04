// 169. Majority Element (EASY)
// https://leetcode.com/problems/majority-element/description/

//Brute (Space: O(1), Time: O(n^2))
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size(), freq=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    freq++;
                    if(freq>floor(n/2)) return nums[i];
                }
            }
            freq=0;
        }
        return -1;
    }
};

//Better (Space: O(n), Time: O(2n))
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map <int, int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;
        for(auto it: mp){
            if(it.second>n/2) return it.first;
        }
        return -1;
    }
};

//Moore's Voting Algorithm 
//Optimal (Space: O(1), Time: O(2n))
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ele, count=0;
        for(int i=0;i<n;i++){
            if(count==0){
                ele=nums[i];
                count=1;
            }
            else if(nums[i]==ele) count++;
            else count--;
        }
        count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele) count++;
        }
        if(count>n/2) return ele;
        return -1;
    }
};
