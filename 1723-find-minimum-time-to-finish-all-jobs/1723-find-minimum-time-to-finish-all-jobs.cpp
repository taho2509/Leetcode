class Solution {
    int ans = INT_MAX;
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> has(k, 0);
        
        sort(jobs.rbegin(), jobs.rend());
        dfs(0, jobs, k, has, 0);
        
        return ans;
    }
    
    void dfs(int i, vector<int>& jobs, int k, vector<int> &has, int ma) {
        int n = jobs.size();
        
        if(i >= n) {
            ans = min(ans, ma);
            return;
        }
        
        if(ma >= ans) return;
        
        for(int j = 0; j < k; ++j) {
            if (j > 0 && has[j] == has[j - 1]) continue;
            has[j] += jobs[i];

            dfs(i + 1, jobs, k, has, max(ma, has[j]));

            has[j] -= jobs[i];
        }
    }
};