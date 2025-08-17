class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance){

        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int, pair<int,int>>> q;
        q.push({0, {entrance[0], entrance[1]}});

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[entrance[0]][entrance[1]] = 1;
        
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};

        while(!q.empty()){
            int steps = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if((row==0 || col==0 || row == n-1 || col==m-1) && !(row==entrance[0] && col ==entrance[1])){
                return steps;
            }

            for(int i=0; i<4; i++){
                int newr = row + dr[i];
                int newc = col + dc[i];
                if(newr>=0 && newc>=0 && newr<n && newc<m && maze[newr][newc]=='.' && vis[newr][newc]==0){
                    q.push({steps+1, {newr, newc}});
                    vis[newr][newc] = 1;
                }
            }

        }
        return -1;
    }
};
