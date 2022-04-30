class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        map<string,double> mp;
        map<string,vector<string>> graph;
        
        for(int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            mp[u+"-"+v] = values[i];
            mp[v+"-"+u] = 1/values[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(int i = 0; i < queries.size(); ++i) {
            string start = queries[i][0];
            string end = queries[i][1];
            if(graph.find(start) == graph.end()
               || graph.find(end) == graph.end()) {
                ans.push_back(-1);
                continue;
            }

            if(start == end) {
                ans.push_back(1);
                continue;
            }
            
            double value = 1;
            set<string> visited;
            bool found = false;
            
            dfs(start, end, mp, graph, value, visited, found);

            if(found) ans.push_back(value);
            else ans.push_back(-1);
        }
        
        return ans;
    }
    
    void dfs(string start, string end, map<string,double>& mp,
             map<string,vector<string>>& graph, double &value,
             set<string>& visited, bool& found) {
        visited.insert(start);
    
        if(found) return;
        
        for(auto child: graph[start]) {
            if(visited.find(child) == visited.end()) {
                value *= mp[start+"-"+child];
                if(end == child) {
                    found = true;
                    return;
                }
                
                dfs(child, end, mp, graph, value, visited, found);
                if(found) return;
                
                value /= mp[start+"-"+child];
            }
        }
    }
};