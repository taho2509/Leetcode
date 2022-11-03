class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();
        vector<vector<int>> adj(n + 1, vector<int>());
        
        for(int i = 0; i < n; i++) {
            if(getDiff(startGene, bank[i])) {
                adj[0].push_back(i + 1);
                adj[i + 1].push_back(0);
            }
        }
        
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(getDiff(bank[i], bank[j])) {
                    adj[i + 1].push_back(j + 1);
                    adj[j + 1].push_back(i + 1);
                }
            }
        }
        // graph settled
        // now lets make a dijkstra
        
        set<pair<int,int>> remaining;
        remaining.insert({0, 0});
        vector<int> ans = vector<int>(n + 1, INT_MAX);
        ans[0] = 0;
        vector<bool> taked = vector<bool>(n + 1, false);
        
        while(!remaining.empty()) {
            pair<int, int> tmp = *(remaining.begin()); 
            remaining.erase(remaining.begin()); 

            int u = tmp.second;
            
            for(int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (ans[v] > ans[u] + 1) 
                { 
                    if (ans[v] != INT_MAX) 
                        remaining.erase(remaining.find(make_pair(ans[v], v))); 

                    // Updating distance of v 
                    ans[v] = ans[u] + 1; 
                    remaining.insert(make_pair(ans[v], v)); 
                }
            }
        }
        
        for(int i = 0; i < bank.size(); i++) {
            if(bank[i] == endGene) {
                return ans[i + 1] == INT_MAX ? -1 : ans[i + 1];
            }
        }
        
        return -1;
    }
    
    bool getDiff(string &current, string &target) {
        int count = 0;
        for(int i = 0; i < current.size(); i++) {
            if(current[i] != target[i]) count++;
            if(count > 1) return false;
        }
        
        return true;
    }
};