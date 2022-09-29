class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();        
        auto it = upper_bound(arr.begin(), arr.end(), x);
        
        int i = it - arr.begin() - 1;
        int j = i + 1;
        vector<int> ans;
        
        while(k > 0) {
            if(i >= 0 && j < n) {
                int ai = abs(arr[i] - x), aj = abs(arr[j] - x);
                if((ai < aj) || ((ai == aj)&&(arr[i] < arr[j]))) {
                    ans.push_back(arr[i]);
                    --i;
                } else {
                    ans.push_back(arr[j]);
                    ++j;
                }
            } else if(i >= 0) {
                ans.push_back(arr[i]);
                --i;
            } else {
                ans.push_back(arr[j]);
                ++j;
            }
            --k;
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};