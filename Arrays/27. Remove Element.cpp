// 27. Remove Element (EASY)
// https://leetcode.com/problems/remove-element/description/

//Brute (Space: O(1), Time: O(n^2))
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==val){
                for(int j=i;j<n-1;j++){
                    nums[j]=nums[j+1];
                }
                i--;
                n--;
            }
        }
        return n;
    }
};

//Better (Space: O(n), Time: O(n))
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        vector<int> store;
        for(int i=0;i<n;i++){
            if(nums[i]!=val) store.push_back(nums[i]);
        }
        int ind=0;
        for(auto num:store) nums[ind++]=num;
        return ind;
    }
};

//Optimal (Space: O(1), Time: O(n))
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size(), j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};
