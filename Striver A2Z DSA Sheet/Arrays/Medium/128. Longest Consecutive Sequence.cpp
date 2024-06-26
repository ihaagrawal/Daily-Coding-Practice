// 128. Longest Consecutive Sequence (MEDIUM)
// https://leetcode.com/problems/longest-consecutive-sequence/description/


//Brute: For each element run a linear search for its consequetive element
//Time: O(n^3)
//Space: O(1)
class Solution {
public:

    bool linear(vector<int>& nums, int num, int count){
        for(int i=0;i<nums.size();i++){
            if(nums[i] == num+1) return true;
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int maxCount = 1;

        for(int i=0;i<n;i++){
            int count = 1, num = nums[i];
            
            while(linear(nums, num, count)){
                num = num+1;
                count++;
            }

            maxCount = max(count, maxCount);
        }

        return maxCount;
    }
};


//Better: Sort the array, keep count of consequetive numbers, if duplicates are encountered just skip them
//Time: O(nlogn)
//Space: O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int count = 1, maxCount = 1;
        sort(nums.begin(), nums.end());

        for(int i=1;i<n;i++){
            if(abs(nums[i] - nums[i-1]) == 1) count++;
            else if(abs(nums[i] - nums[i-1]) == 0) continue;
            else count = 1;

            maxCount = max(count, maxCount);
        }

        return maxCount;
    }
};


//Optimal: Using Unordered Set
//We have O(n) for inserting in set, O(n) for the for loop, and O(n) for the while loop
//the while loop will run for atmost 2 iterations even in the worst case O(2 * n)
//Time: O(3*n)
//Space: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        unordered_set<int> st;

        for(int i=0;i<n;i++) st.insert(nums[i]);

        int maxCount = 1;
        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int count = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x = x+1;
                    count++;
                }
                maxCount = max(count, maxCount);
            }
        }

        return maxCount;
    }
};
