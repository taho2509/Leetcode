class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        int start = 0, end = min(n, m);
        
        string ans = "";
        string current = "";
        
        while(start < end) {
            current += str1[start];
            if(check(str1, str2, current)) {
                ans = current;
            }
            ++start;
        }
        
        return ans;
    }
    
    bool check(string &s1, string &s2, string t) {
        int n = s1.size();
        int m = s2.size();
        int k = t.size();
        
        if(n % k != 0 || m % k != 0) return false;
        
        for(int i = 0; i < n; ++i) {
            if(s1[i] != t[i%k]) return false;
        }
        
        for(int i = 0; i < m; ++i) {
            if(s2[i] != t[i%k]) return false;
        }
        
        return true;
    }
};