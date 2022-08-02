class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        
        for (int r = 0; r < min(m, k); ++r)
            pq.push({matrix[r][0], r, 0});

        for (int i = 1; i <= k; ++i) {
            auto top = pq.top();
            pq.pop();

            int r = top[1], c = top[2];
            ans = top[0];
            
            if (c + 1 < n) pq.push({matrix[r][c + 1], r, c + 1});
        }
        return ans;
    }
};