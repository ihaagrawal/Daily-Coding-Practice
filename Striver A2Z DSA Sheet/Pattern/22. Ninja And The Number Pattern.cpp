// Ninja And The Number Pattern (EASY)
// https://www.naukri.com/code360/problems/ninja-and-the-number-pattern-i_6581959?leftPanelTabValue=PROBLEM

void getNumberPattern(int n) {
    for(int i=1;i<=(2*n)-1;i++){
        for(int j=1;j<=(2*n)-1;j++){
            int top=i-1, left=j-1, bottom=(2*n)-i-1, right=(2*n)-j-1;
            cout << (n - min(min(top, bottom), min(left, right)));
        }cout << endl;
    }
    
}
