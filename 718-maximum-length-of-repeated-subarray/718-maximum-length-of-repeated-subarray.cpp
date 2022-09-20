class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int DP[n+1][m+1];
        for(int i=0;i<=n;i++) DP[i][0]=0;
        for(int i=0;i<=m;i++) DP[0][i]=0;
        // vector<vector<int>> DP(n + 1, vector<int>(m + 1, 0));
        
        int ans = 0;
        
        for(int i = 1; i <= n; ++i) {
            for(int j = m; j > 0; --j) {
                if(nums1[i - 1] == nums2[j - 1]) {// this is the key
                    DP[i][j] = DP[i - 1][j - 1] + 1;
                } else {
                    DP[i][j] = 0;
                }
                ans = max(ans, DP[i][j]);
            }
        }
        
        return ans;
    }
};