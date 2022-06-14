class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> DP(n + 1, vector<int>(m + 1, 0));
        
        // find longuest common subsequence
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                DP[i + 1][j + 1] = max(DP[i][j + 1], DP[i + 1][j]);
                if(word1[i] == word2[j]) {
                    DP[i + 1][j + 1] = max(1 + DP[i][j], DP[i + 1][j + 1]);
                }
            }
        }
        int cl = DP[n][m];
        
        return n + m - (2*cl);
    }
};