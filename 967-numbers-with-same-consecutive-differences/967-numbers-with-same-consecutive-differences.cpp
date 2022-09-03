class Solution {
    set<int> ans;
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i < 10; ++i) {
            dfs(n - 1, k, i, i);
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
    
    void dfs(int n, int k, int current, int last) {
        if(n == 0) {
            ans.insert(current);
            return;
        }
        
        if(last + k < 10) {
            dfs(n - 1, k, current*10 + last + k, last + k);
        }
        if(last - k >= 0) {
            dfs(n - 1, k, current*10 + last - k, last - k);
        }
    }
};