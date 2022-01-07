class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        nums.emplace_back(val);
        m[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        
        const int indexToRemove = m[val];
        
        int last = nums.back();//swap last value to the val's position then remove the last one in vector o(1)
        nums[indexToRemove] = last;
        m[last] = indexToRemove;
        nums.pop_back();
        
        m.erase(val);
        
        return true;
    }
    
    /** Get a random element from the set. a ring with pointer ++ is not random : current value is 0 pobability */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;// random access : random modulo with vector!!!
    unordered_map<int, int> m;// unique element with access o(1) ---> map/set
};
