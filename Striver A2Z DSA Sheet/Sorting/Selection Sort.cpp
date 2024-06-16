// Selection Sort (EASY)
// https://www.geeksforgeeks.org/problems/selection-sort/1

//Time: O(n^2)
//Space: O(1)
class Solution
{
    public:
    void selectionSort(int arr[], int n)
    {
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i] > arr[j]){
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
};
