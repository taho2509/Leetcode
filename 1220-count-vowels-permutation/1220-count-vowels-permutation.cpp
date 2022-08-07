#define mod 1000000007
class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> transitions{{1,2,4},{0,2},{1,3},{2},{2,3}};
        
        vector<long> state(5, 1);
        
        for(int i = 2; i <= n; ++i) {
            vector<long> st(5, 0);
            
            for(int j = 0; j < 5; ++j) {
                for(int k = 0; k < transitions[j].size(); ++k) {
                    st[j] += state[transitions[j][k]];
                }
                st[j] =st[j]%mod;
            }
            state = st;
        }
        
        return accumulate(state.begin(), state.end(), 0,
                          [](int a, int b) -> int{ return (a + b)%mod; }
                         );
    }
};