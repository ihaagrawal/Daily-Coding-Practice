// Insertion Sort (EASY)
// https://www.geeksforgeeks.org/problems/insertion-sort/1

//Time: O(n^2)
//Space: O(n)
class Solution
{
    public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        if(n<=1) return;
        
        insertionSort(arr, n-1);
        
        int last = arr[n-1];
        int j = n-2;
        
        while(j>=0 && arr[j]>last){
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = last;
    }
};
