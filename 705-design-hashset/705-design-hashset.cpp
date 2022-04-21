#define mod 1193
class MyHashSet {
    vector<set<int>> keys;
public:
    MyHashSet() {
        keys = vector<set<int>>(mod);
    }
    
    void add(int key) {
        keys[key%mod].insert(key);
    }
    
    void remove(int key) {
        keys[key%mod].erase(key);
    }
    
    bool contains(int key) {
        return keys[key%mod].count(key) == 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */