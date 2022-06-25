class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<unordered_map<int,int>> adj(n);
        
        vector<int> grades(n);
        
        for(auto e: edges) {
            grades[e[0] - 1]++;
            grades[e[1] - 1]++;
            
            if(e[0] < e[1]) {
                adj[e[0] - 1][e[1] - 1]++;
            } else {
                adj[e[1] - 1][e[0] - 1]++;
            }
        }
        
        vector<pair<int,int>> edgesm;
        
        for(int v = 0; v < adj.size(); ++v) {
            for(auto [u, m]: adj[v]) {
                int s = grades[v] + grades[u];
                edgesm.push_back({s,s - m});
            }
        }
        
        vector<int> sortgrades(grades.begin(), grades.end());
        sort(sortgrades.begin(), sortgrades.end());
        
        vector<int> ans(queries.size(), 0);
        for(int q = 0; q < queries.size(); ++q) {
            int kk = queries[q];
            for(int i = 0; i < n; ++i) {
                int c = sortgrades[i];
                auto it = lower_bound(sortgrades.begin() + i + 1, sortgrades.end(), kk - c + 1);
                ans[q] += sortgrades.end() - it;
            }
            
            for(auto [s, m]: edgesm) {
                if((s > kk) && (m <= kk)) {
                    ans[q]--;
                }
            }
        }
        
        return ans;
    }
};