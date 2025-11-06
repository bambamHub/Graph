class Solution {
public:
    int n; 
    int m;
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& board){
        vis[row][col] = 1;

        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};

        for(int i=0; i<4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='X'){
                dfs(nrow, ncol, vis, board);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {

        n = board.size();
        m = board[0].size();
        
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j]=='X'){
                    cnt++;
                    dfs(i, j, vis, board);
                }
            }
        }
        return cnt;
    }
};
