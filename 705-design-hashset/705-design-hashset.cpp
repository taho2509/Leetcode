#define mod 199933
class MyHashSet {
    vector<bool> keys;
public:
    MyHashSet() {
        keys = vector<bool>(mod, false);
    }
    
    void add(int key) {
        keys[key%mod] = true;
    }
    
    void remove(int key) {
        keys[key%mod] = false;
    }
    
    bool contains(int key) {
        return keys[key%mod];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */