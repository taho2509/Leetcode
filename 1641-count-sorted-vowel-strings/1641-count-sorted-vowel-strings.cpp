class Solution {
    vector<vector<int>> memo;
public:
    int countVowelStrings(int n) {
        memo = vector<vector<int>>(6, vector<int>(55, -1));
        return count(0, n + 1);
    }
    
    int count(int last, int n) {
        if(n == 1){
            return 1;
        }
        if(memo[last][n] != -1) return memo[last][n];
        
        int ans = 0;
        for(int i = last; i < 5; i++) {
            ans += count(i, n - 1);
        }
        return memo[last][n] = ans;
    }
};