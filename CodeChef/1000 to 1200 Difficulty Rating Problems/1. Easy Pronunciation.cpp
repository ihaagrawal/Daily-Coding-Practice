// Easy Pronunciation
// https://www.codechef.com/practice/course/1-star-difficulty-problems/DIFF1200/problems/EZSPEAK

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, count=0;
	    bool found=false;
	    string s;
	    cin>>n;
	    cin>>s;
	    for(int i=0;i<n;i++){
	    if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
	        count=0;
	        continue;
	    }
	    else{
	           count++;
	           if(count==4)
	           break;
	       }
	    }
	    if(count<4) cout << "YES" << endl;
	    else cout << "NO" << endl;
	}
	return 0;

}
