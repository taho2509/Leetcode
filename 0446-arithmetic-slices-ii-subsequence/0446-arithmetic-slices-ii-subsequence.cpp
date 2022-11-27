class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();        
        vector<unordered_map<long,int>> DP(n);
        
        int ans = 0;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                long diff = (long)nums[i] - (long)nums[j];
                DP[i][diff] += (DP[j][diff] + 1);
                ans += DP[j][diff];
            }
        }
        
        return ans;
    }
};