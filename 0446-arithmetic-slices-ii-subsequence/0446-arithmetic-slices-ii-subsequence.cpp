class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long, vector<int>> m;
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int i = 0; i < n; ++i) m[nums[i]].push_back(i);
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                long target = 2 * (long)nums[j] - nums[i];
                if(m.count(target)) {
                    for(int k : m[target]) {
                        if(k < j) dp[i][j] += (dp[j][k] + 1);
                    }
                }
                ans += dp[i][j];
            }
        }
        
        return ans;
    }
};