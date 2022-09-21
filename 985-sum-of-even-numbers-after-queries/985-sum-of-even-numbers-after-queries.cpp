class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int s = 0;
        for(int i: nums) {
            if(i % 2 == 0) s += i;
        }
        
        vector<int> ans;
        
        for(auto q: queries) {
            if(nums[q[1]] %2 == 0) {
                s -= nums[q[1]];
            }
            
            nums[q[1]] += q[0];
            
            if(nums[q[1]] %2 == 0) {
                s += nums[q[1]];
            }
            
            ans.push_back(s);
        }
        
        return ans;
    }
};