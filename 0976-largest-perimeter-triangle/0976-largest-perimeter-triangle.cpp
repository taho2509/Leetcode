class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());

        int n = nums.size();
        for(int i = 2; i < n; ++i) {
            if(isT(nums[i - 2], nums[i - 1], nums[i])) {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }
        
        return 0;
    }
    
    bool isT(int a, int b, int c) {
        if(a + b <= c) return false;
        if(a + c <= b) return false;
        if(c + b <= a) return false;
        return true;
    }
};