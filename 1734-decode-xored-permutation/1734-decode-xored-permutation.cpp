class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();
        int a = 0;
        
        if ((n + 1) % 4 == 0) a = n + 1;
        if ((n + 1) % 4 == 1) a = 1;
        if ((n + 1) % 4 == 2) a = n + 2;

        for(int i = 1; i < n; i += 2) {
            a = a ^ encoded[i];
        }
        
        vector<int> decoded;
        decoded.push_back(a);
        
        for(int i = 0; i < n; i++) {
            a = a ^ encoded[i]; 
            decoded.push_back(a);
        }
        return decoded;
    }    
};