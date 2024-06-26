// Array Leaders (EASY)
// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

//Brute: Check each element with its right side elements
//Gives TLE for large input
//Time: O(n^2)
//Space: O(n)
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int nums[]) {
        vector<int> result;
        for(int i=0;i<n;i++){
            int flag = 1;
            for(int j=i+1;j<n;j++){
                if(nums[i] < nums[j]) flag = 0;
            }
            if(flag) result.push_back(nums[i]);
        }
        return result;
    }
};


//Better: The rightmost element will always be the leader
//Take last element as the largest and put it into result
//Traverse from behind if element > largest, push it into result and largest = element
//Time: O(n)
//Space: O(n)
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int nums[]) {
        vector<int> result;
        int largest = nums[n-1];
        result.push_back(largest);
        
        for(int i=n-2;i>=0;i--){
            if(nums[i] >= largest){
                largest = nums[i];
                result.push_back(largest);
            }    
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
