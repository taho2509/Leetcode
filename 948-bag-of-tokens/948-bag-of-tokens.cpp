class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int i = 1, j = n - 1;
        
        if(n == 0) return 0;
        if(tokens[0] > power) return 0;
        
        int score = 1;
        int ans = 1;
        power -= tokens[0];
        
        while(i <= j) {
            if(tokens[i] <= power) {
                power -= tokens[i++];
                ++score;
            } else {
                if(score == 0) break;
                power += tokens[j--];
                --score;
            }
            ans = max(ans, score);
        }
        
        return ans;
    }
};