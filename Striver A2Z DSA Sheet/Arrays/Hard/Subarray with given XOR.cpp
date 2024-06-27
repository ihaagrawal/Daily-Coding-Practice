// Subarray with given XOR (MEDIUM)
// https://www.interviewbit.com/problems/subarray-with-given-xor/


//Brute: Check the xor of each subarray
//Time: O(n^3)
//Space: O(1)
int Solution::solve(vector<int> &nums, int b) {
    int n = nums.size();
    int count = 0;
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int xr = 0;
            for(int k=i;k<=j;k++) xr ^= nums[k];
            if(xr == b) count++;
        } 
    }
    
    return count;
}


//Better: Optimise the above code with 2 loops
//Time: O(n^2)
//Space: O(1)
int Solution::solve(vector<int> &nums, int b) {
    int n = nums.size();
    int count = 0;
    
    for(int i=0;i<n;i++){
        int xr = 0;
        for(int j=i;j<n;j++){
            xr ^= nums[j];
            if(xr == b) count++;
        } 
    }
    
    return count;
}


//Optimal: Use a map to store the prefix XOR
//Time: Ordered_map -> O(nlogn), Unordered_map -> O(n)
//Space: O(n)
int Solution::solve(vector<int> &nums, int b) {
    int n = nums.size();
    int xr = 0, count = 0;;
    map<int,int> mp;
    mp[xr]++;
    
    for(int i=0;i<n;i++){
        xr ^= nums[i];
        int x = xr^b;
        count += mp[x];
        mp[xr]++;
    }
    
    return count;
}
