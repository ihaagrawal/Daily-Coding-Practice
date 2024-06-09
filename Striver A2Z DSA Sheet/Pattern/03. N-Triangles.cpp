// N-Triangles (EASY)
// https://www.naukri.com/code360/problems/n-triangles_6573689

void nTriangle(int n) {
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout << j << " ";
		}cout << endl;
	}
}
