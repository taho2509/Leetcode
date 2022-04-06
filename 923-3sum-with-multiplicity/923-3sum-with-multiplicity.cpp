class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; ++i) {            
            int j = i + 1, k = n - 1;
            while(j < k) {
                if(nums[i] + nums[j] + nums[k] == target) {
                    if(nums[j] == nums[k]) {
                        ans += ((k - j)*(k - j + 1))/2;
                        ans %= 1000000007;
                        break;
                    }
                    int left = 1, right = 1;
                    while(j + 1 < k && nums[j+1] == nums[j]) {
                        ++left;
                        ++j;
                    }
                    while(j + 1 < k && nums[k - 1] == nums[k]) {
                        ++right;
                        --k;
                    }
                    ans += left*right;
                    ans %= 1000000007;
                    ++j; --k;
                } else if(nums[i] + nums[j] + nums[k] > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        
        return ans;
    }
};