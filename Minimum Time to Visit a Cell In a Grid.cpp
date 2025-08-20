class Solution {
public:
    int minimumTime(vector<vector<int>>& grid){

        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][1]>1 && grid[1][0]>1){
            return -1;
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        pq.push({0,{0, 0}});

        vector<vector<int>> res(n, vector<int>(m, 1e9));
        res[0][0] = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));
 
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r==n-1 && c==m-1) return time;

            if(vis[r][c]==1) continue;

            vis[r][c] = 1;
            for(int i=0; i<4; i++){
                int newr = r + dr[i];
                int newc = c + dc[i];

                if(newr>=0 && newc>=0 && newr<n && newc<m){
                    if(time + 1 >= grid[newr][newc]){
                        pq.push({time+1, {newr, newc}});
                        res[newr][newc] = time + 1;
                    }
                    else if((grid[newr][newc] - time)%2==0){
                        pq.push({grid[newr][newc]+1, {newr, newc}});
                        res[newr][newc] = grid[newr][newc]+1;
                    }
                    else{
                        pq.push({grid[newr][newc], {newr, newc}});
                        res[newr][newc] = grid[newr][newc];
                    }
                }
            }
        }
        return -1;
        
    }
};
