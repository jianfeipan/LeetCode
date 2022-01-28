class LFUCache {
private:
    struct Metric
    {
        int value;
        int freq;
        list<int>::iterator pos;
    };
    
    int _capacity;
    unordered_map<int, Metric> _cache;
    map<int, list<int>> _order;//order by frequency
    
public: 

    LFUCache(int capacity):
    _capacity(capacity),
    _cache(),
    _order()
    {
        
    }
    
    int get(int key)
    {
        auto it = _cache.find(key);
        if(it==_cache.end()) return -1;
        
        markAsUsed(it);
        
        return it->second.value;
        
    }
    
    void put(int key, int value) 
    {
        auto it = _cache.find(key);
        if(it==_cache.end())
        {
            if(_capacity==0)
            {
                auto leastFrequentlyList = _order.begin();
                if(leastFrequentlyList!=_order.end())
                {
                    while(leastFrequentlyList->second.empty()) ++leastFrequentlyList;
                    //cout<<"remove:"<<leastFrequentlyList->second.back()<<endl;
                    _cache.erase(leastFrequentlyList->second.back());    

                    leastFrequentlyList->second.pop_back();
                    ++_capacity;
                }
            }
            if(_capacity>0)
            {
                auto & orders = _order[1];
                orders.push_front(key);

                //cout<<"add:"<<key<<endl;
                _cache[key] = {value, 1, orders.begin()};
                --_capacity;
            }
        }
        else
        {
            it->second.value = value;
            markAsUsed(it);
        }
    }
private:
    void markAsUsed(unordered_map<int, Metric>::iterator it)
    {
        const auto markedFreq = ++(it->second.freq);
        //cout<<"update freq : "<<it->first<<" : "<<markedFreq<<endl;
        _order[markedFreq-1].erase( it->second.pos);
        _order[markedFreq].push_front(it->first);
        it->second.pos = _order[markedFreq].begin();
    }
    
    

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */ 
