// 263.A Beautiful Matrix
// https://codeforces.com/problemset/problem/263/A

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> matrix(5, vector<int>(5));
    int row=0, col=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> matrix[i][j];
            if(matrix[i][j]==1){
                col=j;
                row=i;
                break;
            }
        }
    }

    int ans=0;
    ans += abs(row-2);
    ans += abs(col-2);
    cout << ans << endl;
}
