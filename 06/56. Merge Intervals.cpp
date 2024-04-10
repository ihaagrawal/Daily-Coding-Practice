// 56. Merge Intervals (MEDIUM)
// https://leetcode.com/problems/merge-intervals/description/

//Brute, Better, Optimal (Space: O(1), Time: O(nlogn))
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i=0;
        while(i<intervals.size()-1){
            if(intervals[i][1]>=intervals[i+1][0]){
                intervals[i][1]=max(intervals[i][1], intervals[i+1][1]);
                intervals[i][0]=min(intervals[i][0], intervals[i+1][0]);
                intervals.erase(intervals.begin()+i+1);
            }
            else i++;
        }
        return intervals;
    }
};
