class Solution {
public:
    int numSquares(int n) {
        vector<int> DP(n + 1, INT_MAX);
        DP[0] = 0;
        
        for(int i = 1; i*i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(j - i*i >= 0) DP[j] = min(DP[j], DP[j - i*i] + 1);
            }
        }
        
        return DP[n];
    }
};