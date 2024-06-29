// 88. Merge Sorted Array (EASY)
// https://leetcode.com/problems/merge-sorted-array/description/


//Brute: Create a new array and put the elements into it in sorted order
//Time: O(m+n)
//Space: O(m+n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> arr3;

        int left = 0, right = 0;
        while(left < m && right < n){
            if(nums1[left] <= nums2[right]){
                arr3.push_back(nums1[left]);
                left++;
            }else{
                arr3.push_back(nums2[right]);
                right++;
            }
        }

        while(left < m){
            arr3.push_back(nums1[left]);
            left++;
        }

        while(right < n){
            arr3.push_back(nums2[right]);
            right++;
        }

        for(int i=0;i<arr3.size();i++) nums1[i] = arr3[i];
    }
};


//Better: Merge both the arrays into nums1, and sort nums1
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


//Optimal: Use merge sort 
//Time: O(m+n)
//Space: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        while(j >= 0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
