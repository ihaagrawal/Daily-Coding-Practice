// 14. Longest Common Prefix (EASY)
// https://leetcode.com/problems/longest-common-prefix/description/

//Better (Space: O(1), Time: O(n))
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int n=strs.size();
        string prefix=strs[0];
        for(int i=1;i<n;i++){
            int j=0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j])
                j++;
            prefix.erase(j);
        }
        return prefix;
    }
};
