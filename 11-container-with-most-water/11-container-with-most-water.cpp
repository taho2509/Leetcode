class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int area = min(height[0], height[n - 1]) * (n - 1);
        int left = height[0] < height[n - 1];
        int i = 0, j = n - 1, k;
        
        while(i < j) {
            if(left) {
                k = i + 1;
                while(height[k] <= height[i] && (k < j)) k++;
                i = k;
            } else {
                k = j - 1;
                while(height[k] <= height[j] && (k > i)) k--;
                j = k;
            }
            if(i == j) break;
            area = max(area, min(height[j], height[i]) * (j - i));
            left = height[i] < height[j];
        }

        return area;
    }
};