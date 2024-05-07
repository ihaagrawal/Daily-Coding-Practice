// TCS Examination (1006)
// https://www.codechef.com/practice/course/1-star-difficulty-problems/DIFF1200/problems/EXAMTIME

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int dr[3];
	    int sl[3];
	    int sumd=0, sums=0;
	    
	    for(int i=0;i<3;i++){
	        cin >> dr[i];
	        sumd += dr[i];
	    }
	    for(int i=0;i<3;i++){
	        cin >> sl[i];
	        sums += sl[i];
	    }
	    
	    if(sumd<sums) cout << "Sloth" << endl;
	    else if(sumd>sums) cout << "Dragon" << endl;
	    else{
	        if(dr[0]>sl[0]) cout << "Dragon" << endl;
	        else if(sl[0]>dr[0]) cout << "Sloth" << endl;
	        else if(dr[1]>sl[1]) cout << "Dragon" << endl;
	        else if(sl[1]>dr[1]) cout << "Sloth" << endl;
	        else if(dr[2]>sl[2]) cout << "Dragon" << endl;
	        else if(sl[2]>dr[2]) cout << "Sloth" << endl;
	        else cout << "Tie" << endl;
	    }
	    
	}

}
