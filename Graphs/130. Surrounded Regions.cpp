// 130. Surrounded Regions (MEDIUM)
// https://leetcode.com/problems/surrounded-regions/description/


//Using BFS
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


//Using DFS
class Solution {
public:

    void dfs(int r, int c, vector<vector<int>>& visited, vector<vector<char>>& board){
        visited[r][c]=1;
        int row[]={-1,0,1,0};
        int col[]={0,-1,0,1};
        int m=board.size(), n=board[0].size();

        for(int i=0;i<4;i++){
            int nrow=r+row[i];
            int ncol=c+col[i];

            if(nrow >=0 && nrow <m && ncol >= 0 && ncol < n 
            && !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, visited, board); 
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        
        int i=0,j=0;

        for(j=0;j<n;j++){
            if(visited[0][j]!=1 && board[0][j]=='O'){
                dfs(0, j, visited, board);
            }
            if(visited[m-1][j]!=1 && board[m-1][j]=='O'){
                dfs(m-1, j, visited, board);
            }
        }

        for(i = 0; i < m; i++) {
            if(visited[i][0] != 1 && board[i][0] == 'O'){
                dfs(i, 0, visited, board);
            }
            if(visited[i][n - 1] != 1 && board[i][n - 1] == 'O'){
                dfs(i, n - 1, visited, board);
            }
        }

        for(int i = 0;i<m;i++) {
            for(int j= 0 ;j<n;j++) {
                if(!visited[i][j] && board[i][j] == 'O') 
                    board[i][j] = 'X'; 
            }
        }
    }
};
