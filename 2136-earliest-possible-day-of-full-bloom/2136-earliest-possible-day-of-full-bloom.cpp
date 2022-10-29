class Solution {
public:
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
        vector<pair<int,int>> plants;
        int n = plant.size();
        
        for(int i = 0; i < n; ++i) {
            plants.push_back({grow[i], plant[i]});
        } 
        
        sort(plants.rbegin(), plants.rend());
        
        int ans = 0;
        int plantAccumulated = 0;
        for(int i = 0; i < n; ++i) {
            auto [g,p] = plants[i];
            ans = max(ans, plantAccumulated + g + p);
            plantAccumulated += p;
        }
        
        return ans;
    }
};