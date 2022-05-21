class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> change(amount + 1, INT_MAX - 10);
        change[0] = 0;
        for(int i = 1; i <= amount; ++i) {
            for(int j = 0; j < coins.size(); ++j) {
                if(i - coins[j] >= 0) {
                    change[i] = min(change[i], change[i - coins[j]] + 1);
                }
            }
        }
        
        return change[amount] > 10000 ? -1 : change[amount];
    }
};