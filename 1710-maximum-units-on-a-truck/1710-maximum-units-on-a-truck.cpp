class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.rbegin(), boxTypes.rend(), 
             [](vector<int> &a, vector<int> &b) -> bool {
                 return a[1] < b[1];
             });
        
        int i = 0;
        int n = boxTypes.size();
        int ans = 0;
        while(i < n && truckSize > 0) {
            if(truckSize >= boxTypes[i][0]) {
                ans += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            } else {
                ans += truckSize*boxTypes[i][1];
                truckSize = 0;
            }
            ++i;
        }
        
        return ans;
    }
};