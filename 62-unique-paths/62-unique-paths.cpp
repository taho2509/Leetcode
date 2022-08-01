class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> DP(n, vector<int>(m, 0));
        DP[0][0] = 1;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {                
                if(i > 0) DP[i][j] += DP[i - 1][j];
                if(j > 0) DP[i][j] += DP[i][j - 1];
            }
        }
        
        return DP[n - 1][m - 1];
    }
};