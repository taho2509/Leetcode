class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<bool> play(100001, false);
        vector<int> looses(100001, 0);
        
        for(auto v: matches) {
            play[v[0]] = true;
            play[v[1]] = true;
            
            looses[v[1]]++;
        }
        
        vector<vector<int>> ans(2);
        
        for(int i = 1; i < 100001; ++i) {
            if(play[i]) {
                if(looses[i] == 0) ans[0].push_back(i);
                if(looses[i] == 1) ans[1].push_back(i);
            }
        }
        
        return ans;
    }
};