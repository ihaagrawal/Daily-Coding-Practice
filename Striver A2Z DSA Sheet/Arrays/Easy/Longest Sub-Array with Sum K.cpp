// Longest Sub-Array with Sum K (MEDIUM)
// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

//Brute: Generate all subarrays
//Time: O(n^3)
//Space: O(1)
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        int length = 0;
        
        for(int i=0;i<n;i++){
            for(j=i;j<n;j++){
                int s = 0;
                for(int k=i;k<j;k++) s += a[k];
                if(s==k) length = max(length, j-i+1);
            }
        }
        
        return length;
    } 

};

//Better: Using Two Loops
//Time: O(n^2)
//Space: O(1)
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        int length = 0;
        
        for(int i=0;i<n;i++){
            int sum = 0;
            int j = i;
            for(j=i;j<n;j++){
                sum += a[j];
                if(sum == k) length = max(length, j-i+1);
            }
        }
        
        return length;
    } 

};


//Optimal: Use map to store the previous sums encountered, and look to see if sum-k exists in map


//Ordered Map
//Time: O(nlogn)
//Space: o(n)
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        map<int, int> mp;
        int sum = 0, length = 0;
        mp[0] = -1;
        
        for(int i=0;i<n;i++){
            sum += a[i];
            if(mp.find(sum-k) != mp.end()) length = max(length, i-mp[sum-k]);
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return length;
    } 
};


//Unordered Map
//Time: O(n)
//Space: O(n)
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        unordered_map<int, int> mp;
        int sum = 0, length = 0;
        mp[0] = -1;
        
        for(int i=0;i<n;i++){
            sum += a[i];
            if(mp.find(sum-k) != mp.end()) length = max(length, i-mp[sum-k]);
            if(mp.find(sum) == mp.end()) mp[sum] = i;
        }
        return length;
    } 
};
