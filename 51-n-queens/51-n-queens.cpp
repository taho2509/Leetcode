class Solution {
vector<vector<string>> ans;
public:
    vector<vector<string>> solveNQueens(int n) {
        for(int i = 0; i < n; ++i) create({}, {0, i}, n);
        return ans;
    }
    
    void create(vector<pair<int,int>> queens, pair<int,int> last, int n) {
        queens.push_back(last);
        if(queens.size() == n) return build(queens);
        
        for(int i = 0; i < n; ++i) {
            if(canPlaceIt(queens, i)) {
                create(queens, {queens.size(), i}, n);
            }
        }
    }
    
    bool canPlaceIt(vector<pair<int,int>> &queens, int i) {
        int x2 = queens.size(), y2 = i;
        
        for(auto [x1, y1]: queens) {
            if(x1 == x2 || y1 == y2) return false;
            if(y1 - x1 == y2 - x2) return false;
            if(y1 + x1 == y2 + x2) return false;
        }
        
        return true;
    }
    
    void build(vector<pair<int,int>> &queens) {
        int n = queens.size();
        
        string row(n, '.');
        
        vector<string> current(n);
        for(int i = 0; i < n; ++i) current[i] = row;
        
        for(auto [x, y]: queens) current[x][y] = 'Q';
        
        ans.push_back(current);
    }
};