// 728. Self Dividing Numbers (EASY)
// https://leetcode.com/problems/self-dividing-numbers/

class Solution {
public:

    bool divNum(int n){
        int num = n;
        while(num>0){
            int rem = num%10;
            if(rem==0 || n%rem != 0) return false;
            num = num / 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i=left;i<=right;i++){
            if(divNum(i)) result.push_back(i);
        }
        return result;
    }
};
