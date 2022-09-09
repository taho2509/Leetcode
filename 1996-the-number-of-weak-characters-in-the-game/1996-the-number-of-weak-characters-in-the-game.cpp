class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& props) {
        sort(props.begin(), props.end(), [](vector<int> &a, vector<int> &b) -> bool {
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        
        int n = props.size();
        
        vector<int> maxes(n + 1, 0);
        
        for(int i = n - 1; i >= 0; --i) {
            maxes[i] = max(maxes[i + 1], props[i][1]);
        }
        
        int count = 0;
        for(int i = 0; i < n - 1; ++i) {
            int up = bs(props, i + 1, props[i][0] + 1);
            if(up >= n) continue;
            if(maxes[up] > props[i][1]) {
                ++count;
            }
        }
        
        return count;
    }
    
    int bs(vector<vector<int>>& props, int start, int val) {
        int end = props.size();
        
        while(start < end) {
            int m = (start + end)/2;
            if(m == props.size()) return m;
            if(props[m][0] < val) {
                start = m + 1;
            } else {
                end = m;
            }
        }
        
        return start;
    }
};