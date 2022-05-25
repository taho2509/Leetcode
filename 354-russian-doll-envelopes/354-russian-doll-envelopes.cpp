class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(), e.end(), [](vector<int>& a, vector<int>& b) 
             -> bool {return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];});
        
        vector<int> dp;
        for (auto& env : e) {
            int height = env[1];
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            if (left == dp.size()) dp.push_back(height);
            dp[left] = height;
        }
        return dp.size();
    }
};