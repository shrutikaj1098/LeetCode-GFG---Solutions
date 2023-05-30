class MyHashSet {
public:
set<int>v;
    MyHashSet() {
        
    }
    
    void add(int key) {
        v.insert(key);
    }
    
    void remove(int key) {
        v.erase(key);
    }
    
    bool contains(int key) {
        for(auto i: v)
        {
            if(i==key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */