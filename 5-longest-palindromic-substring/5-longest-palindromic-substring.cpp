class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> DP(1000, vector<int>(1000, 0));
        
        vector<int> ma{1, 0};
        for(int i = 0; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                if(isPal(s, i, j, DP)) {
                    if(j - i + 1 > ma[0]) {
                        ma = {j - i + 1, i};
                    }
                }
            }
        }
        
        return s.substr(ma[1], ma[0]);
    }
    
    bool isPal(string &s, int i, int j, vector<vector<int>> &DP) {
        if(i == j) return true;
        if(j - i == 1) {
            return s[i] == s[j];
        }
        
        if(DP[i][j] != 0) return DP[i][j] == 1;
        if(s[i] != s[j]) {
            DP[i][j] = 2;
            return false;
        }
        bool ans = isPal(s, i + 1, j - 1, DP);
        DP[i][j] = ans ? 1 : 2;
        return ans;
    }
};