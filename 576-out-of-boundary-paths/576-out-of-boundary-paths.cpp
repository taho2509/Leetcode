class Solution {
vector<vector<vector<int>>> memo;
public:
    int findPaths(int n, int m, int maxMove, int sr, int sc) {
        memo = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(maxMove + 1, -1)));
        
        return dfs(sr, sc, maxMove, n, m);
    }
    
    int dfs(int i, int j, int moves, int n, int m) {
        if(moves < 0) return 0;
        if(i < 0 || j < 0) return 1;
        if(i >= n || j >= m) return 1;
        
        if(memo[i][j][moves] != -1) return memo[i][j][moves];
        
        vector<int> mov{0,1,0,-1,0};
        long long ans = 0;
        for(int k = 0; k < 4; ++k) {
            ans += dfs(i + mov[k], j + mov[k + 1], moves - 1, n, m);
            ans %= 1000000007;
        }
        
        return memo[i][j][moves] = ans;
    }
};