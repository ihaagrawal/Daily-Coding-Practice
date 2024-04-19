// 5. Longest Palindromic Substring (MEDIUM)
// https://leetcode.com/problems/longest-palindromic-substring/description/

//Brute (Space: O(1), Time: O(n^3))
class Solution {
public:

    bool isPalindrome(string& s, int i, int j){
        if(i>=j) return true;
        if(s[i]==s[j]) return isPalindrome(s, i+1, j-1);
        return false;
    }

    string longestPalindrome(string s) {
        int n=s.length(), len=INT_MIN;
        int sp=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s, i, j)){
                    if(j-i+1 >= len){
                        len=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp, len);
    }
};

//Better (Space: O(n^2), Time: O(n^2))
class Solution {
public:
    int t[1001][1001];
    bool isPalindrome(string& s, int i, int j){
        if(i>=j) return true;
        if(t[i][j]!=-1) return t[i][j];
        if(s[i]==s[j]) return t[i][j] = isPalindrome(s, i+1, j-1);
        return t[i][j]=0;
    }

    string longestPalindrome(string s) {
        int n=s.length(), len=INT_MIN;
        memset(t, -1, sizeof(t));
        int sp=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s, i, j)){
                    if(j-i+1 >= len){
                        len=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp, len);
    }
};
