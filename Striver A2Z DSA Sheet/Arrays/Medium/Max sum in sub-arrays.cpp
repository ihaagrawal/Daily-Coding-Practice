// Max sum in sub-arrays (EASY)
// https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0?category


//Brute: For each subarray find smallest and second smallest and find their sum
//Gives TLE for large inputs
//Time: O(n^2)
//Space: O(1)
class Solution{
    public:
        long long pairWithMaxSum(long long nums[], long long n){
            long long maxSum = LLONG_MIN;
            
            for(int i=0;i<n-1;i++){
                long long smallest = nums[i], second = LLONG_MAX;;
                for(int j=i+1;j<n;j++){
                    if(nums[j] < smallest){
                        second = smallest;
                        smallest = nums[j];
                    }else if(nums[j] < second){
                        second = nums[j];
                    }
                    
                    if(second != LLONG_MAX){
                        long long sum = smallest + second;
                        maxSum = max(sum, maxSum);
                    }
                }
            }
            
            return maxSum;
        }
    
};


//Better:
//Indirectly this question is same as the max sum of consecutive numbers 
//because the two numbers will always be the smallest and second smallest 
//for the subarray of two elements
//Time: O(n)
//Space: O(1)
class Solution{
    public:
        long long pairWithMaxSum(long long nums[], long long n){
            long long maxSum = LLONG_MIN;
            for(int i=1;i<n;i++){
                long long sum = nums[i] + nums[i-1];
                maxSum = max(sum, maxSum);
            }
            return maxSum;
        }
};
