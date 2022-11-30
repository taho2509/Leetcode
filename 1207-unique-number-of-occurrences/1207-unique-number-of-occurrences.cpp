class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> counts;
        
        for(int a: arr) {
            counts[a]++;
        }
        
        vector<bool> exist(1001, false);
        for(auto [k,v]: counts) {
            if(exist[v]) return false;
            else exist[v] = true;
        }
        
        return true;
    }
};