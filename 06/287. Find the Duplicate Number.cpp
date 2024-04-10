// 287. Find the Duplicate Number (MEDIUM)
// https://leetcode.com/problems/find-the-duplicate-number/description/

//Brute (Space: O(1), Time: O(n^2)) 
//TLE
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size(), freq=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<n;j++){
                if(nums[j]==i){
                    freq++;
                    if(freq>1) return i;
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
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> count(n+1,0);
        for(int i=0;i<n;i++)
            count[nums[i]]++;
        for(int i=0;i<n;i++){
            if(count[i]>1) return i;
        }
        return -1;
    }
};

//Optimal (Space: O(1), Time: O(n))
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size(), i=0, ind=-1;
        while(i<n+1){
            if(nums[i]==-1) return i;
            ind=nums[i];
            nums[i]=-1;
            i=ind;
        }
        return -1;
    }
};
