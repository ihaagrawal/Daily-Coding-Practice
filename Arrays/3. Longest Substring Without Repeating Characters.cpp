// 3. Longest Substring Without Repeating Characters (MEDIUM)
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/


//Better (Space: O(n), Time: O(2*n))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(), len=0;
        set<char> st;
        int j=0;
        for(int i=0;i<n;i++){
            while(j<i && st.find(s[i])!=st.end()){
                st.erase(s[j]);
                j++;
            }
            st.insert(s[i]);
            len=max(len, i-j+1);
        }
        return len;
    }
};

//Optimal (Space: O(n), Time: O(n))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(256, -1);
        int n=s.length();
        int l=0, i=0, len=0;
        while(i<n){
            if(count[s[i]]!=-1) l=max(count[s[i]]+1, l);
            count[s[i]]=i;
            len=max(len, i-l+1);
            i++;
        }
        return len;
    }
};
