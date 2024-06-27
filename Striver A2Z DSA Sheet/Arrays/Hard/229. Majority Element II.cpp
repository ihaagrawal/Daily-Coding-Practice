// 229. Majority Element II (MEDIUM)
// https://leetcode.com/problems/majority-element-ii/description/


//Brute: Count the frequency of each number and check if it is greater than n/3
//Time: O(n^3)
//Space: O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj = n/3;
        vector<int> elements;

        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(nums[i] == nums[j]) count++;
            }
            auto it = find(elements.begin(), elements.end(), nums[i]);
            if(count > maj && it == elements.end()) elements.push_back(nums[i]);
        }
        return elements;
    }
};


//Better: Use a map to store frequency of each element
//Time: Unordered_map -> O(n), Ordered_map -> O(nlogn)
//Space: O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj = n/3;
        vector<int> result;
        map<int,int> mp;

        for(int i=0;i<n;i++) mp[nums[i]]++;

        for(auto it : mp){
            if(it.second > maj) result.push_back(it.first);
        }

        return result;
    }
};


//Optimal: Using Boyer-Moore Voting Algo
//Keep count of element, if element is found count++ else count--
//Time: O(n)
//Space: O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj = n/3;
        int count1 = 0, count2 = 0;
        int ele1, ele2;

        for(int i=0;i<n;i++){
            if(count1 == 0 && nums[i] != ele2){
                count1++;
                ele1 = nums[i];
            }else if(count2 == 0 && nums[i] != ele1){
                count2++;
                ele2 = nums[i];
            }else if(ele1 == nums[i]) count1++;
            else if(ele2 == nums[i]) count2++;
            else{
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == ele1) count1++;
            else if(nums[i] == ele2) count2++;
        }

        vector<int> result;
        if(count1 > maj) result.push_back(ele1);
        if(count2 > maj) result.push_back(ele2);

        return result;
    }
};
