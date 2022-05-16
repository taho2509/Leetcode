class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
        if(n == 1) return 1;
        
        vector<vector<int>> visited(n, vector<int>(n, -1));
        queue<pair<int,int>> q;
        int x[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int y[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

        q.push({0,0});
        visited[0][0] = 1;
        while(!q.empty()) {
            auto c = q.front();
            q.pop();
            
            for(int i = 0; i < 8; ++i) {
                int tx = c.first + x[i];
                int ty = c.second + y[i];
                
                if((tx == n - 1) && (ty == n - 1)) return visited[c.first][c.second] + 1;
                if(tx < 0 || tx >= n) continue;
                if(ty < 0 || ty >= n) continue;
                if(visited[tx][ty] != -1) continue;
                if(grid[tx][ty] != 0) continue;
                
                visited[tx][ty] = visited[c.first][c.second] + 1;
                q.push({tx, ty});
            }
        }
        
        return -1;
    }
};