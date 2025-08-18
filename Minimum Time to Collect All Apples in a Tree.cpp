class Solution {
public:
    int dfs(int node, int parent, unordered_map<int, vector<int>> &adj, vector<bool>& hasApple){

        int time = 0;

        for(auto child : adj[node]){
            if(child == parent) continue;

            int childTime = dfs(child, node, adj, hasApple);

            if(childTime > 0 || hasApple[child]){
                time += childTime + 2;

            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple){

        unordered_map<int, vector<int>> adj;
        for(auto it: edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(0, -1, adj, hasApple);
        
    }
};
