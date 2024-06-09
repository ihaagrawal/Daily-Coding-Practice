// 7. Reverse Integer (MEDIUM)
// https://leetcode.com/problems/reverse-integer/description/

class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        int sign = 1;

        if(x<0){
            sign *= -1;
            if(x == INT_MIN) return 0;
            x *= sign;
        }

        while(x>0){
            int rem = x%10;
            if(rev > INT_MAX || rev < INT_MIN) return 0;
            rev = rev*10 + rem;
            x/=10;
        }

        if(rev*sign > INT_MAX || rev*sign < INT_MIN) return 0;
        return rev*sign;
    }
};
