// 88. Merge Sorted Array (EASY)
// https://leetcode.com/problems/merge-sorted-array/description/


//Brute: Merge both the arrays into nums1, and sort nums1
//Time: O(n) + O(mlogm) -> merging the arrays + sorting nums1
//Space: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m, j = 0;
        while(i+j < m+n){
            nums1[i+j] = nums2[j];
            j++; 
        }
        sort(nums1.begin(), nums1.end());
    }
};

