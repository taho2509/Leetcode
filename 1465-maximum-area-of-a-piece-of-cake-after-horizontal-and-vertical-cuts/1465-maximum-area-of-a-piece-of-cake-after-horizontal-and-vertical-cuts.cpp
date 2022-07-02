class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        hc.push_back(0);
        hc.push_back(h);
        vc.push_back(w);
        vc.push_back(0);
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        int hm = 0, vm = 0;
        
        for(int i = 1; i < hc.size(); ++i) {
            hm = max(hm, hc[i] - hc[i - 1]);
        }
        
        for(int i = 1; i < vc.size(); ++i) {
            vm = max(vm, vc[i] - vc[i - 1]);
        }
        
        return (long long)1*vm*hm % 1000000007;
    }
};