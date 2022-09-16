class Solution {
    vector<vector<int>> dp;
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        dp = vector<vector<int>> (multipliers.size(),vector<int>(multipliers.size(),INT_MIN));
        
        return dfs(0, 0, nums.size()-1, nums, multipliers);
    }
    
    int dfs(int idx, int st, int end, vector<int>& nums, vector<int>& multipliers){
        if(idx == multipliers.size()) return 0;
        
        if(dp[idx][st] != INT_MIN) return dp[idx][st];
        
        int ans = INT_MIN;
        
        ans= max(multipliers[idx] * nums[st] + dfs(idx + 1, st + 1, end, nums, multipliers),
                 multipliers[idx] * nums[end] + dfs(idx + 1, st, end - 1, nums, multipliers));
        
        return dp[idx][st] = ans;
    }
};