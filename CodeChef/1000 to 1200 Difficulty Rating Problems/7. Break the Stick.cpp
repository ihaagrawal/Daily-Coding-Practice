// Break the Stick (1026)
// https://www.codechef.com/practice/course/1-star-difficulty-problems/DIFF1200/problems/BREAKSTICK?tab=statement

#include <bits/stdc++.h>
using namespace std;

bool checkParity(int n){
    return n%2==0;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        if(!checkParity(x)) cout << "YES" << endl;
        else{
            if(checkParity(n)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
