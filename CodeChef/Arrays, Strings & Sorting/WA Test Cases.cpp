// WA Test Cases (976)
// https://www.codechef.com/practice/course/sorting/SORTING/problems/WATESTCASES

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> sizes(n);
        for(int i = 0; i < n; i++) {
            cin >> sizes[i];
        }
        string v;
        cin >> v;
        
        int smallest = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(v[i] == '0') {
                smallest = min(smallest, sizes[i]);
            }
        }
        cout << smallest << endl;
    }
    return 0;
}
