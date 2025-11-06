class Solution {
public:
    int n;
    int m;
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int &perm){

        vis[row][col] = 1;

        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};

        for(int i=0; i<4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(nrow<0 || nrow>=n || ncol<0 || ncol>=m || grid[nrow][ncol]==0){
                perm++;
            }
            else if(!vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow, ncol, vis, grid, perm);
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid){
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int perm = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    dfs(i, j, vis, grid, perm);
                    return perm;
                }
            }
        }
        return 0;
    }
};
