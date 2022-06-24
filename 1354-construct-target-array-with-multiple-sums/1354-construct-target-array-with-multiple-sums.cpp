class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size() == 1 && target[0] != 1) return false;
        
        sort(target.begin(), target.end(), greater<int>{});
        long long sum = 0;
        priority_queue<long long> q;
        for(int t: target){
            sum+=t;
            q.push(t);
        }
        
        while(q.top() != 1) {
            long long c = q.top();
            q.pop();
            
            sum -= c;
            if(sum < 1) return false;
            
            if(sum >= c) return false;
            if(sum == 1) return true;
            c %= sum;
            if(c == 0) return false;
            q.push(c);
            
            sum += c;
        }
        
        return true;
    }
};