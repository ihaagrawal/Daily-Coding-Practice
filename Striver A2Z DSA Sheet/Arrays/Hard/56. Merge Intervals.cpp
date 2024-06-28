// 56. Merge Intervals (MEDIUM)
// https://leetcode.com/problems/merge-intervals/description/


//Brute: Sort the intervals by start time, and check for current index all the other intervals that can be merged
//Time: O(nlogn) + O(n^2) -> worst case,  O(nlogn) + O(2*n) -> best case
//Space: (n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int i = 0;

        if(n==0) return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        for(int i=0;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(!merged.empty() && end <= merged.back()[1]) continue;

            for(int j=i+1;j<n;j++){
                if(intervals[j][0] <= end) end = max(end, intervals[j][1]);
                else break;
            }

            merged.push_back({start, end});
        }

        return merged;
    }
};


//Better: Sort the intervals by start time, check intervals[i][1] >= intervals[i+1][0] then merge intervals
//Time: O(nlogn) + O(n)
//Space: O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int i = 0;

        if(n==0) return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for(int i=1;i<n;i++){
            vector<int>& temp = merged.back();
            if(temp[1] >= intervals[i][0]) temp[1] = max(intervals[i][1], temp[1]);
            else merged.push_back(intervals[i]);
        }

        return merged;
    }
};
