// A. Bit++
// https://codeforces.com/problemset/problem/282/A

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int n, x=0, newx=0;
    string str;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str;
        if(str=="X++"){
            x++;
            newx=x;
        }
        if(str=="X--"){
            x--;
            newx=x;
        }
        if(str=="++X"){
            newx++;
            x=newx;
        }
        if(str=="--X"){
            newx--;
            x=newx;
        }
    }
    cout<<x;
    return 0;
}
