class Solution {
    map<tuple<string,string,string>, bool> DP;
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        if(n == 0 && m == 0 && k == 0) return true;
        if(n + m != k) return false;
        
        if(n == 0) return s2 == s3;
        if(m == 0) return s1 == s3;
        
        if(DP.count({s1,s2,s3}) != 0) return DP[{s1,s2,s3}];
        
        if(s1[0] == s3[0]) {
            if(isInterleave(s1.substr(1), s2, s3.substr(1))) {
                DP[{s1,s2,s3}] = true;
                return true;
            }
        }
        if(s2[0] == s3[0]) {
            if(isInterleave(s1, s2.substr(1), s3.substr(1))) {
                DP[{s1,s2,s3}] = true;
                return true;
            }
        }
        DP[{s1,s2,s3}] = false;
        return false;
    }
};