class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        
        int x = 0;
        
        for(int i = 0; i < coins.size(); ++i) {
            if(x >= coins[i] - 1) {
                x += coins[i];
            } else {
                return x + 1;
            }
        }
        
        return x + 1;
    }
};