// ATM Machine (1001)
// https://www.codechef.com/practice/course/1-star-difficulty-problems/DIFF1200/problems/ATM2

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    vector<int> result;
	    for(int i=0;i<n;i++) cin >> arr[i];
	    for(int i=0;i<n;i++){
	        if(arr[i]<=k){
	            k-=arr[i];
	            result.push_back(1);
	        }
	        else{
	            result.push_back(0);
	        }
	    }
	    
	    for(auto it:result) cout<<it;
	    cout<<endl;
	}

}
