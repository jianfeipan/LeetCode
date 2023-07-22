/*Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

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
lRUCache.get(4);    // return 4*/

class LRUCache {

/*
fact: 
    1 k-v cache , no order in keys 
    2 least Recently Used 
        we need counts of usage 
        we need a container for order
        we need to maintain the size, remove the least Rencent used.

idea:
    1 --> unordered_map
    2 LRU
        2.1: <key, < value, count  > >
        2.2  operations we need on this container  
                add --> new added is most recently used
                move --> if the node is already used, move it to the most recently used position--> random access(make use of the map)
                remove --> remove always the least recent used --> tail
            --> std::list
        2.3 counter of capacity


*/
public:
    LRUCache(int capacity) :
    m_data(), m_positions(), m_capacity(capacity)
    {
    }
    
    int get(int key) {
        auto it = m_data.find(key);
        if(m_data.end() != it)
        {
            const auto value = it->second.first;
            auto pos = it->second.second;
            m_positions.erase(pos);
            m_data[key] = std::make_pair(value, m_positions.insert(m_positions.end(), key));

            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        auto it = m_data.find(key);
        if(m_data.end() == it) //insert 
        {
            --m_capacity;
        }
        else //update
        {
            auto pos = it->second.second;
            m_positions.erase(pos);
        }
        m_data[key] = std::make_pair(value, m_positions.insert(m_positions.end(), key));


        if(m_capacity<0)//Eviction
        {
            auto toEvict = m_positions.front();
            m_data.erase(toEvict);
            m_positions.pop_front();
            ++m_capacity;
        }
        
    }

private:
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> m_data;
    std::list<int> m_positions; // front is least recently used
    int m_capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
