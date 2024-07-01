// Ceil The Floor (EASY)
// https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1


//Brute: Using Linear Search
//Time: O(n)
//Space: O(1)
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr, arr+n);
    int fl = -1, ce = -1;
    
    for(int i=n-1;i>=0;i--){
        if(arr[i] <= x){
            fl = arr[i];
            break;
        }
    }
    
    for(int i=0;i<n;i++){
        if(arr[i] >= x){
            ce = arr[i];
            break;
        }
    }
    
    return {fl, ce};
}


//Better: Binary Search 
//Time: O(log n)
//Space: O(n)
int getresult(int arr[], int n, int x, int flag){
    int low = 0, high = n-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == x) return arr[mid];
        else if(arr[mid] > x) high = mid - 1;
        else low = mid + 1;
    }
    
    if(flag == 0){
        return (high >= 0) ? arr[high] : -1;
    }else{
        return (low < n) ? arr[low] : -1;
    }
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr, arr+n);
    int fl = getresult(arr, n, x, 0);
    int ce = getresult(arr, n, x, 1);
    
    return {fl, ce};
}
