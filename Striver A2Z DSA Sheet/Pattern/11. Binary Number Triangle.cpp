// Binary Number Triangle (EASY)
// https://www.naukri.com/code360/problems/binary-number-triangle_6581890

void nBinaryTriangle(int n) {
    for(int i=1;i<=n;i++){
      for(int j=1;j<=i;j++){
        if((j%2!=0 && i%2!=0) || (j%2==0 && i%2==0))
          cout << 1 << " ";
        else 
          cout << 0 << " ";
      }cout << endl;
    }
}
