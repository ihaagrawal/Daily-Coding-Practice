// 493. Reverse Pairs (HARD)
// https://leetcode.com/problems/reverse-pairs/description/


//Brute: Use nested loop to check for each element of the array
//Time: O(n^2)
//Space: O(1)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long num1 = nums[i];
                long long num2 = 2LL * nums[j];
                if(num1 > num2) count++;
            }
        }
        return count;
    }
};



//Better: Using merge sort
//Time: O(nlogn)
//Space: O(n)
class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right){
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
    
    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2LL * arr[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergesort(vector<int>& arr, int left, int right){
        int count = 0;
        if(left < right){
            int mid = (left+right)/2;
            count += mergesort(arr, left, mid);
            count += mergesort(arr, mid+1, right);
            count += countPairs(arr, left, mid, right);
            merge(arr, left, mid, right);
        }
        return count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(nums, 0, n-1);
    }
};
