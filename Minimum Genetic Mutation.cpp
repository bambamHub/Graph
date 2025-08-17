class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank){

        unordered_set<string> st(bank.begin(), bank.end());
        st.erase(startGene);

        queue<pair<string, int>> q;
        q.push({startGene, 0});
        vector<char> choices = {'A', 'C', 'G', 'T'};

        while(!q.empty()){
            string gene = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(gene == endGene) return steps;

            for(int i=0; i<gene.size(); i++){
                char original = gene[i];
                for(char ch : choices){
                    gene[i] = ch;
                    if(st.find(gene)!=st.end()){
                        st.erase(gene);
                        q.push({gene, steps+1});
                    }
                }
                gene[i] = original;
            }
        }
        return -1;
        
    }
};
