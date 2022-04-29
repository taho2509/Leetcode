class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> colors(n, 0);
        
        for(int i = 0; i < n; ++i) {
            if(colors[i] == 0 && !dfs(i, 0, graph, colors)) return false;
        }
        return true;
    }
    
    bool dfs(int u, int parent, vector<vector<int>>& graph, vector<int> &colors) {
        if(colors[u] != 0) {
            if(colors[u] == parent) return false;
            return true;
        }
        
        if(parent == 1) {
            colors[u] = 2;
        } else {
            colors[u] = 1;
        }
        
        for(int v: graph[u]) {
            if(!dfs(v, colors[u], graph, colors)) return false;
        }
        
        return true;
    }
};