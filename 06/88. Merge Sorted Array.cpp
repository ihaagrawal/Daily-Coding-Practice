// 88. Merge Sorted Array (EASY)
// https://leetcode.com/problems/merge-sorted-array/description/

//Brute (Space: O(m+n), Time: O(m+n))
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0, ind=0;
        vector<int> result(m+n, 0);
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                result[ind]=nums1[i];
                i++;
            }
            else{
                result[ind]=nums2[j];
                j++;
            }
            ind++;
        }
        while(j<n) result[ind++]=nums2[j++];
        while(i<m) result[ind++]=nums1[i++];
        for(i=0;i<m+n;i++)
            nums1[i]=result[i];
    }
};

//Better (Space: O(1), Time: O((m+n)log(m+n))
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m, j=0;
        while(i<m+n && j<n){
            nums1[i]=nums2[j];
            i++;
            j++;
        }
        sort(nums1.begin(), nums1.end());
    }
};

//Optimal (Space: O(1), Time: O(m+n))
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1, k=m+n-1;
        while(j>=0){
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                i--;
            }
            else{
                nums1[k]=nums2[j];
                j--;
            }
            k--;
        }
    }
};
