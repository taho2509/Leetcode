class Solution {
public:
    long long appealSum(string s) {

        vector<int> hash(26,0);
		long long ans = 0;
        int n = s.size();
        
		for(int i = 0; i < n; ++i) {
			hash[s[i] - 'a'] = i + 1;
			for(int j = 0; j < 26; ++j) ans += hash[j];
		}
		
        return ans;
    }
};