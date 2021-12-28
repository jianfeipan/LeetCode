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
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto it = _cache.find(key);
        
        if(it!=_cache.end())
        {
            
            markAsUsed(key);
            return it->second.first;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = _cache.find(key);
        if(it == _cache.end())
        {
            _keys.push_front(key);
            if(_capacity>0)
            {
                --_capacity;
            }
            else
            {
                _cache.erase(_keys.back());
                _keys.pop_back();
            }
        }
        else
        {
            
            markAsUsed(key);
        }
        _cache[key] = { value, _keys.begin() };
        
    }
    
private:
    void markAsUsed(int key)
    {
        _keys.erase(_cache[key].second);//make use of map
        _keys.push_front(key);
        _cache[key].second = _keys.begin();
    }
    
private:
    unordered_map<int, pair<int, list<int>::iterator> > _cache; //fonction 1 : cache to access value 
    list<int> _keys; //function 2 : limited capacity to remove old least recent used key
    int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
