// 128. Longest Consecutive Sequence (MEDIUM)
// https://leetcode.com/problems/longest-consecutive-sequence/description/

//Brute (Space: O(1), Time: O(n^2))
//Gives TIME LIMIT EXCEEDED
class Solution {
public:

    bool linear(vector<int>& nums, int num){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num) return true;
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int len=1, max_len=1, x;

        for(int i=0;i<n;i++){
            x=nums[i];
            len=1;
            for(int j=0;j<n;j++){
                while(linear(nums, x+1)){
                    x++;
                    len++;
                }
            }
            max_len=max(max_len, len);
        }

        return max_len;
    }
};

//Better (Space: O(n), Time: O(nlogn))
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(), len=1, max_len=1;
        if(n<=1) return n; 
        set<int> st;
        for(int i=0;i<n;i++) st.insert(nums[i]);
        auto prev = st.begin();
        for (auto it = ++st.begin(); it != st.end(); ++it) {
            if (*it == *prev+1) len++;
            else len=1;
            prev = it;
            max_len=max(max_len, len);
        }
        return max_len;
    }
};

//Optimal (Space: O(1), Time: O(nlogn))
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(), len=1, max_len=0;
        if(n==1) return 1;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]==0) max_len=max(len, max_len);
            else if(nums[i+1]-nums[i]!=1) len=1;
            else len++;
            max_len=max(len, max_len);
        }
        return max_len;
    }
};



