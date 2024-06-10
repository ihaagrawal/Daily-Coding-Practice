// Armstrong Numbers (EASY)
// https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1

class Solution {
  public:
    string armstrongNumber(int n){
        int sum = 0, num = n;
        
        while(n>0){
            int rem = n%10;
            sum += pow(rem, 3);
            n /= 10;
        }
        if(sum == num) return "Yes";
        return "No";
    }
};
