class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        
        int advanced = 0;
        int bricksUsed = 0;
        while(advanced < n - 1 && bricksUsed <= bricks) {
            if(heights[advanced + 1] <= heights[advanced]){
                advanced++;
                continue;
            }

            pq.push(-(heights[advanced + 1] - heights[advanced]));
            if(pq.size() > ladders) {
                bricksUsed += -pq.top();
                pq.pop();
            }
            advanced++;
        }
        
        if(bricksUsed > bricks) advanced--;
        
        return advanced;
    }
};