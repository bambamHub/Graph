---- DFS CODE ---
class Solution {
public:
    void dfs(int node, int target,  vector<vector<int>>& graph, vector<vector<int>> &ans, vector<int> &path){

        path.push_back(node);

        if(node==target){
            ans.push_back(path);
        }
        else{
            for(auto it : graph[node]){
                dfs(it, target, graph, ans, path);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){

        int n = graph.size();

        int src = 0;
        int target = n-1;
        vector<vector<int>> ans;
        vector<int> path;
        dfs(src, target, graph, ans, path);
        return ans;
    }
};


--- BFS CODE --- 
  class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){

        int n = graph.size();

        queue<vector<int>> q;

        int src = 0;
        int target = n-1;

        q.push({src});

        vector<vector<int>> ans;

        while(!q.empty()){
            vector<int> path = q.front();
            q.pop();

            int node = path.back();

            if(node==target){
                ans.push_back(path);
            }
            else{
                for(auto it: graph[node]){
                    vector<int> newPath = path;
                    newPath.push_back(it);
                    q.push({newPath});
                }
            }
        }
        return ans;
    }
};
