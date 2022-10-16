#define big 3000000
class Solution {
    vector<vector<int>> dp;
public:
    int minDifficulty(vector<int>& jobs, int d) {
        int n = jobs.size();
        
        if(n < d) return -1;
        dp = vector<vector<int>>(d, vector<int>(n + 10, big));
        
        return dfs(jobs, d - 1, -1, 0, 0);
    }
    
    int dfs(vector<int>& jobs, int d, int m, int i, int l) {
        int n = jobs.size();
        if(i == n) {
            if(d != 0) return big;
            if(m == -1) return big;
            return m;
        }
        
        if(d < 0) return big;
        
        if(dp[d][l] != big) return dp[d][l];
        
        return dp[d][l] = min(
            dfs(jobs, d, max(m, jobs[i]), i + 1, l),
            max(m, jobs[i]) + dfs(jobs, d - 1, -1, i + 1, i)
        );
    }
};