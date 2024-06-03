// Find all factorial numbers less than or equal to N (BASIC)
// https://www.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/0?problemType=functional&difficulty%255B%255D=-1&page=1&query=problemTypefunctionaldifficulty%255B%255D-1page1

class Solution
{
public:

    void factorial(long long n, long long current, long long factor, vector<long long>& result){
        if(current > n) return;
        
        result.push_back(current);
        factorial(n, current * factor, factor+1, result);
    }

    vector<long long> factorialNumbers(long long n)
    {
        vector<long long> result;
        factorial(n, 1, 2, result);
        return result;
    }
};
