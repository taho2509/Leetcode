class TNode {
    public:
    int index;
    vector<TNode*> children;
    TNode(int index):children(vector<TNode*>(27, nullptr)), index(index){}
    
    void insert(string &s, int i, int pos) {
        int index = (s[i] == '#') ? 26 : s[i] - 'a';
        if(i >= s.size()) return;

        if(children[index] == nullptr) children[index] = new TNode(pos);
        children[index]->index = pos;

        if(i < s.size() - 1) children[index]->insert(s, i + 1, pos);
    }
    
    int match(string &s, int i) {
        int n = s.size();
        if(i >= n) return -1;
        int index = (s[i] == '#') ? 26 : s[i] - 'a';

        if(children[index] == nullptr) return -1;

        return i == n - 1 ?
            children[index]->index
            : children[index]->match(s, i + 1);
    }
};

class WordFilter {
    TNode* tree;
public:
    WordFilter(vector<string>& words) {
        tree = new TNode(-1);
        
        int i = 0;
        for(string s: words) {
            string full = s + "#" + s;
            for(int j = 0; j < s.size(); ++j) {
                string t = full.substr(j);
                tree->insert(t, 0, i);
            }
            ++i;
        }
    }

    int f(string prefix, string suffix) {
        string full = suffix + "#" + prefix;
        return tree->match(full, 0);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */