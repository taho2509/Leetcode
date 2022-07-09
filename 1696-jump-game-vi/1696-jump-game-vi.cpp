class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> DP(n, INT_MIN);
        DP[0] = nums[0];
        
        priority_queue<int> pq;
        priority_queue<int> deleted;
        
        pq.push(DP[0]);
        
        // but this is O(n^2)
        for(int i = 1; i < n; ++i) {
            int j = i - 1;
            DP[i] = nums[i] + pq.top();
            pq.push(DP[i]);
            if(i - k >= 0) {
                deleted.push(DP[i - k]);
                while(!pq.empty() && !deleted.empty() && (pq.top() == deleted.top())) {
                    pq.pop();
                    deleted.pop();
                }
            }
        }
        
        return DP[n - 1];
    }
};