// 4. Median of Two Sorted Arrays (HARD)
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

//Brute (Space: O(n+m), Time: O(n+m))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int n=nums1.size(), m=nums2.size();
        int left=0, right=0;
        while(left<n && right<m){
            if(nums1[left]<=nums2[right]) nums3.push_back(nums1[left++]);
            else nums3.push_back(nums2[right++]);        
        }

        while(left<n) nums3.push_back(nums1[left++]);
        while(right<m) nums3.push_back(nums2[right++]);
            
        double median;
        int num = nums3.size();
        if (num % 2 == 0) median = (nums3[num / 2 - 1] + nums3[num / 2]) / 2.0;
        else median = nums3[num / 2];
        return median;
    }
};


//Better (Space: O(1), Time: O(n+m))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size(), count=-1, i=0, j=0;
        int ind1=(n+m)/2, ind2=(n+m)/2-1;
        int ele1=INT_MIN, ele2=INT_MIN;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                count++;
                if(count==ind1) ele1=nums1[i];
                if(count==ind2) ele2=nums1[i];
                i++;
            }
            else{
                count++;
                if(count==ind1) ele1=nums2[j];
                if(count==ind2) ele2=nums2[j];
                j++;
            }
        }
        while(i<n){
           count++;
            if(count==ind1) ele1=nums1[i];
            if(count==ind2) ele2=nums1[i];
            i++; 
        }
        while(j<m){
            count++;
            if(count==ind1) ele1=nums2[j];
            if(count==ind2) ele2=nums2[j];
            j++;
        }

        if((n+m)%2==0) return (ele1+ele2)/2.0;
        else return ele1;
    }
};


//Optimal (Space: O(1), Time: O(min(logm, logn))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int n=n1+n2;
        int low=0, high= n1, cases=(n1+n2+1)/2;
        while(low<=high){
            int mid1=low+(high-low)/2;
            int mid2=cases-mid1;

            int l1=INT_MIN, l2=INT_MIN, r1=INT_MAX, r2=INT_MAX;
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];

            if(l1<=r2 && l2<=r1){
                if(n%2==0) return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
                else return max(l1, l2);
            }
            else if(l1>r2) high=mid1-1;
            else low=mid1+1;
        }
        return 0.0;
    }
};

