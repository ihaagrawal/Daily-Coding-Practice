// Symmetry (EASY)
// https://www.naukri.com/code360/problems/symmetry_6581914

void symmetry(int n) {

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) cout << "* ";
        for(int j=1;j<=2*(n-i);j++) cout << " ";
        for(int j=1;j<=i;j++) cout << "* ";
        cout << endl;
    }
    
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i+1;j++) cout << "* ";
        for(int j=1;j<=2*(i-1);j++) cout << " ";
        for(int j=1;j<=n-i+1;j++) cout << "* ";
        cout << endl; 
    }
}
