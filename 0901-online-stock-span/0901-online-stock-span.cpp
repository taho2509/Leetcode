class StockSpanner {
    vector<int> prices;
    vector<int> nexts;
public:
    StockSpanner() {
        prices.push_back(1000000);
        nexts.push_back(1);
    }
    
    int next(int price) {
        int i = nexts.size() - 1;
        
        prices.push_back(price);
        nexts.push_back(1);
        
        
        int ans = 1;

        while(i >= 0) {
            if(price >= prices[i]) {
                ans += nexts[i];
                i -= nexts[i];
                
            } else break;
        }
        
        nexts.pop_back();
        nexts.push_back(ans);
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */