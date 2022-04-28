class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int start = 0, end = 999999, m;
        while(start < end) {
            m = (start + end)/2;
            if(canTraverse(heights, m)) {
                end = m;
            } else {
                start = m + 1;
            }
        }
        
        return start;
    }
    
    bool canTraverse(vector<vector<int>> &heights, int k) {
        int n = heights.size();
        int m = heights[0].size();
        
        if(m == 1 && n == 1) return true;
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[0][0] = true;
        queue<pair<int,int>> q;
        q.push({0,0});
        
        vector<int> mov{1,0,-1,0,1};
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            for(int i = 0; i < 4; ++i) {
                int tx = p.first + mov[i];
                int ty = p.second + mov[i + 1];
                
                if(tx < 0) continue;
                if(tx >= n) continue;
                if(ty < 0) continue;
                if(ty >= m) continue;
                
                if(visited[tx][ty]) continue;
                
                if(abs(heights[tx][ty] - heights[p.first][p.second]) <= k) {
                    if((tx == (n - 1)) && (ty == (m - 1))) return true;
                    q.push({tx,ty});
                    visited[tx][ty] = true;
                }
            }
        }
        
        return false;
    }
};