class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health){
        
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        pq.push({grid[0][0], {0, 0}});

        vector<vector<int>> dis(n, vector<int>(m, 1e9));

        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r==n-1 && c==m-1 && dis[n-1][m-1] < health){
                return true;
            }

            for(int i=0; i<4; i++){
                int newr = r + dr[i];
                int newc = c + dc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    if(d + grid[newr][newc] < dis[newr][newc]){
                        dis[newr][newc] = d + grid[newr][newc];
                        pq.push({dis[newr][newc], { newr, newc}});
                    }
                }
            }
        }
        return false;
    }
};
