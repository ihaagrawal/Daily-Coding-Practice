// Seeding (EASY)
// https://www.naukri.com/code360/problems/seeding_6581892

void seeding(int n) {
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			cout << "* ";
		}cout << endl;
	}
}
