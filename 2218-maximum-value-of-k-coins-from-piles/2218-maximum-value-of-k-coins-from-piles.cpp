#define big 300000000
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        
        vector<vector<int>> DP(k + 1, vector<int>(2,0));
        
        for(int i = n - 1; i >= 0; --i) {
            for(int t = 1; t <= k; ++t) {
                int accum = 0;
                for(int j = 0; j < piles[i].size() && (j < k || j + 1 < t); ++j) {
                    accum += piles[i][j];

                    if(j < k) DP[j + 1][i%2] = max(max(DP[j + 1][(i+1)%2],DP[j + 1][i%2]), accum);

                    if(j + 1 < t) DP[t][i%2] = max(max(DP[t][(i+1)%2],DP[t][i%2]), accum + DP[t - (j + 1)][(i+1)%2]);
                }
            }
        } 
        
        return max(DP[k][0],DP[k][1]);
    }
    

};