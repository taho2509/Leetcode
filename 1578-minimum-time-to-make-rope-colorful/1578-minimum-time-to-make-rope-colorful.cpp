class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        char current = s[0];
        int accumulated = 0, maximun = 0;
        bool first = true;
        int totalCost = 0;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == current) {
                if(first) {
                    accumulated = cost[i-1];
                    first = false;
                    maximun = cost[i-1];
                }
                accumulated += cost[i];
                maximun = max(cost[i], maximun);
            } else {
                first = true;
                totalCost += (accumulated - maximun);
                accumulated = 0;
                maximun = 0;
            }
            current = s[i];
        }
        totalCost += (accumulated - maximun);
        return totalCost;
    }
};