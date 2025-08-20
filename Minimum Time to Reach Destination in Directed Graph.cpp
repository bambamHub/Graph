class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {

        vector<vector<array<int,3>>> adj(n);
        for (auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2], it[3]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> dist(n, 1e9);

        dist[0] = 0;
        pq.push({0,0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (node == n-1) return d;
            if (d > dist[node]) continue;

            for (auto &it : adj[node]) {
                int adjNode = it[0], s = it[1], e = it[2];
                if (d > e) continue;  
                int newd = max(d, s) + 1; 
                if(newd < dist[adjNode]){        
                    dist[adjNode] = newd;
                    pq.push({newd,adjNode});
                }
            }
        }
        return -1 ;
    }
};

