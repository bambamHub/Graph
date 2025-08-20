class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges){

        unordered_map<int, vector<pair<int, int>>> adj;
        unordered_map<int, vector<pair<int, int>>> radj;

        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], 2*it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        vector<int> dist(n, 1e9);
        dist[0] = 0;

        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();

            if(node==n-1) return dis;

            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;

                if(dis + edgeWt < dist[adjNode]){
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }

            for(auto it: radj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;

                if(dis + edgeWt < dist[adjNode]){
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return -1;
        
    }
};
