// 189. Rotate Array (MEDIUM)
// https://leetcode.com/problems/rotate-array/description/


//Brute: By shifting elements to the right (GIVES TLE ON LARGE INPUT SIZE)
//Time: O(n*k)
//Space: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<k;i++){
            int last = nums[n-1];
            for(int j=n-1;j>0;j--) nums[j] = nums[j-1];
            nums[0] = last;
        }
    }
};


//Better: Using another array
//Time: O(n)
//Space: O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(nums.begin(), nums.end());

        for(int i=0;i<n;i++){
            int newInd = (i + k) % n;
            nums[newInd] = arr[i];
        }
    }
};


//Better: Using a temporary array
//Time: O(n)
//Space: O(k)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> temp;

        for(int i=n-k;i<n;i++){
            temp.push_back(nums[i]);
        }

        int j=n-1;
        for(int i=n-k-1;i>=0;i--){
            nums[j] = nums[i];
            j--;
        }

        for(int i=0;i<k;i++){
            nums[i] = temp[i];
        }
    }
};


//Optimal: Reverse entire array, reverse upto k elements, reverse from k to end
//Time: O(n)
//Space: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
