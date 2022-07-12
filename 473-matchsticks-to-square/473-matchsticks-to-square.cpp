class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        long perimeter = 0;
        for(int a: matchsticks) perimeter += a;
        
        if(perimeter % 4 != 0) return false;
        
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        int side = perimeter/4;
        
        vector<int> sums(4, 0);
        return construct(matchsticks, 0, sums, side);
    }
    
    bool construct(vector<int>& sticks, int t, vector<int> &sums, int side) {
        if(t == sticks.size()) {
            for(int s: sums) if(s != side) return false;
            return true;
        }
        
        for(int i = 0; i < 4; ++i) {
            if(sums[i] + sticks[t] > side) continue;
            
            sums[i] += sticks[t];
            bool ans = construct(sticks, t + 1, sums, side);
            if(ans) return true;
            sums[i] -= sticks[t];
        }
        
        return false;
    }
};