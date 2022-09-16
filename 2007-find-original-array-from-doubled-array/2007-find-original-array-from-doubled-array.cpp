class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n % 2 == 1) return {};
        
        sort(changed.begin(), changed.end());
        unordered_map<int,int> counts;
        
        vector<int> ans;
        
        for(int c: changed) {
            counts[c]++;
        }
        
        for(int c: changed) {
            if(counts[c] <= 0) continue;
            if(counts[2*c] > 0) {
                ans.push_back(c);
                counts[c]--;
                counts[2*c]--;
            } else return {};
        }
        
        return ans;
    }
};