class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target, 0});
        int n = stations.size();
        long long fuel = startFuel;
        int distance = 0;
        int count = 0;
        priority_queue<int> gas;
        
        for(int i = 0; i < n; ++i) {
            if(fuel >= stations[i][0]) {
                gas.push(stations[i][1]);
            } else {
                if(gas.empty()) return -1;
                fuel += gas.top();
                gas.pop();
                count++;
                --i;
            }
        }
        
        return count;
    }
};