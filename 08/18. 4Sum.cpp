// 18. 4Sum (MEDIUM)
// https://leetcode.com/problems/4sum/description/

//Brute (Space: O(1), Time: O(n^4))
// Gives TIME LIMIT EXCEEDED
class Solution {
public:

    static bool compareRows(const vector<int>& row1, const vector<int>& row2) {
        return row1 == row2;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        long long sum = nums[i]+nums[j];
                        sum+=nums[k];
                        sum+=nums[l];
                        if(sum==target){
                            vector<int> quadruplet = {nums[i], nums[j], nums[k], nums[l]};
                            sort(quadruplet.begin(), quadruplet.end());
                            result.push_back(quadruplet);
                        }
                    }
                }
            }
        }
        
        sort(result.begin(), result.end());
        auto last = unique(result.begin(), result.end(), compareRows);
        result.erase(last, result.end());
        return result;
    }
};
