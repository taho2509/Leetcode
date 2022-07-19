class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> startRow(1,1);
        
        vector<vector<int>> pascal(numRows, startRow);
        
        for(int i = 2; i <= numRows; ++i) {
            for(int j = 1; j < i - 1; ++j) {
                pascal[i - 1].push_back(pascal[i - 2][j - 1] + pascal[i - 2][j]);
            }
            pascal[i - 1].push_back(1);
        }

        return pascal;
    }
};