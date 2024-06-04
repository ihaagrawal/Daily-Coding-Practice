// 229. Majority Element II (MEDIUM)
// https://leetcode.com/problems/majority-element-ii/description/

//Brute (Space: O(1), Time: O(n^2) + O(nlogn))
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size(), count=1;
        vector<int> result;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]) count++;
            }
            if(count>n/3) result.push_back(nums[i]);
            count=1;
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};

//Better (Space: O(n), Time: O(n))
//unordered_map takes O(1) to insert in map
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map <int, int> mp;
        int n=nums.size();
        vector<int> result;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==(n/3)+1) result.push_back(nums[i]);
        }

        return result;
    }
};

//Extended Moore's Voting Algorithm
//Optimal (Space: O(1), Time: O(2n))

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count1=0, count2=0, ele1, ele2;
        vector<int> result;
        for(int i=0;i<n;i++){
            if(count1==0 && ele2!=nums[i]){
                count1=1;
                ele1=nums[i];
            }
            else if(count2==0 && ele1!=nums[i]){
                count2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1) count1++;
            else if(nums[i]==ele2) count2++;
            else{
                count1--;
                count2--;
            }
        }

        count1=0, count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1) count1++;
            else if(nums[i]==ele2) count2++;
        }

        if(count1>n/3) result.push_back(ele1);
        if(count2>n/3) result.push_back(ele2);
        return result;
    }
};

//for n/3 there can be maximum 2 majority elements
//if n=6, n/3=2
//this means for an element to be majority, it should occur at least 2 times
//this is only possible with max 2 majority elements

//if n=9, n/3=3
//this means for an element to be majority, it should occur at least 3 times
//this is only possible with max 2 majority elements

