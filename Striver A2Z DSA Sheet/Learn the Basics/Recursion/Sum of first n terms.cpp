// Sum of first n terms (EASY)
// https://www.geeksforgeeks.org/problems/sum-of-first-n-terms5843/1


class Solution {
  public:
  
    void sumNums (long long& sum, long long n){
        if(n==0) return;
        
        sum += n*n*n;
        sumNums(sum, n-1);
    }
  
    long long sumOfSeries(long long n) {
        long long sum = 0;
        sumNums(sum, n);
        return sum;
    }
};
