// Floor in a Sorted Array (EASY)
// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&%253BbatchId=154


//Brute: Linear Search for lower bound
//Time: O(n)
//Space: O(1)
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> arr, long long n, long long x){
        int index = -1;
        for(int i=1;i<n;i++){
            if(arr[i] == x) return i;
            else if(arr[i] < x) index = i;
        }
        return index;
    }
};


//Better: Binary Search for lower bound
//Time: O(logn)
//Space: O(1)
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> arr, long long n, long long x){
        int low = 0, high = n-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] == x) return mid;
            else if(arr[mid] > x) high = mid - 1;
            else low = mid + 1;
        }
        
        return high;
    }
};
