// Largest subarray with 0 sum (MEDIUM)
// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

//Brute (Space: O(1), Time: O(n^2))
//Gives TIME LIMIT EXCEEDED
class Solution{
public:
    int maxLen(vector<int>&A, int n)
    {   
        int max_len = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += A[j];
                if(sum == 0){
                    int len = j - i + 1;
                    max_len = max(len, max_len);
                }
            }
        }
        return max_len;
    }
};
