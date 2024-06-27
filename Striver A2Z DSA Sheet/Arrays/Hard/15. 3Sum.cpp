// 15. 3Sum (MEDIUM)
// https://leetcode.com/problems/3sum/description/


//Brute: Run three loops for i, j, k and check their sum 
//Gives TLE
//Time: O(n^3)
//Space: O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                }    
            }
        }

        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }
};


//Better: Use 2 loops, and a set, find the diff = -(nums[i] + nums[j]) in the set
//Gives TLE
//Time: O(n^2)
//Space: O(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;

        for(int i=0;i<n;i++){
            set<int> st;
            for(int j=i+1;j<n;j++){
                int diff = -(nums[i] + nums[j]);

                if(st.find(diff) != st.end()){
                    vector<int> temp = {nums[i], nums[j], diff};
                    sort(temp.begin(), temp.end());
                    if(find(result.begin(), result.end(), temp) == result.end())
                        result.push_back(temp);
                }
                st.insert(nums[j]);
            }
        }

        return result;
    }
};


//Optimal: Sort the array, fix the value of i, move j and k whenever required
//Time: O(n^2) + O(nlogn)
//Space: O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n-2;i++){
            if(i!=0 && nums[i] == nums[i-1])continue;

            int j = i+1, k = n-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0) k--;
                else if(sum < 0) j++;
                else{
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(k > j && nums[k] == nums[k+1]) k--;
                }
            }
        }

        return result;
    }
};
