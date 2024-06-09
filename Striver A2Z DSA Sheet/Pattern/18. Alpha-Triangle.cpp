// Alpha-Triangle (EASY)
// https://www.naukri.com/code360/problems/alpha-triangle_6581429

void alphaTriangle(int n) {
    for(int i=1;i<=n;i++){
        char ch = 'A' + (n-1);
        for(int j=1;j<=i;j++){
            cout << ch << " ";
            ch--;
        }cout << endl;
    }
}
