class Solution {
    vector<int> root;
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        root = vector<int>(n);
        
        for(int i = 0; i < n; ++i) root[i] = i;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    join(i,j);
            }
        }

        int groups = 0;
        for(int i=0;i<n;i++) 
            if(root[i] == i) ++groups;

        return n - groups;
    }
    
    int getRoot(int i) {
        if(root[i] != i) root[i] = getRoot(root[i]);
        
        return root[i];
    }
    
    void join(int i, int j){
        root[getRoot(i)] = getRoot(j); 
    }    
};