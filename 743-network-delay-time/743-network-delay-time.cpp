#define INF 0x3f3f3f3f
class Graph {
    int V;
public:
    list<pair<int, int>> *adj;
    Graph(int V) {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }
    
    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
    }

    vector<int> shortestPath(int s) {
        set<pair<int, int>> setds;
        vector<int> dist(V, INF);
        setds.insert(make_pair(0, s));
        dist[s] = 0;

        while (!setds.empty()) {
            pair<int, int> tmp = *(setds.begin());
            setds.erase(setds.begin());
            int u = tmp.second;

            list<pair<int, int>>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i) {
                int v = (*i).first;
                int weight = (*i).second;

                if (dist[v] > dist[u] + weight) {
                    if (dist[v] != INF) setds.erase(setds.find(make_pair(dist[v], v)));

                    dist[v] = dist[u] + weight;
                    setds.insert(make_pair(dist[v], v));
                }
            }
        }

        return dist;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        Graph g(n);
        for(auto e: times) {
            g.addEdge(e[0] - 1, e[1] - 1, e[2]);
        }

        vector<int> distances = g.shortestPath(k - 1);
        int m = 0;
        for(auto d: distances) {
            if(d == INF) return -1;
            m = max(m, d);
        }
        
        return m;
    }
};