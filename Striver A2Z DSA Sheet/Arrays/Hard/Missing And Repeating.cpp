// Missing And Repeating (MEDIUM)
// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article


//Brute: Using double loop and linear search
//TIme: O(n^2)
//Space: O(1)
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int rep = -1, mis = -1;
        
        for(int i=1;i<=n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(arr[j] == i) count++;
            }
            
            if(count == 2) rep = i;
            else if(count == 0) mis = i;
            
            if(rep != -1 && mis != -1) break;
        }
        return {rep, mis};
    }
};


//Better: Use a map to store the elements, then check frequency of 2 and 0
//Time: Unordered Map -> O(2*n), Ordered Map -> O(nlogn) + O(n)
//Space: O(n)
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        
        int rep = 0, mis = 0;
        for(int i=1;i<=n;i++){
            if(mp[i] == 2) rep = i;
            if(mp[i] == 0) mis = i;
        }
        
        return {rep, mis};
    }
};



//Optimal: Using maths, find sum of first n integers (sn), sum of squares of first n integers (s2n)
//sum of array elements (s), sum of squares of array elements (s2)
//then use the eq: sn-s = x - y && s2n - s2 = X^2 - y^2, solve these two
//Time: O(n)
//Space: O(1)
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int rep = -1, mis = -1;

        long long sn = (n * 1LL * (n + 1)) / 2;
        long long s2n = (n * 1LL * (n + 1) * (2 * n + 1)) / 6;

        long long s = 0, s2 = 0;
        for (int i = 0; i < n; ++i) {
            s += arr[i];
            s2 += arr[i] * 1LL * arr[i];
        }

        long long val1 = sn - s;
        long long val2 = s2n - s2;

        val2 = val2 / val1;
        mis = (val1 + val2) / 2;
        rep = val2 - mis;

        return {rep, mis};
    }
};
