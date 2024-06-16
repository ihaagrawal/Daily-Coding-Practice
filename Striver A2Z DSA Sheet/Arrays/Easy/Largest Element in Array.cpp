// Largest Element in Array (BASIC)
// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/0


//Time: O(n)
//Space: O(1)
class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int largest = INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i] > largest){
                largest = arr[i];
            }
        }
        
        return largest;
    }
};
