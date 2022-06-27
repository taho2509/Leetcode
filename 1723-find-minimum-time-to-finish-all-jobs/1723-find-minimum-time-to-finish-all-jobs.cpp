class Solution {
    int ans = INT_MAX;
    unordered_set<string> used;
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> has(k, 0);
        string hass(k*8, '*');
        
        sort(jobs.rbegin(), jobs.rend());
        dfs(0, jobs, k, has, hass, 0);
        
        return ans;
    }
    
    void dfs(int i, vector<int>& jobs, int k, vector<int> &has, string &hass, int ma) {
        int n = jobs.size();
        
        if(i >= n) {
            ans = min(ans, ma);
            return;
        }
        
        if(ma >= ans) return;
        if(used.find(hass) != used.end()) return;
        
        for(int j = 0; j < k; ++j) {
            if (j > 0 && has[j] == has[j - 1]) continue;
            has[j] += jobs[i];
            int t = has[j];
            for(int k = 0; k < 8; ++k) {
                if(t > 0) {
                    hass[8*j + k] = t%10;
                    t /= 10;
                } else {
                    hass[8*j + k] = '*';
                }
            }

            dfs(i + 1, jobs, k, has, hass, max(ma, has[j]));

            has[j] -= jobs[i];
            t = has[j];
            for(int k = 0; k < 8; ++k) {
                if(t > 0) {
                    hass[8*j + k] = t%10;
                    t /= 10;
                } else {
                    hass[8*j + k] = '*';
                }
            }
        }
        
        used.insert(hass);
    }
};