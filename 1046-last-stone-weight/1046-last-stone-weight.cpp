class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for(auto s: stones) pq.push(s);
        
        while(pq.size() > 1) {
            int f = pq.top(); pq.pop();
            int s = pq.top(); pq.pop();
            
            if(s != f) pq.push(abs(f - s));
        }
        
        if(pq.empty()) return 0;
        return pq.top();
    }
};