// Print GFG n times (EASY)
// https://www.geeksforgeeks.org/problems/print-gfg-n-times/1


class Solution {
  public:
    void printGfg(int n) {
        if(n==0) return;
        printGfg(n-1);
        cout << "GFG" << " ";
    }
};
