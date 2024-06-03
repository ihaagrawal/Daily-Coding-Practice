// Print Array in Reverse (VERY-EASY)
// https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/print-array-in-reverse/

#include <iostream>
#include <vector>

using namespace std;

void reverseArray(vector<int>& arr, int n){
	if(n==0) return;

	cout << arr[n-1] << endl;
	reverseArray(arr, n-1);
}

int main() {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin >> arr[i];

	reverseArray(arr, n);
	return 0;
}
