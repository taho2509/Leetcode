class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int,int> m;
        for(int a: arr) {
            m[a]++;
        }
        
        vector<pair<int,int>> elements;
        for(auto [key, value]: m) {
            elements.push_back({value, key});
        }
        
        sort(elements.rbegin(), elements.rend());
        
        int ans = 0;
        int taked = 0;
        for(auto [value, key]: elements) {
            taked += value;
            ++ans;
            if(taked >= n/2) break;
        }
        return ans;
    }
};