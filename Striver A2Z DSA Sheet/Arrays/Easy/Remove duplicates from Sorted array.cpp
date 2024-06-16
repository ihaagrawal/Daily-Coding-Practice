// 26. Remove Duplicates from Sorted Array (EASY)
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/


//Brute: Double Loop
//Time: O(n^2)
//Space: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 1, length = 1;
        while(i<n){
            if(nums[i] == nums[i-1]){
                for(int j=i;j<n-1;j++){
                    nums[j] = nums[j+1];
                }
                n--;
            }else{
                i++;
                length++;
            }
        }

        return length;
    }
};



//Better: Set
//Time: O(n)
//Space: O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int> unique;
        for(int i=0;i<n;i++) unique.insert(nums[i]);

        int i = 0;
        for(int num : unique){
            nums[i] = num;
            i++;
        }
        return unique.size();
    }
};


//Optimal: Two Pointers
//Time: O(n)
//Space: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int last = nums[0], count = 1;
        
        while(right < n){
            if(nums[right] != last){
                count++;
                nums[left+1] = nums[right];
                left++;
                last = nums[left];
            }else right++;
        }

        return count;
    }
};
