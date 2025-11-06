class Solution {
public:
    int n;
    int m;
    void dfs(int row, int col, int &fish, vector<vector<int>>& vis, vector<vector<int>>& grid){
        vis[row][col] = 1;
        fish += grid[row][col];
 
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};

        for(int i=0; i<4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]>0){
                dfs(nrow, ncol, fish, vis, grid);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int maxFish = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]>0){
                    int fish = 0;
                    dfs(i, j, fish, vis, grid);
                    maxFish = max(maxFish, fish);
                }
            }
        }
        return maxFish;
    }
};
