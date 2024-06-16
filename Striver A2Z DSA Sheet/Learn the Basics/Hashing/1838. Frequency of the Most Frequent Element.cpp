// 1838. Frequency of the Most Frequent Element (MEDIUM)
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/


//APPROACH 1: Binary Search and Prefix Sum
//Time: O(nlogn)
//Space: O(n)

class Solution {
public:

    int binarySearch(int targetInd, int k, vector<int>& nums, vector<long>& prefixSum){
        int target = nums[targetInd];
        int left = 0, right = targetInd;
        int result = targetInd;

        while(left <= right){
            int mid = left + (right - left)/2;

            long count = (targetInd - mid + 1);
            long windowSum = (count * target);
            long currSum = prefixSum[targetInd] - prefixSum[mid] + nums[mid];
            long ops = windowSum - currSum;

            if(ops > k){
                left = mid + 1;
            }else{
                result = mid;
                right = mid - 1;
            }
        }

        return targetInd - result + 1;
    }

    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long> prefixSum(n);
        prefixSum[0] = nums[0];
        for(int i=1;i<n;i++) prefixSum[i] = prefixSum[i-1] + nums[i];

        int maxFreq = 0;
        for(int i=0;i<n;i++){
            int freq = binarySearch(i, k, nums, prefixSum);
            maxFreq = max(maxFreq, freq);
        }

        return maxFreq;
    }
};


//APPROACH 2: Sliding Window
//Time: O(nlogn)
//Space: O(1)

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long windowSum = 0;
        int freq = 0;
        int left = 0;

        for(int right=0;right<n;right++){
            long target = nums[right];
            windowSum += nums[right];

            while((right-left+1) * target - windowSum > k){
                windowSum -= nums[left];
                left++;
            }

            freq = max(freq, right - left + 1);
        }

        return freq;
    }
};
