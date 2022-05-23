class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> DP(m+1, vector<int>(n+1, 0));
        
        for(string s: strs) {
            int c0 = 0;
            int c1 = 0;
            for(char c: s) {
                if(c == '0') c0++;
                else c1++;
            }
            for(int i = m; i >= c0; --i) {
                for(int j = n; j >= c1; --j) {
                    DP[i][j] = max(DP[i][j], DP[i - c0][j - c1] + 1);
                }
            }
        }
        
        return DP[m][n];
    }
};