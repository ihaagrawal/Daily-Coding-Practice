// Chef and Dolls (1012)
// https://www.codechef.com/practice/course/arrays-strings-sorting/INTARR01/problems/MISSP

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n); 
        for (int i = 0; i < n; i++) cin >> arr[i];
        int max_ele = *max_element(arr.begin(), arr.end());
        vector<int> count(max_ele + 1, 0); 
        for (int i = 0; i < n; i++) {
            count[arr[i]]++;
        }
        for (int i = 0; i <= max_ele; i++) { 
            if (count[i] % 2 != 0) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
