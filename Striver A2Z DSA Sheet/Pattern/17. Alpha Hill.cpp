// Alpha Hill (EASY)
// https://www.naukri.com/code360/problems/alpha-hill_6581921

void alphaHill(int n) {
    int dir = 1;
    for(int i=1;i<=n;i++){
        char ch = 'A';
        for(int j=1;j<=(n-i)*2;j++) cout << " ";

        int index = (2*i)-1;
        for(int j=1;j<=index;j++){
            cout << ch << " ";
            if(j == (index/2)+1) dir = dir * (-1);
            ch = ch + dir;
        }
        dir = 1;
        cout << endl;
    }
}
