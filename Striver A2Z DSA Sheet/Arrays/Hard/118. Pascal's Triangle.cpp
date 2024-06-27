// 118. Pascal's Triangle (EASY)
// https://leetcode.com/problems/pascals-triangle/description/


//Brute: Using the row number(n) and column number(r) to find out nCr
//Time: O(n^3)
//Space: O(n^2)
class Solution {
public:

    int generate(int n, int r){
        int res = 1;
        for(int i=0;i<r;i++){
            res *= (n-i);
            res /= (i+1);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        int n = numRows, r = numRows;
        vector<vector<int>> result;

        for(int i=0;i<n;i++){
            vector<int> row;
            for(int j=0;j<=i;j++){
                int num = generate(i, j);
                row.push_back(num);
            }
            result.push_back(row);
        }

        return result;
    }
};

//Better: create a vector for each row, using the previos row
//Time: O(n^2)
//Space: O(n^2)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> result;
        
        //if numRows = 0
        if(n == 0) return result;

        //if numRows = 1
        result.push_back({{1}});

        //numRows > 1
        for(int i=2;i<=n;i++){
            vector<int> prev = result.back();
            vector<int> temp = {1};

            for(int j=1;j<i-1;j++){
                int num = prev[j] + prev[j-1];
                temp.push_back(num);
            }
            temp.push_back(1);
            result.push_back(temp);
        }

        return result;
    }
};


//Optimal: Using the observation Current element = prevElement * (rowNumber - colIndex) / colIndex
//Time: O(n^2)
//Space: O(n^2)
class Solution {
public:

    vector<int> generated(int n){
        int ans = 1;
        vector<int> row;
        row.push_back(1);

        for(int i=1;i<n;i++){
            ans *= (n-i);
            ans /= i;
            row.push_back(ans);
        }
        return row;
    }

    vector<vector<int>> generate(int numRows) {
        int n = numRows, r = numRows;
        vector<vector<int>> result;

        for(int i=1;i<=n;i++){
            result.push_back(generated(i));
        }

        return result;
    }
};
