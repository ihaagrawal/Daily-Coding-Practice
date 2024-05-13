// Distinct Colors (760)
// https://www.codechef.com/practice/course/arrays-strings-sorting/INTARR01/problems/DISTINCTCOL

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
	    
	    int max_count = *max_element(arr.begin(), arr.end());
	    
	    cout << max_count << endl;
	}

}
