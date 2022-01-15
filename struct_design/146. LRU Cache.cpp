class LRUCache {
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
            if(--_capacity<0)
            {
                eraseLeastUsed();
                ++_capacity;
            }
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
