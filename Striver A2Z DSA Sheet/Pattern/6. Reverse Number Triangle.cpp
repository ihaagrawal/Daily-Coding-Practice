// Reverse Number Triangle (EASY)
// https://www.naukri.com/code360/problems/reverse-number-triangle_6581889

void nNumberTriangle(int n) {
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout << j << " ";
        }cout << endl;
    }
}
