class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> best(n + 1, 0);
        best[0] = cost[0];
        best[1] = cost[1];
        
        for(int i = 2; i < n; ++i) {
            best[i] = cost[i] + min(best[i - 1],best[i - 2]);
        }
        
        return min(best[n - 1],best[n - 2]);
    }
};