class Solution {
public:
    void dfs(int node, int parent, unordered_map<int, vector<int>> &adj, vector<int> &ans,  vector<int> &count, string &labels){

        char mylabel = labels[node];

        int count_before = count[mylabel - 'a'];
        count[mylabel - 'a'] += 1;

        for(auto it : adj[node]){
            if(it == parent) continue;
            dfs(it, node, adj, ans, count, labels);
        }

        int count_after = count[mylabel - 'a'];
        ans[node] = count_after - count_before;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels){

        unordered_map<int, vector<int>> adj;

        for(auto it: edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans(n, 0);
        vector<int> count(26, 0);
        dfs(0, -1, adj, ans, count, labels);
        return ans;
        
    }
};
