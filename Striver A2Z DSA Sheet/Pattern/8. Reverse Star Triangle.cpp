// Reverse Star Triangle (EASY)
// https://www.naukri.com/code360/problems/reverse-star-triangle_6573685

void nStarTriangle(int n) {
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++) cout << " ";
        for(int j=1;j<=((2*(n-i))+1);j++) cout << "*";
        cout << endl;
    }
}
