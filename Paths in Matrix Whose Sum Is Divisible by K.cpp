class Solution {
public:
    int n;
    int m;
    int mod = 1e9 + 7;
    int solve(int i, int j, int sum, int k, vector<vector<int>>& grid,  vector<vector<vector<int>>> &dp){

        if(i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1){
            sum += grid[i][j];
            if(sum%k==0) return 1;
            return 0;
        }
        if(dp[i][j][sum%k]!=-1){
            return dp[i][j][sum%k];
        }
        
        int down = solve(i+1, j, sum + grid[i][j], k, grid, dp);
        int right = solve(i, j+1, sum + grid[i][j], k, grid, dp);

        return dp[i][j][sum%k] =  (down%mod + right%mod)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {

        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(51, -1)));
        return solve(0, 0, 0, k, grid, dp);
    }
};
