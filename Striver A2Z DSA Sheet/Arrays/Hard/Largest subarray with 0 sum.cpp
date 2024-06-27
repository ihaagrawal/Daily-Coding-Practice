// Largest subarray with 0 sum (MEDIUM)
// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?category%5B%5D=Hash&company%5B%5D=Amazon&page=1&query=category%5B%5DHashcompany%5B%5DAmazonpage1company%5B%5DAmazoncategory%5B%5DHash


//Brute: Check the sum of each subarray
//Gives TLE
//Time: O(n^3)
//Space: O(1)
class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        int maxCount = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int count = 0, sum = 0;                            
                for(int k=i;k<=j;k++) sum += arr[k];
                if(sum == 0) count = j-i+1;
                maxCount = max(maxCount, count);
            }
        }
        
        return maxCount;
    }
};


//Better: Keep adding the next element to  a subarray and check
//Gives TLE
//Time: O(n^2)
//Space: O(1)
class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        int maxCount = 0;
        
        for(int i=0;i<n;i++){
            int count = 0, sum = 0;
            for(int j=i;j<n;j++){
                sum += arr[j];
                if(sum == 0) count = j-i+1;
                maxCount = max(maxCount, count);
            }
        }
        
        return maxCount;
    }
};


//Optimal: Use a map to store previous sums
//Time: O(n)
//Space: O(n)
class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        int maxCount = 0, sum = 0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
            
            if(sum == 0) maxCount = max(maxCount, i+1);
            else if(mp.find(sum) != mp.end()) maxCount = max(maxCount, i-mp[sum]);
            else mp[sum] = i;
        }
        
        return maxCount;
    }
};
