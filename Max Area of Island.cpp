      class Solution {
public:
    int n;
    int m;
    void dfs(int row, int col, int &area, vector<vector<int>>& vis, vector<vector<int>>& grid){

        vis[row][col] = 1;
        area++;

        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};

        for(int i=0; i<4; i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow, ncol, area, vis, grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();
        
        int maxArea = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int area = 0;
                    dfs(i, j, area, vis, grid);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};
