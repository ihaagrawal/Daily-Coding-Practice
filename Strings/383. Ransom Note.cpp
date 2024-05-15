// 383. Ransom Note (EASY)
// https://leetcode.com/problems/ransom-note/description/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());

        int n=ransomNote.length(), m=magazine.length();
        if(n>m) return false;

        int j=0, i=0;
        for(i=0;i<m;i++){
            if(ransomNote[j]!=magazine[i]){
                continue;
            }
            j++;
        }
        if(i==m && j<n) return false;

        return true;
    }
};
