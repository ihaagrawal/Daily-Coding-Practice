// Alpha-Ramp (EASY)
// https://www.naukri.com/code360/problems/alpha-ramp_6581888

void alphaRamp(int n) {
    char ch = 'A';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << ch << " ";
        }cout << endl;
        ch++;
    }
}
