class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        if(m == 1 && n == 1) return 0;
        vector<vector<int>> visited(n, vector<int>(m, -1));
        
        vector<int> mov{0,1,0,-1,0};
        queue<tuple<int,int,int, int>> q;
        q.push({0,0,k, 0});
        visited[0][0] = k;
        
        while(!q.empty()) {
            auto [x, y, r, p] = q.front();
            q.pop();
            
            if(x == n - 1 && y == m - 1) return p;
            
            for(int i = 0; i < 4; ++i) {
                int tx = x + mov[i];
                int ty = y + mov[i + 1];
                if(tx < 0 || tx >= n) continue;
                if(ty < 0 || ty >= m) continue;
                //if(visited[tx][ty] != -1) continue;
                if(r <= visited[tx][ty]) continue;
                if(grid[tx][ty] == 1) {
                    if(r == 0) continue;
                    q.push({tx,ty,r - 1, p + 1});
                    visited[tx][ty] = r - 1;
                } else {
                    q.push({tx,ty,r, p + 1});
                    visited[tx][ty] = r;
                }
            }
        }
        
        return -1;
    }
};