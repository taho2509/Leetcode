class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        sort(flowers.begin(), flowers.end());
        
        flowers[0] = min(flowers[0], target);
        
        int n = flowers.size();
        vector<long long> cost(n, 0);
        
        for(int i = 1; i < n; ++i) {
            flowers[i] = min(flowers[i], target);
            cost[i] = cost[i - 1];
            cost[i] += (flowers[i] - (long long)flowers[i - 1])*i;
        }
        
        if(flowers[0] == target) return (long long)n*full;
        
        int j = n - 1;
        while(j >= 0 && flowers[j] == target) --j;
        
        if(newFlowers >= cost[n - 1] + (target - flowers[n - 1]) * n)
            return max((long long)n*full, (long long)full*(n - 1) + (long long)partial*(target-1));
        
        long long ans = 0;
        int idx;
        long long bar;
        while(newFlowers >= 0) {
            auto it = lower_bound(cost.begin(), cost.begin() + j, newFlowers);
            idx = it - cost.begin();

            if(cost[idx] > newFlowers) --idx;
            
            bar = flowers[idx] + (newFlowers - cost[idx])/(idx + 1);
            
            ans = max(ans, (long long)full*(n - j - 1) + partial*(bar));
            
            newFlowers -= (target - flowers[j]);
            --j;
        }
        
        return ans;
    }
};