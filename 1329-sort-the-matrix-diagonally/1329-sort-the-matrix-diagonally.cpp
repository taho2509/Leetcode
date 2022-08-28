class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i = 0; i < mat.size(); i++) {
            sort(mat, i, 0);
        }
        
        for(int i = 1; i < mat[0].size(); i++) {
            sort(mat, 0, i);
        }
        
        return mat;
    }
    
    void sort(vector<vector<int>>& mat, int i, int j) {
        int delta = min(mat.size() - i, mat[0].size() - j);
        int si = i, sj = j;
        vector<int> tosort(delta);
        
        for(int a = 0; a < delta; ++a) {
            tosort[a] = mat[si++][sj++];
        }
        
        std::sort(tosort.begin(), tosort.end());
        
        si = i, sj = j;
        for(int a = 0; a < delta; ++a) {
            mat[si++][sj++] = tosort[a];
        }
    }
};