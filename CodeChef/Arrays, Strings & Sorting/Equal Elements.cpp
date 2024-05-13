// Equal Elements (1123)
// https://www.codechef.com/practice/course/arrays-strings-sorting/INTARR01/problems/EQUALELE

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        int max_ele = *max_element(arr.begin(), arr.end());
        
        vector<int> count(max_ele+1, 0); 
        for(int i=0;i<n;i++) count[arr[i]]++;
        
        int max_ind = distance(count.begin(), max_element(count.begin(), count.end()));
        count[max_ind] = -1;
        
        int total_ops = 0; 
        for(int i=0;i<=max_ele;i++){ 
            if(count[i]!=-1) total_ops+=count[i];  
        }
        cout << total_ops << endl; 
    }
    return 0;
}
