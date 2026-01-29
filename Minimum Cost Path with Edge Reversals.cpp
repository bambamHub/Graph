class Solution {
public:
    typedef pair<int, int> P;
    int minCost(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<P>> adj;

        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, 2*wt});
        }
        
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> dist(n, INT_MAX);

        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node==n-1){
                return dist[n-1];
            }

            for(auto &p : adj[node]){
                int adjNode = p.first;
                int edWt = p.second;
                if(dis + edWt < dist[adjNode]){
                    dist[adjNode] = dis + edWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return -1;
    }
};
