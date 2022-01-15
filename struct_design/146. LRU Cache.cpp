class LRUCache {
  
  /*
  Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

  
["LRUCache","put","put","get","put","get"]
[[2],[2,2],[1,1],[1],[3,3], [2]]
["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
["LRUCache","put","put","get","put","put","get"]
[[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]
  
  
  */
public:
    LRUCache(int capacity):
    _capacity(capacity),
    _data(),
    _mostRencentUsedKey()
    {
    }
    
    int get(int key) 
    {
        if(_data.count(key))
        {
            markAsUsed(key);
            return _data[key].first;
        }
        else return -1;
    }
    
    void put(int key, int value) 
    {
        if(_data.count(key))
        {
            _data[key].first = value;
            markAsUsed(key);
        }
        else
        {
            --_capacity;
            if(_capacity==0)
                eraseLeastUsed();
            
            _mostRencentUsedKey.push_front(key);
            _data[key] = {value, _mostRencentUsedKey.begin()};
        }
    }
    
private:
    
    void eraseLeastUsed()
    {
        auto leastUsedKey = _mostRencentUsedKey.back();
        _mostRencentUsedKey.pop_back();
        _data.erase(leastUsedKey);  
        ++_capacity;
    }
    
    void markAsUsed(int key)
    {
        if(_data.count(key))
        {
            auto it = _data[key].second;
            
            _mostRencentUsedKey.erase(it);
            _mostRencentUsedKey.push_front(key);
            _data[key].second = _mostRencentUsedKey.begin();
        }
    }
    
    
private:
    int _capacity;
    unordered_map<int, pair<int, list<int>::iterator>> _data;
    list<int> _mostRencentUsedKey;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
