// Bubble Sort (EASY)
// https://www.geeksforgeeks.org/problems/bubble-sort/1

//Time: O(n^2)
//Space: O(n)
class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n) {
       if(n==0) return;
       
       for(int i=1;i<n;i++){
           if(arr[i] < arr[i-1]){
               swap(arr[i], arr[i-1]);
           }
       }
       
       bubbleSort(arr, n-1);
    }
};
