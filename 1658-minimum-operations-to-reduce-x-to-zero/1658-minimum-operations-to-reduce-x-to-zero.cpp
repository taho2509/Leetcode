class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), -x);
        
        if(target == 0) return n;
        if(target < 0) return -1;

        int ans = INT_MIN;
        int accum = 0;
        for(int j = 0, i = 0; j < n; ++j) {
            accum += nums[j];
            while(i <= j && accum >= target) {
                if (accum == target) ans = max(ans, j - i + 1);
                accum -= nums[i++];
            }
        }
        
        return (ans == INT_MIN) ? -1 : n - ans;
    }
};