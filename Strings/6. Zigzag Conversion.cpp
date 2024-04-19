// 6. Zigzag Conversion (MEDIUM)
// https://leetcode.com/problems/zigzag-conversion/

//n->length of string
//Brute (Space: O(1), Time: O(n^2))
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string result;
        int jump=(numRows-1)*2;
        for(int i=0;i<numRows;i++){
            for(int j=i;j<s.length();j+=jump){
                result += s[j];
                int mid_jump = jump-(2*i);
                if(i>0 && i<numRows-1 && mid_jump+j<s.length()) 
                    result += s[j+mid_jump];
            }
        }
        return result;
    }
};

//Better (Space: O(n), Time: O(n))
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int d=1, k=0;
        vector<string> res(numRows);
        for(int i=0;i<s.length();i++){
            res[k].push_back(s[i]);
            if(k==0) d=1;
            else if(k==numRows-1) d=-1;
            k+=d;
        }
        string result;
        for(auto c:res) result+=c;
        return result;
    }
};
