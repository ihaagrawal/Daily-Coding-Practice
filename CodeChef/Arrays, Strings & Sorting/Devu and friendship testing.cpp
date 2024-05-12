// Devu and friendship testing (1061)
// https://www.codechef.com/practice/course/arrays-strings-sorting/INTARR01/problems/CFRTEST

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    set<int> st;
	    for(int i=0;i<n;i++){
	        int num;
	        cin>>num;
	        st.insert(num);
	    }
	    cout << st.size() << endl;
	}
	return 0;

}
