class Solution {
public:
    int minSteps(int n) {        
        vector<int> DP(n + 1, 0);
        DP[0] = 0;
        DP[1] = 0;
        
        for(int i = 2; i <= n; ++i) {
            DP[i] = i;
            for(int j = 2; j < i; ++j) {
                if(i%j == 0) {
                    DP[i] = min(DP[i], (i - j)/j + DP[j] + 1);
                }
            }
        }
        
        return DP[n];
    }
};