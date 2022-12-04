class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> accums(n + 1, 0);
        
        for(int i = 0; i < n; ++i) {
            accums[i + 1] = accums[i] + nums[i];
        }
        
        int ans = -1;
        int md = INT_MAX;
        
        for(int i = 0; i < n; ++i) {
            long long left = accums[i + 1];
            long long right = accums[n] - accums[i + 1];
            
            long long pl = left/(i + 1);
            long long pr = 0;
            if(n - i - 1 > 0) {
                pr = right/(n - i - 1);
            }
            
            if(md > abs(pl - pr)) {
                md = abs(pl - pr);
                ans = i;
            }
        }
        
        return ans;
    }
};