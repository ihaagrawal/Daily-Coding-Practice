// 3019. Number of Changing Keys (EASY)
// https://leetcode.com/problems/number-of-changing-keys/description/

class Solution {
public:
    int countKeyChanges(string s) {
        int n=s.length(), count=0;
        for(int i=1;i<n;i++){
            if(abs(s[i]-s[i-1])!=32 && abs(s[i]-s[i-1])!=0) count++;
        }
        return count;
    }
};
