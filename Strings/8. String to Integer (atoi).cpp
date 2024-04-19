// 8. String to Integer (atoi) (MEDIUM)
// https://leetcode.com/problems/string-to-integer-atoi/description/

//Brute (Space: O(1), Time: O(n))
class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();

        int i=0, sign=1;
        while(s[i]==32) i++;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+') i++;
        
        long long result=0;
        while(s[i]>='0' && s[i]<='9' && i<n){
            
            result=result*10+s[i]-'0';

            if(result*sign>INT_MAX) return INT_MAX;
            if(result*sign<INT_MIN) return INT_MIN;

            i++;
        }
        return (int)(result*sign);
    }
};
