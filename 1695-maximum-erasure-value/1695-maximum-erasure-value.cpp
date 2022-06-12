class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        int ans = 0;
        int s = 0;
        vector<bool> in(10001, false);
        while(i < n) {
            if(in[nums[i]]) {
                while(j < i && in[nums[i]]) {
                    s -= nums[j];
                   in[nums[j]] = false;
                    ++j;
                }
            } else {
                s += nums[i];
                in[nums[i]] = true;
                ++i;
            }
            ans = max(ans, s);
        }
        
        return ans;
    }
};