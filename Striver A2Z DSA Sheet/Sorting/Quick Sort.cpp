// Quick Sort (MEDIUM)
// https://www.geeksforgeeks.org/problems/quick-sort/1

//Time: O(nlogn)
//Space: O(logn)
class Solution
{
    public:
    int partition (int arr[], int low, int high)
    {
       int piv=arr[high], ind=low;
       for(int i=low;i<high;i++){
           if(arr[i]<piv){
               swap(arr[i], arr[ind]);
               ind++;
           }
       }
       swap(arr[ind], arr[high]);
       return ind;
    }
    
    void quickSort(int arr[], int low, int high)
    {
        if(low>high) return;
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
};
