class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if(amount == 0) return 0;
        sort(coins.begin(), coins.end());
        auto count =  coinChange_dp(coins, amount);
        return count<0 ? -1 : count;
    }
    
private:
    unordered_map<int, int> minCoinsCount;
    
    int coinChange_dp(const vector<int> & coins, int amount)
    {
        //cout<<amount<<endl;
        auto it  = minCoinsCount.find(amount);
        if(it != minCoinsCount.end())
        {
            return it->second;
        }
        else
        {
            if(amount == 0) return 0;
            if(amount<coins[0]) return -1;
            
            int minCount = INT_MAX;
            for(const auto & coin : coins)
            {
                auto prevCount = coinChange_dp(coins, amount - coin);
                if(prevCount>=0)
                {
                    auto count = 1 + prevCount;
                    minCount = min(minCount, count);
                }
            }
            if(minCount == INT_MAX) minCount = -1;
            minCoinsCount[amount] = minCount;
            
            return minCount;
        }
    }
    
    
    int coinChange_greedy(const vector<int> & coins, int amount)
    {
        int count = 0;
        for(int i = coins.size()-1; i>=0; --i)
        {
            
            const int currentValue = coins[i];
            const int currentCount = amount/currentValue;
            const int realSum = currentCount*currentValue;
            
            //cout<<"amount : "<<amount<<" currentValue:"<<currentValue<< " realSum:"<<realSum<<endl;
            
            count += currentCount;  
            if(realSum == amount) return count;
            else if(realSum < amount) amount-=realSum;
        }
        return -1;
    }
};
