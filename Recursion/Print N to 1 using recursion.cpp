// Print N to 1 without loop (EASY)
// https://www.geeksforgeeks.org/problems/print-n-to-1-without-loop/1


class Solution {
  public:
    void printNos(int n) {
        if(n==0) return;
        cout << n << " ";
        printNos(n-1);
    }
};
