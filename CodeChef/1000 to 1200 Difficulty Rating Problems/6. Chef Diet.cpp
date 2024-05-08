// Chef Diet
// https://www.codechef.com/practice/course/1-star-difficulty-problems/DIFF1200/problems/DIET

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++) cin>>arr[i];
	    
	    int rem=0, ind=-1;
	    for(int i=0;i<n;i++){
	        arr[i] += rem;
	        rem = arr[i]-k;
	        if(rem<0){
	            ind = i;
	            break;
	        }
	    }
	    
	    if(ind==-1) cout << "YES" <<endl;
	    else cout << "NO " << ind+1 << endl;
	}

}
