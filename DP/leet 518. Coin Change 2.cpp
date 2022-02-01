class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        vector<vector<int>> memory(amount+1, vector<int>(coins.size(),-1));
        return change(amount, 0, coins, memory);
    }
    
private:
    int change(int amount, int from, const vector<int>& coins, vector<vector<int>> & memory) 
    {
        if(amount == 0) return 1;
        
        if(amount<0 || from>=coins.size()) return 0;
        
        auto & cache = memory[amount][from];
        if(cache!=-1) return cache;
        
        int count = 0;
        
        for(int i = from; i<coins.size(); ++i)
        {
            count += change(amount - coins[i], i, coins, memory);
        }
        
        cache = count;
        return count;
    
    }
};
