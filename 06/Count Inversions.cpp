// Count Inversions (MODERATE)
// https://www.naukri.com/code360/problems/count-inversions_615?leftPanelTabValue=PROBLEM

//Brute (Space: O(1), Time: O(n^2))
#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    int i=0, j=n-1;
    long long inv=0;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]) inv++;
        }
    }
    return inv;
}

//Better (Space: O(n), Time: O(nlogn))
long long merge(long long arr[], int left, int mid, int right){
    int i = left, j = mid, k = 0;
    long long invCount = 0;
    int temp[(right - left + 1)];

    while ((i < mid) && (j <= right)){
        if (arr[i] <= arr[j]){
            temp[k] = arr[i];
            ++k;
            ++i;
        }
        else{
            temp[k] = arr[j];
            invCount += (mid - i);
            ++k;
            ++j;
        }
    }

    while (i < mid){
        temp[k] = arr[i];
        ++k;
        ++i;
    }

    while (j <= right){
        temp[k] = arr[j];
        ++k;
        ++j;
    }

    for (i = left, k = 0; i <= right; i++, k++){
        arr[i] = temp[k];
    }

    return invCount;
}

long long mergeSort(long long arr[], int left, int right){
    long long invCount = 0;

    if (right > left){
        int mid = (right + left) / 2;
        invCount = mergeSort(arr, left, mid);
        invCount += mergeSort(arr, mid + 1, right);
        invCount += merge(arr, left, mid + 1, right);
    }
    return invCount;
}

long long getInversions(long long arr[], int n){
    return mergeSort(arr, 0, n - 1);
}
