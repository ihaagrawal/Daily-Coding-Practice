// Number Crown (EASY)
// https://www.naukri.com/code360/problems/number-crown_6581894

void numberCrown(int n) {
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) cout << j << " ";
        for(int j=1;j<(2*n)-(i*2);j++) cout << " ";
        for(int j=i;j>=1;j--) cout << j << " ";
        cout << endl;
    }
}
