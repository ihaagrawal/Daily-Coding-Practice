// Increasing Number Triangle (EASY)
// https://www.naukri.com/code360/problems/increasing-number-triangle_6581893

void nNumberTriangle(int n) {
    int count = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << count << " ";
            count++;
        }cout << endl;
    }
}
