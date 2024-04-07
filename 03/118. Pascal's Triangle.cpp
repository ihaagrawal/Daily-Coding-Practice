// 118. Pascal's Triangle (EASY)
// https://leetcode.com/problems/pascals-triangle/description/

//Brute (Space: O(1), Time: O(n^2))
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows==0) return result;
        result.push_back({1});
        int j=0;
        for(int i=1;i<numRows;i++){
            vector<int> old=result.back();
            vector<int> vec={1};
            for(j=0;j<i-1;j++)
                vec.push_back(old[j]+old[j+1]);
            vec.push_back(1);
            result.push_back(vec);
        }
        return result;
    }
};

