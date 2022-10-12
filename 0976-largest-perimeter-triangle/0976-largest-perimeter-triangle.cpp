class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());

        int n = nums.size();
        for(int i = 2; i < n; ++i) {
            if(nums[i - 2] + nums[i - 1] <= nums[i]) continue;
            if(nums[i - 2] + nums[i] <= nums[i - 1]) continue;
            if(nums[i] + nums[i - 1] <= nums[i - 2]) continue;
            
            return nums[i - 2] + nums[i - 1] + nums[i];
        }
        
        return 0;
    }
};