// 455. Assign Cookies (EASY)
// https://leetcode.com/problems/assign-cookies/description/


//Time Complexity: O(nlogn) + O(mlogm) + O(n+m) 
//Space Complexity: O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(), m=s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=0, j=0;
        int count = 0;
        while(i<n && j<m){
            if(g[i]<=s[j]){
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};
