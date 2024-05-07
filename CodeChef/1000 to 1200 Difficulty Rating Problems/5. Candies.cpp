// Candies (1018)
// https://www.codechef.com/practice/course/1-star-difficulty-problems/DIFF1200/problems/CNDY?tab=statement


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isValidPrices(int N, vector<int>& A) {
    unordered_map<int, int> freq;

    for (int num : A) {
        freq[num]++;
        if (freq[num] > 2) {
            return false;
        }
    }

    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(2 * N);
        for (int i = 0; i < 2 * N; ++i) {
            cin >> A[i];
        }

        if (isValidPrices(N, A)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
