class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int start = 0, end = m*n - 1;
        
        while(start <= end) {
            int middle = (start + end)/2;
            if(matrix[middle/m][middle%m] == target) return true;
            else if(matrix[middle/m][middle%m] < target){
                start = middle + 1;
            } else {
                end = middle - 1;
            }
        }

        return false;
    }
};