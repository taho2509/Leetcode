class RandomizedSet {
unordered_map<int,int> m;
    vector<int> elements;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val) == m.end()) {
            m[val] = elements.size();
            elements.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        int n = elements.size();
        auto it = m.find(val);
        if(it == m.end()) return false;
        m[elements[n - 1]] = it->second;
        swap(elements[it->second],elements[n - 1]);
        m.erase(val);
        elements.pop_back();
        return true;
    }
    
    int getRandom() {
        int i = rand() % m.size();
        return elements[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */