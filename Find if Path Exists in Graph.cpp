class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination){

        unordered_map<int, vector<int>> adj;

        for(auto it: edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        queue<int> q;
        q.push(source);
        vis[source] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        for(int i=0; i<n; i++){
            if(vis[destination]==0){
                return false;
            }
        }
        return true;
    }
};
