class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ++ans;
                }
            }
        }
        
        return ans;
    }
    
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || i >= n) return;
        if(j < 0 || j >= m) return;
        if(grid[i][j] != '1') return;
        
        grid[i][j] = '0';
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }
};