class Graph
{
    int V;
public:
    list<int> *adj;
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        //cout << "start" << endl;
        vector<pair<int,int>> visited(n, {0,0});
        
        Graph g(n);
        for(auto e: edges) {
            g.addEdge(e[0] - 1, e[1] - 1);
        }
        
        queue<pair<int,int>> q;
        q.push({0,0});// [node, arriveTime]
        visited[0].first++;
        while(!q.empty()) {
            auto [u, arriveTime] = q.front();
            q.pop();
            
            bool wait = (arriveTime/change)%2 == 1;
            int waitTime = !wait ? 0 : (change - arriveTime%change);
            int nextArriveTime = arriveTime + waitTime + time;
            
            for (auto v: g.adj[u]) {
                if(visited[v].first >= 2) continue;
                if(visited[v].second == nextArriveTime) continue;
                
                visited[v].first++;
                visited[v].second = nextArriveTime;
                q.push({v,nextArriveTime});
                
                if(v == n - 1 && visited[v].first == 2) return nextArriveTime;
            }
        }
        return -1;
    }
};