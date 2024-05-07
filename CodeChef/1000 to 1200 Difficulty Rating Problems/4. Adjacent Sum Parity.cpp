// Adjacent Sum Parity (1013)
// https://www.codechef.com/practice/course/1-star-difficulty-problems/DIFF1200/problems/ADJSUMPAR

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, sum=0;
	    cin>>n;
	    int b[n];
	    for(int i=0;i<n;i++){
	        cin >> b[i];
	        sum += b[i];
	    }
	    if(sum%2==0) cout << "YES" << endl;
	    else cout << "NO" << endl;
	}

}
