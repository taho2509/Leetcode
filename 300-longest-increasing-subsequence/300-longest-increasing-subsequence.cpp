class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(1, nums[0]);
        int n = nums.size();
        for(int i = 1; i < n; ++i) {
            if(nums[i] > lis.back()) {
                lis.push_back(nums[i]);
            } else {
                int j = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[j] = nums[i];
            }
        }
        
        return lis.size();
    }
};