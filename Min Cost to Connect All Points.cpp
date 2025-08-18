class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int V = points.size();

        vector<vector<pair<int, int>>> adj(V);

        for(int i=0; i<V; i++){
            for(int j=i+1; j<V; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x1-x2) + abs(y1-y2);

                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<int> vis(V, 0);

        int minCost = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;

            if(vis[node]==1) continue;

            vis[node] = 1;
            minCost += wt;

            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeWt  = it.second;
                if(!vis[adjNode]){
                    pq.push({edgeWt,adjNode});

                }
            }
        }
        return minCost;
    }
};
