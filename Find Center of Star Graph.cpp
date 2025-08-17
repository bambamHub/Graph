class Solution {
public:
    int findCenter(vector<vector<int>>& edges){

        unordered_map<int, int> mp;

        for(auto it: edges){
            int u = it[0];
            int v = it[1];

            mp[u]++;
            mp[v]++;
        }

        for(auto it: mp){
            if(it.second==mp.size()-1){
                return it.first;
            }
        }
        return -1;

        
        
    }
};
