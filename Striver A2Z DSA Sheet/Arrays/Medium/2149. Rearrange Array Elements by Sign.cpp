// 2149. Rearrange Array Elements by Sign (MEDIUM)
// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/


//Brute: Take 2 queues to store positive and negative and then put them alternatively in result vector
//Time: O(n)
//Space: O(n)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        queue<int> pos, neg;

        for(int i=0;i<n;i++){
            if(nums[i] < 0) neg.push(nums[i]);
            else pos.push(nums[i]);
        }
        
        vector<int> result(n);
        int i = 0;
        while(!pos.empty() && !neg.empty()){
            if(i%2 == 0){
                result[i] = pos.front();
                pos.pop();
            }else{
                result[i] = neg.front();
                neg.pop();
            }
            i++;
        }

        while(!pos.empty()){
            result[i] = pos.front();
            pos.pop();
            i++;
        }

        while(!neg.empty()){
            result[i] = neg.front();
            neg.pop();
            i++;
        }
        
        return result;
    }
};


//Better: Take two pointers pos=0 and neg=1, traverse through nums
//if nums[i]<0 then result[neg] = nums[i] and increase neg by 2
//else if nums[i]>0 then result[pos] = nums[i] and increase pos by 2
//Time: O(n)
//Space: O(1)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int pos = 0, neg = 1;

        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                result[pos] = nums[i];
                pos += 2;
            }else{
                result[neg] = nums[i];
                neg += 2;
            }
        }

        return result;
    }
};
