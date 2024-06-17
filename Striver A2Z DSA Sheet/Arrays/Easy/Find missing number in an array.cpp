// 268. Missing Number (EASY)
// https://leetcode.com/problems/missing-number/description/


//Brute: Check for each element using double loop
//Time: O(n^2)
//Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<=n;i++){
            bool flag = false;
            for(int j=0;j<n;j++){
                if(nums[j] == i){
                    flag = true;
                }
            }
            if(!flag) return i;
        }
        return n;
    }
};


//Better: Using Ordered Map
//Time: O(nlogn)
//Space: O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        map<int, int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;

        for(int i=0;i<=n;i++){
            if(mp.find(i) == mp.end()) return i;
        }
        return n;
    }
};


//Better: Using Unordered Map
//Time: O(n)
//Space: O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;

        for(int i=0;i<=n;i++){
            if(mp.find(i) == mp.end()) return i;
        }
        return n;
    }
};



//Better: Sort the array
//Time: O(nlogn)
//Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            if(nums[i] != i) return nums[i]-1;
        }

        return n;
    }
};



//Optimal: Using sum of elements of array
//Time: O(n)
//Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int sum = n * (n+1)/2;
        int arraySum = 0;
        for(int i=0;i<n;i++) arraySum += nums[i];

        return sum - arraySum;
    }
};


//Most Optimal: Using XOR of elements 
//Time: O(n)
//Space: O(1)
//Prevents integer overflow unlike summation of elements

//eg: for n=10^5 the sum=n*(n+1)/2 will give 10^10
//But, xor will never be more than the largest element
//so for n=10^5, xor will still give 10^5 in worst case


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int xr = 0;
        for(int i=0;i<n;i++){
            xr = xr ^ nums[i] ^ i;
        }
        xr = xr ^ n;
        
        return xr;
    }
};
