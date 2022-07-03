class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> DP(n, {1,1});
        
        int m = 1;
        
        for(int i = 1; i < n; ++i) {
            for(int j = i - 1; j >= 0; --j) {
                if(nums[i] < nums[j]) {
                    DP[i].second = max(DP[i].second, DP[j].first + 1);
                    m = max(m, DP[i].second);
                } else if(nums[i] > nums[j]) {
                    DP[i].first = max(DP[i].first, DP[j].second + 1);
                    m = max(m, DP[i].first);
                }
            }
        }
        
        return m;
    }
};