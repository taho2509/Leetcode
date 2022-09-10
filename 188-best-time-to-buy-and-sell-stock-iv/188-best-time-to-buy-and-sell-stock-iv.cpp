#define big 10000
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> DP(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        
        for(int i = 0; i <= k; ++i) {
            DP[0][i][1] = -big;
        }
        
        for(int i = 0; i < n; ++i) {
            for(int j = k; j > 0; --j) {
                DP[i + 1][j][0] = max(DP[i][j][0], DP[i][j][1] + prices[i]);
                DP[i + 1][j][1] = max(DP[i][j][1], DP[i][j - 1][0] - prices[i]);
            }
        }
        
        return DP[n][k][0];
    }
};