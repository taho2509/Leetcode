class Solution {
vector<vector<int>> cache;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        cache = vector<vector<int>>(n, vector<int>(m, -1));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                ans = max(ans, goforit(matrix, i, j));
            }
        }
        
        return ans;
    }
    
    int goforit(vector<vector<int>>& matrix, int sx, int sy) {
        if(cache[sx][sy] != -1) return cache[sx][sy];

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> mx{0,1,0,-1};
        vector<int> my{1,0,-1,0};
        
        int ans = 1;

        for(int i = 0; i < 4; ++i) {
            int tx = sx + mx[i];
            int ty = sy + my[i];

            if(tx < 0 || tx >= n) continue;
            if(ty < 0 || ty >= m) continue;
            if(matrix[tx][ty] <= matrix[sx][sy]) continue;
            
            ans = max(ans, 1 + goforit(matrix, tx, ty));
        }
        
        cache[sx][sy] = ans;
        return ans;
    }
};