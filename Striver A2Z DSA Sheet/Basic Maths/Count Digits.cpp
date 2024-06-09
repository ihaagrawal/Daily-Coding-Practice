// Count Digits (EASY)
// https://www.geeksforgeeks.org/problems/count-digits5716/1

class Solution{
public:
    int evenlyDivides(int N){
        int n = N, count = 0;
        while(n>0){
            int rem = n%10;
            if(rem > 0 && N % rem == 0 ) count++;
            n /= 10;
        }
        return count;
    }
};
