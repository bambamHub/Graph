class Solution {
public:
    long res_base_node = 0;
    vector<int> count;
    int N;

    int dfsBase(int curr_node, int prev_node, int curr_depth, unordered_map<int, vector<int>> &adj){
        int tot_count = 1;
        res_base_node += curr_depth;

        for(auto child: adj[curr_node]){
            if(child==prev_node) continue;

            tot_count += dfsBase(child, curr_node, curr_depth+1, adj);
        }

        count[curr_node] = tot_count;
        return tot_count;
    }

    void DFS(int parent_node, int prev_node, unordered_map<int, vector<int>> &adj, vector<int> &res){

        for(auto &child : adj[parent_node]){
            if(child==prev_node) continue;

            res[child] = res[parent_node] - count[child] + (N - count[child]);
            DFS(child, parent_node, adj, res);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges){

        N = n;
        count.resize(n, 0);

        unordered_map<int, vector<int>> adj;

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        res_base_node = 0;
        dfsBase(0, -1, 0, adj);

        vector<int> res(n, 0);
        res[0] = res_base_node;

        DFS(0, -1, adj, res);
        return res;
    }
};
