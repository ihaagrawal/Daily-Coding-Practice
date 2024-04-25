// 130. Surrounded Regions (MEDIUM)
// https://leetcode.com/problems/surrounded-regions/description/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && (i==0 || i==m-1 || j==0 || j==n-1)){
                    q.push({i, j});
                    board[i][j]='P';
                }
            }
        }

        int row[]={1,0,-1,0};
        int col[]={0,1,0,-1};

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            bool found=true;

            for(int k=0;k<4;k++){
                int new_row=i+row[k];
                int new_col=j+col[k];

                if(new_row>=0 && new_row<m && new_col>=0 && new_col<n){
                    if(board[new_row][new_col]=='O'){
                        q.push({new_row, new_col});
                        board[new_row][new_col]='P';
                    }
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='P') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }

    }
};
