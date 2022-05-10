class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> current;
        dfs(k, n, 0, current, 1);
        return ans;
    }
    
    void dfs(int k, int n, int sum, vector<int> &curr, int i) {
        if(k == 0) {
            if(sum == n) {
                ans.push_back(curr);
            }
            return;
        }
        if(sum > n) return;
        if(i > 9) return;
        
        for(int j = i; j <= 9; ++j) {
            curr.push_back(j);
            dfs(k - 1, n, sum + j, curr, j + 1);
            curr.pop_back();
        }
    }
};