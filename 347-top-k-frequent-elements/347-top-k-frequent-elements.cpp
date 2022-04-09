class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counter;
        
        for(auto n: nums) {
            counter[n]++;
        }
        
        vector<pair<int,int>> elements(counter.begin(), counter.end());
        
        sort(elements.begin(), elements.end(), [](pair<int,int> &a, pair<int,int> &b) -> bool {
            return a.second > b.second;
        });
        
        vector<int> ans(k);
        for(int i = 0; i < k; ++i) {
            ans[i] = elements[i].first;
        }
        
        return ans;
    }
};