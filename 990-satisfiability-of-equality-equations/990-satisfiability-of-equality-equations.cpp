struct UnionFind {
    int n, cc, *u;
    UnionFind() : n(0), cc(0), u(NULL) {}
    UnionFind(int n_) : n(n_), cc(n_) {
      u = new int[n_];
      memset(u, -1, sizeof (int) * n);
    }
    UnionFind(const UnionFind &y) : n(y.n), cc(y.cc) {
      u = new int[y.n];
      memcpy(u, y.u, sizeof (int) * n);
    }
    ~UnionFind() {
      delete[] u; u = NULL;
      n = cc = 0;
    }
    friend void swap(UnionFind &x, UnionFind &y) {
      swap(x.n, y.n); swap(x.cc, y.cc); swap(x.u, y.u);
    }
    UnionFind& operator=(UnionFind y) { 
      swap(*this, y);
      return *this;
    }
    int root(int x) {
      int y = x, t;
      while (u[y] >= 0) y = u[y];
      while (x != y) { t = u[x]; u[x] = y; x = t; }
      return y;
    }
    bool link(int x, int y) {
      x = root(x); y = root(y);
      if (x == y) return false;
      if (u[y] < u[x]) swap(x, y);
      u[x] += u[y]; u[y] = x; cc--;
      return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int count_node(int x) { return -u[root(x)]; }
    int count_tree() { return cc; }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        
        for(string s: equations) {
            if(s[1] == '=') {
                uf.link(s[0] - 'a', s[3] - 'a');
            }
        }
        
        for(string s: equations) {
            if(s[1] == '!') {
                if(uf.same(s[0] - 'a', s[3] - 'a')) return false;
            }
        }
        
        return true;
    }
};