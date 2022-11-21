class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        
        int n = maze.size();
        int m = maze[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[entrance[0]][entrance[1]] = true;
        q.push({entrance[0],entrance[1]});
        int count = 0;
        vector<int> mov{1, 0, -1, 0, 1};
        
        while(!q.empty()) {
            int k = q.size();
            
            for(int i = 0; i < k; ++i) {
                auto [x, y] = q.front();
                q.pop();
                
                for(int j = 0; j < 4; ++j) {
                    int tx = x + mov[j];
                    int ty = y + mov[j + 1];
                    
                    if(tx < 0 || tx >= n) continue;
                    if(ty < 0 || ty >= m) continue;
                    if(maze[tx][ty] == '+') continue;
                    if(visited[tx][ty]) continue;
                    
                    if(tx == 0 || ty == 0) return count + 1;
                    if(tx == n - 1 || ty == m - 1) return count + 1;
                    
                    q.push({tx,ty});
                    visited[tx][ty] = true;
                }
            }
            
            ++count;
        }
        
        return -1;
    }
};