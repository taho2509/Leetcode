class Solution {
    int best;
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> childs(n);
        
        for(int i = 1; i < n; ++i) {
            childs[parent[i]].push_back(i);
        }
        
        best = 0;
        
        dfs(childs, 0, s);
        
        return best;
    }
    
    int dfs(vector<vector<int>> &childs, int root, string &s) {        
        priority_queue<int> pq;
        pq.push(0);
        pq.push(0);

        for(int child: childs[root]) {            
            int temp = dfs(childs, child, s);
            if(s[child] == s[root]) continue;
            
            pq.push(temp);
        }

        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        
        best = max(best, a + b + 1);
        return a + 1;
    }
};