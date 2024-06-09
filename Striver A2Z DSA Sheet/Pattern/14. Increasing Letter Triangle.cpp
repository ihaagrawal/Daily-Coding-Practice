// Increasing Letter Triangle (EASY)
// https://www.naukri.com/code360/problems/increasing-letter-triangle_6581897

void nLetterTriangle(int n) {
    for(int i=1;i<=n;i++){
        char ch = 'A';
        for(int j=1;j<=i;j++){
            cout << ch << " ";
            ch++;
        }cout << endl;
    }
}
