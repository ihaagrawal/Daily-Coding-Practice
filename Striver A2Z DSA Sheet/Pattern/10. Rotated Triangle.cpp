// Rotated Triangle (EASY)
// https://www.naukri.com/code360/problems/rotated-triangle_6573688

void nStarTriangle(int n) {
    for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cout << "*";
		}
		cout << endl;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			cout << "*";
		}cout << endl;
	}
}
