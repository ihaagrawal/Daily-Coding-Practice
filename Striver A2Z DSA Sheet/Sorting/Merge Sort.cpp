// Merge Sort (MEDIUM)
// https://www.geeksforgeeks.org/problems/merge-sort/1


//Time: O(nlogn)
//Space: O(n)
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int left=l, right=m+1;
        int temp[r-l+1], ind=0;
        while(left<=m && right<=r){
            if(arr[left]<=arr[right]){
                temp[ind]=arr[left];
                left++;
            }
            else{
                temp[ind]=arr[right];
                right++;
            }
            ind++;
        }
        
        while(left<=m){
            temp[ind]=arr[left];
            left++;
            ind++;
        }
        
        while(right<=r){
            temp[ind]=arr[right];
            right++;
            ind++;
        }
        
        ind=0;
        while(l<=r){
            arr[l]=temp[ind];
            l++;
            ind++;
        }
        
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l<r){
            int mid=(l+r)/2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid+1, r);
            merge(arr, l, mid, r);
        }
    }
};
