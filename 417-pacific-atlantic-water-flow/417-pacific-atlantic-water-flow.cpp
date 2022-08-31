struct cell {
    int x;
    int y;
    int h;
};

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return {};
        int m = matrix[0].size();
        if(m == 0) return {};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<bool>> visited2(n, vector<bool>(m, false));
        
        vector<int> x{0,1,0,-1};
        vector<int> y{1,0,-1,0};
        queue<cell> pacific;
        for(int i = 0; i < n; ++i) {
            pacific.push({i, -1, 0});
        }
        for(int i = 1; i < m; ++i) {
            pacific.push({-1, i, 0});
        }
        
        while(!pacific.empty()) {
            auto current = pacific.front();
            pacific.pop();
            
            for(int i = 0; i < 4; ++i) {
                int nextx = current.x + x[i];
                int nexty = current.y + y[i];
                
                if(nextx < 0) continue;
                if(nexty < 0) continue;
                if(nextx >= n) continue;
                if(nexty >= m) continue;
                
                if(visited[nextx][nexty]) continue;
                if(matrix[nextx][nexty] >= current.h) {
                    visited[nextx][nexty] = true;
                    pacific.push({nextx, nexty, matrix[nextx][nexty]});
                }
            }
        }
        
        queue<cell> atlantic;
        for(int i = 0; i < n; ++i) {
            atlantic.push({i, m, 0});
        }
        for(int i = 0; i < m - 1; ++i) {
            atlantic.push({n, i, 0});
        }
        
        vector<vector<int>> ans;
        
        while(!atlantic.empty()) {
            auto current = atlantic.front();
            atlantic.pop();
            
            for(int i = 0; i < 4; ++i) {
                int nextx = current.x + x[i];
                int nexty = current.y + y[i];
                
                if(nextx < 0) continue;
                if(nexty < 0) continue;
                if(nextx >= n) continue;
                if(nexty >= m) continue;
                
                
                if(visited2[nextx][nexty]) continue;
                if(matrix[nextx][nexty] >= current.h) {
                    if(visited[nextx][nexty]) {
                        ans.push_back({nextx, nexty});
                    }
                    visited2[nextx][nexty] = true;
                    atlantic.push({nextx, nexty, matrix[nextx][nexty]});
                }
            }
        }
        
        return ans;        
    }
};