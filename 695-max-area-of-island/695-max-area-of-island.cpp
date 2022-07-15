class Solution {
    vector<int> mov{0,1,0,-1,0};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        
        return ans;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        
        grid[i][j] = 0;
        int current = 1;
        
        for(int k = 0; k < 4; ++k) {
            int ti = i + mov[k], tj = j + mov[k + 1];
            if(ti < 0 || ti >= n) continue;
            if(tj < 0 || tj >= m) continue;
            if(grid[ti][tj] == 0) continue;
            current += dfs(grid, ti, tj);
        }
        return current;
    }
};