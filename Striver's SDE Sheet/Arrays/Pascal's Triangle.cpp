//Variation 1: Given row r and column c, return the element at (r, c) in the pascal's triangle
//Time Complexity: O(r)
//Space Complexity: O(1)
long long ncr(int n, int r){
	long long res = 1;
	for(int i=0;i<r;i++){
		res = res * (n-i);
		res = res / (i+1);
	}
	return res;
}


//Variation 2: Given row number n, print nth row of triangle

//119. Pascal's Triangle II
//https://leetcode.com/problems/pascals-triangle-ii/description/

//Brute
//Time Complexity: O(rowIndex * r)
//Space Complexity: O(1)
class Solution {
public:

    long long ncr(int n, int r){
        long long res = 1;
        for(int i=0;i<r;i++){
            res = res * (n-i);
            res = res / (i+1);
        }
        return res;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for(int i=0;i<=rowIndex;i++){
            long long res = ncr(rowIndex, i);
            result.push_back(res);
        }
        return result;
    }
};


//Better
//Time Complexity: O(rowIndex)
//Space Complexity: O(1)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result = {1};
        long long res = 1;
        for(int i=1;i<=rowIndex;i++){
            res = res * (rowIndex+1 - i);
            res = res / i;
            result.push_back(res);
        }
        return result;
    }
};



//Variation 3: Given the number of rows n, print the first n rows

// Pascal's Triangle (EASY)
// https://leetcode.com/problems/pascals-triangle/description/




