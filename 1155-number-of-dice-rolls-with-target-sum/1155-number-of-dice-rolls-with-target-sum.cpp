#define mod 1000000007
class Solution {
    vector<vector<vector<int>>> memo;
public:
    int numRollsToTarget(int n, int k, int target) {
        memo = vector<vector<vector<int>>>(target + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
        return dfs(n, k, target);
    }
    
    int dfs(int n, int k, int target) {
        if(target < 0) return 0;
        if(target == 0) {
            if(n == 0) return 1;
            return 0;
        }
        if(n <= 0) return 0;
        
        if(memo[target][n][k] != -1) return memo[target][n][k];
        
        long long ans = 0;
        for(int i = 1; i <= k; ++i) {
            ans = (ans + dfs(n - 1, k, target - i))%mod;
        }
        return memo[target][n][k] = ans;
    }
};