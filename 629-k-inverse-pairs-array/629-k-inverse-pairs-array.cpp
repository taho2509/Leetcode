#define mod 1000000007
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> DP(n + 1, vector<int>(k + 1, 0));
        for(int i = 0; i <= n; ++i) DP[i][0] = 1;
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= k; ++j) {
                DP[i][j] = DP[i][j - 1] + DP[i - 1][j];
                DP[i][j] %= mod;
                if(j - i >= 0) {
                    DP[i][j] = (DP[i][j] + mod - DP[i - 1][j - i])%mod;
                }
            }
        }
        
        return DP[n][k];
    }
};