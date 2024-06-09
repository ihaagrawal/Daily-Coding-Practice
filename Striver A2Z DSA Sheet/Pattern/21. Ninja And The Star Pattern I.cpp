// Ninja And The Star Pattern I (EASY)
// https://www.naukri.com/code360/problems/ninja-and-the-star-pattern-i_6581920

void getStarPattern(int n) {
    for(int i=1;i<=n;i++){
      if(i==1 || i==n){
        for(int j=1;j<=n;j++) cout << "*";
      }else{
        for(int j=1;j<=n;j++){
          if(j==1 || j==n) cout << "*";
          else cout << " ";
        }
      }
      cout << endl;
    }
}
