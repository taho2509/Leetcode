class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        
        for(int i = 0; i < n; ++i) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        
        sort(jobs.begin(), jobs.end());

        vector<int> DP(n + 1, 0);

        for(int i = 0; i < n; ++i) {
            int j = i;
            while(j >= 0 && (jobs[j][0] > jobs[i][1])) --j;
            DP[i + 1] = max(DP[i], jobs[i][2] + DP[j + 1]);
        }
        return DP[n];
    }
};