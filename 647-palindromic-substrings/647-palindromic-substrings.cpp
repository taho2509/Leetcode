class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> DP(n, vector<bool>(n, false));
        
        int count = 0;
        
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                if(i == j) {
                    count++;
                    DP[i][j] = true;
                } else if(j - 1 == i) {
                    if(s[j] == s[i]) {
                        DP[i][j] = true;
                        count++;
                    } else {
                        DP[i][j] = false;
                    }
                } else {
                    if(s[j] == s[i] && DP[i + 1][j - 1]) {
                        DP[i][j] = true;
                        count++;
                    } else {
                        DP[i][j] = false;
                    }
                }
            }
        }
        
        return count;
    }
};