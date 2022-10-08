class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        int diff = INT_MAX;
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1;
            
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if(abs(target - sum) < diff) {
                    diff = abs(target - sum);
                    ans = sum;
                }
                if(sum < target) {//increase sum by moving j ->
                    ++j;
                } else {// decrease sum by moving k <-
                    --k;
                }
            }
        }
        
        return ans;
    }
};