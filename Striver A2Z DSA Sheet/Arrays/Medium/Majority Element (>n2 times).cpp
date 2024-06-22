// 169. Majority Element (EASY)
// https://leetcode.com/problems/majority-element/description/

//Brute: Count frequency of each element and check if it is greater than n/2
//Time: O(n^2)
//Space: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int limit = floor(n/2);

        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(nums[i] == nums[j]) count++;
            }
            if(count > limit) return nums[i];
        }

        return -1;
    }
};

//Better: Use a map to store the frequency of each element

//Ordered Map
//Time: O(nlogn)
//Space: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int limit = floor(n/2);
        map <int, int> mp;

        for(int i=0;i<n;i++) mp[nums[i]]++;

        for(auto& num : mp){
            if(num.second > limit) return num.first;
        }

        return -1;
    }
};

//Unordered Map
//Time: O(n)
//Space: O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int limit = floor(n/2);
        unordered_map <int, int> mp;

        for(int i=0;i<n;i++) mp[nums[i]]++;

        for(auto& num : mp){
            if(num.second > limit) return num.first;
        }

        return -1;
    }
};


//Better: By sorting, and keeping track of frequency of one element
//Time: O(nlogn)
//Space: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1, limit = floor(n/2);
        sort(nums.begin(), nums.end());

        int last = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] == last) count++;
            else{
                if(count > limit) return last;
                last = nums[i];
                count = 1;
            }
        }
        if(count > limit) return last;
        return -1;
    }
};


//Optimal: Keeping track of an element, while traversal if we have same element then count++ else count--, at count=0 reassign the last element
//Time: O(n)
//Space: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0, last;
        int limit = floor(n/2);

        for(int i=0;i<n;i++){
            if(count == 0){
                count = 1;
                last = nums[i];
            }else if(nums[i] == last) count++;
            else count--;
        }
        
        count = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == last) count++;
        }

        if(count > limit) return last;
        return -1;
    }
};
