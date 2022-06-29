class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),
             [](vector<int> &a, vector<int> &b) -> bool {
                 if(a[1] == b[1]) {
                     return a[0] < b[0];
                 }
                 return a[1] < b[1];
             });

        vector<vector<int>> ans;
        ans.push_back(people[0]);
        int n = people.size();
        for(int i = 1; i < n; ++i) {
            int m = ans.size();
            int j = 0;
            int count = people[i][1];
            while(j < m) {
                if(people[i][0] <= ans[j][0]) {
                    if(count > 0) {
                        count--;
                    } else {
                        break;
                    }
                }
                ++j;
            }
            if(j == ans.size()) {
                ans.push_back(people[i]);
            } else {
                ans.insert(ans.begin() + j, people[i]);
            }
        }
        
        return ans;
    }
};