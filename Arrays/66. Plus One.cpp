// 66. Plus One (EASY)
// https://leetcode.com/problems/plus-one/description/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=0, i=1;
        vector<int> result;
        
        reverse(digits.begin(), digits.end());
        int first = digits[0] + 1;
        if(first>9){
            first = first-10;
            carry=1;
        }
        result.push_back(first);

        while(i<n){
            digits[i] += carry;
            if(digits[i]>9){
                digits[i] = digits[i]-10;
                carry=1;
            }else{
                carry=0;
            }
            result.push_back(digits[i]);
            i++;
        }

        if(carry==1) result.push_back(carry);

        reverse(result.begin(), result.end());
        return result;
    }
};
