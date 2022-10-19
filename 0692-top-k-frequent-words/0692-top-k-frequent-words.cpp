class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        sort(words.begin(), words.end());
        
        priority_queue<pair<int,string>> pq;
        
        string current = words[0];
        int count = 1;
        int n = words.size();
        for(int i = 1; i < n; ++i) {
            if(words[i] == current) {
                ++count;
            } else {
                pq.push({-count, current});
                current = words[i];
                count = 1;
                if(pq.size() > k) pq.pop();
            }
        }
        
        pq.push({-count, current});
        if(pq.size() > k) pq.pop();
        
        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};