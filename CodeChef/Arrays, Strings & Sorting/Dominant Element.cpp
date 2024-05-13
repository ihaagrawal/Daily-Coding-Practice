// Dominant Element (1171)
// https://www.codechef.com/practice/course/arrays-strings-sorting/INTARR01/problems/DOMINANT2

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
	    int max_count = *max_element(count.begin(), count.end());
	    int max_ind = distance(count.begin(), find(count.begin(), count.end(), max_count));

        int found = 0;
	    for(int i=0;i<=max_ele;i++){
	        if(i!=max_ind && count[i]==max_count){
	            cout << "NO" << endl;
	            found = 1;
	            break;
	        }
	    }
	    if(found==0) cout << "YES" << endl;
	}
    return 0;
}
