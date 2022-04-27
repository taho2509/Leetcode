#define N 100001
class DSU
{
public:
    int parents[N];
  DSU(int n)
  {
    for (int i = 0; i < n; i++)
    {
      parents[i] = i;
    }
  }
  int find(int x)
  {
    return parents[x] == x ? x : (parents[x] = this->find(parents[x]));
  }

  bool unite(int i, int j)
  {
    i = this->find(i);
    j = this->find(j);

    if (i == j)
      return false;
    parents[j] = i;
    return true;
  }
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DSU uf(n);
        
        // DSU to find groups
        for(auto v: pairs) uf.unite(v[0],v[1]);
        
        unordered_map<int,priority_queue<short>> groups;
        
        // separate groups and sort groups
        for(int i = 0; i < n; ++i) {
            groups[uf.find(i)].push(-s[i]);
        }
        
        string ans = "";
        // compose new string
        for(int i = 0; i < n; ++i) {
            ans += (-groups[uf.find(i)].top());
            groups[uf.find(i)].pop();
        }
        return ans;
    }
};