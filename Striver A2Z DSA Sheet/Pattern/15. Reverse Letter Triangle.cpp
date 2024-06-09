// Reverse Letter Triangle (EASY)
// https://www.naukri.com/code360/problems/reverse-letter-triangle_6581906

void nLetterTriangle(int n) {
    for(int i=1;i<=n;i++){
        char ch = 'A';
        for(int j=1;j<=n-i+1;j++){
            cout << ch << " ";
            ch++; 
        }cout << endl;
    }
}
