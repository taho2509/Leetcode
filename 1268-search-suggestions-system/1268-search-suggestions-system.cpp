class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        
        vector<vector<string>> ans;
        
        for(int i = 0; i < searchWord.size(); ++i) {
            string search = searchWord.substr(0, i + 1);
            int j = find(products, search);
            int k = 3;
            vector<string> current;
            while(k > 0 && j < products.size() && match(search, products[j])) {
                current.push_back(products[j]);
                ++j;
                --k;
            }
            ans.push_back(current);
        }
        
        return ans;
    }
    
    int find(vector<string>& products, string &s) {
        int start = 0, end = products.size();
        
        while(start < end) {
            int m = (start + end)/2;
            if(products[m] < s) {
                start = m + 1;
            } else {
                end = m;
            }
        }
        
        return start;
    }
    
    bool match(string &search, string &b) {
        int n = search.size();
        int m = b.size();
        if(m < n) return false;
        for(int i = 0; i < n; ++i) {
            if(search[i] != b[i]) return false;
        }
        
        return true;
    }
};