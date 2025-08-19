class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k){

        int n = grid.size();
        int m = grid[0].size();

        queue<array<int, 4>> q;
        q.push({0, 0, k, 0});

        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};

        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(k+1, 0)));
        vis[0][0][k] = 1;
        
        while(!q.empty()){
            auto [r, c, rem, d] = q.front();
            q.pop();

            if(r==n-1 && c==m-1) return d;

            for(int i=0; i<4; i++){
                int newr = r + dr[i];
                int newc = c + dc[i];

                if(newr>=0 && newc>=0 && newr<n && newc<m){
                    int nrem = rem - grid[newr][newc];
                    if(nrem>=0 && !vis[newr][newc][nrem]){
                        vis[newr][newc][nrem] = 1;
                        q.push({newr, newc, nrem, d+1});
                    }
                }
            }
        }
        return -1;
    }
};
