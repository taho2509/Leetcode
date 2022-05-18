class Solution {
int discoveryTime = -1;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> discoveryTimes = vector<int>(n);
        vector<int> low = vector<int>(n);
        vector<bool> visited = vector<bool>(n);
        
        vector<vector<int>> bridges;
        vector<int> parent = vector<int>(n);
        vector<vector<int>> adj(n, vector<int>());

        for (vector<int> c :connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        dfs(adj, visited, bridges, 0, discoveryTimes, low, parent);
        
        return bridges;
    }
    
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<vector<int>> &bridges, int currentNode, vector<int> &discoveryTimes, vector<int> &low, vector<int> &parent) {
        visited[currentNode] = true;
        discoveryTimes[currentNode] = ++discoveryTime;
        low[currentNode] = discoveryTime;
        
        for (int adjNode : adj[currentNode]) {
            
            if (!visited[adjNode]) {
                parent[adjNode] = currentNode;
                dfs(adj, visited, bridges, adjNode, discoveryTimes, low, parent);
                low[currentNode] = min(low[currentNode], low[adjNode]);
            } else {
                if (parent[currentNode] != adjNode) {
                    low[currentNode] = min(low[currentNode], discoveryTimes[adjNode]);
                }
            }
            
            if (low[adjNode] > discoveryTimes[currentNode]) {
                bridges.push_back({currentNode, adjNode});
            }
        }
    }
};