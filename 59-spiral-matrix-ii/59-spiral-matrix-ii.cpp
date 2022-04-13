class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n,0));
        int counter = 1;
        vector<int> x = {0,1,0,-1};
        vector<int> y = {1,0,-1,0};
        int currentDir = 0;
        pair<int,int> current = {0,0};
        int nextx, nexty;
        
        while(true) {
            matrix[current.first][current.second] = counter;
            if(counter == n*n) break;
            
            counter++;
            
            nextx = current.first + x[currentDir % 4];
            nexty = current.second + y[currentDir % 4];
            
            // change of dir
            if(nextx >= n || nextx < 0 || nexty >= n || nexty < 0 || matrix[nextx][nexty] != 0) {
                currentDir++;
                nextx = current.first + x[currentDir % 4];
                nexty = current.second + y[currentDir % 4];
            }
            
            current = {nextx, nexty};
        }
        
        return matrix;
    }
};