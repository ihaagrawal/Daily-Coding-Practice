// Count Inversions (MEDIUM)
// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1


//Brute: Using double loop to traverse through the array and count the inversions
//Time: O(n^2)
//Space: O(1)
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], int n) {
        long long int count = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i] > arr[j]) count++;
            }
        }
        return count;
    }
};


//Better: Using Merge Sort
//Time: O(nlogn)
//Space: O(n)
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int count = 0;
    
    void merge(long long arr[], int left, int mid, int right){
        int n1 = mid-left+1, n2 = right-mid;
        vector<long long> l(n1), r(n2);
        
        for(int i=0;i<n1;i++) l[i] = arr[left+i];
        for(int i=0;i<n2;i++) r[i] = arr[mid+i+1];
        
        int i=0, j=0, k=left;
        while(i<n1 && j<n2){
            if(l[i] <= r[j]){
                arr[k] = l[i];
                i++;
            }else{
                arr[k] = r[j];
                j++;
                count += (long long)(n1 - i);
            }
            k++;
        }
        
        while(i<n1){
            arr[k] = l[i];
            i++;
            k++;
        }
        
        while(j<n2){
            arr[k] = r[j];
            j++;
            k++;
        }
        
    }
    
    
    void mergesort(long long arr[], int left, int right){
        if(left < right){
            int mid = (left+right)/2;
            mergesort(arr, left, mid);
            mergesort(arr, mid+1, right);
            merge(arr, left, mid, right);
        }
    }
    
    long long int inversionCount(long long arr[], int n) {
        mergesort(arr, 0, n-1);
        return count;
    }
};
