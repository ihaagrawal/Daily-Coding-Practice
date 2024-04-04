// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?source=submission-ac

//Brute

class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n=a.size();
        for(int i=0;i<n-1;i++){
		if(a[i]==a[i+1]){
			for(int j=i+1;j<n-1;j++)
				a[j]=a[j+1];
			i--;
			n--;
		}
	}
	return n;
    }
};


//Better

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=1, n=nums.size();
        while(j<n){
            if(nums[i]==nums[j]) j++;
            else{
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
}; 
