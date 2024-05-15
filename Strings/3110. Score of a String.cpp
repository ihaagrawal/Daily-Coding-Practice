// 3110. Score of a String (EASY)
// https://leetcode.com/problems/score-of-a-string/description/

class Solution {
public:
    int scoreOfString(string s) {
        int n=s.length(), sum=0;
        for(int i=1;i<n;i++){
            sum += abs(s[i]-s[i-1]);
        }
        return sum;
    }
};
