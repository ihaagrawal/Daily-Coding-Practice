// 125. Valid Palindrome (EASY)
// https://leetcode.com/problems/valid-palindrome/description/

class Solution {
public:

    bool check(string& result, int left, int right){
        if(left >= right) return true;
        if(result[left] != result[right]) return false;
        return check(result, left+1, right-1);
    }

    bool isPalindrome(string s) {
        int n = s.length();
        string result;

        for(char ch : s){
            if(isalnum(ch)){
                result += tolower(ch);
            }
        }

        return check(result, 0, result.length()-1);
    }
};
