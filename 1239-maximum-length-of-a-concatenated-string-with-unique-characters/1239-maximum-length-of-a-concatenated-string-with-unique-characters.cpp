class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<pair<int,int>> letters;//tuple: index, hash, count
        
        for(int i = 0; i < n; ++i) {
            if(arr[i].size() > 26) continue;
            int b = 0;
            bool valid = true;
            for(char c: arr[i]) {
                int bp = b | 1 << (c - 'a');
                if(bp == b){
                    valid = false;
                    break;
                }
                b = bp;
            }
            if(valid) letters.push_back({b, (int)arr[i].size()});
        }
        
        return dfs(0, 0, 0, letters);
    }
    
    int dfs(int i, int b, int lenght, vector<pair<int,int>> &letters) {
        if(i == letters.size()) {
            return lenght;
        }
        
        int ans = dfs(i + 1, b, lenght, letters);
        
        auto [hash, count] = letters[i];
        if(((hash ^ b) & hash) == hash
           && ((hash ^ b) & b) == b) {
            ans = max(ans, dfs(i + 1, hash | b, lenght + count, letters));
        }
        
        return ans;
    }
};