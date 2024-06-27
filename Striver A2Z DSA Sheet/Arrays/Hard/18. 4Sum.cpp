// 18. 4Sum (MEDIUM)
// https://leetcode.com/problems/4sum/description/

//Brute: Run 4 loops and check the sum
// Gives TLE
//Time: O(n^4)
//Space: O(1)
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


//Better: Use 3 loops and a set
//Time: O(n^3)
//Space: O(n)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<long long> temp;
                for(int k=j+1;k<n;k++){
                    long long sum = nums[i]+nums[j];
                    sum+=nums[k];
                    long long fourth=target-sum;
                    if(temp.find(fourth)!=temp.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    temp.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
};

//Optimal: Fix i and j, and move k and l
//Time: O(n^3)
//Space: O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1, l=n-1;
                while(k<l){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum==target){
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++, l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum<target) k++;
                    else l--;
                }
            }
        }
        return result;
    }
};
