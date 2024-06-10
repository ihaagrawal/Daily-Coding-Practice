// LCM And GCD (BASIC)
// https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1

class Solution {
  public:
    long long gcd(long long a, long long b){
        if(a % b == 0) return b;
        return gcd(b, a%b);
    }
    
    vector<long long> lcmAndGcd(long long A , long long B) {
        long long g = gcd(A, B);
        long long l = (A*B)/g;
        return {l, g};
    }
};
