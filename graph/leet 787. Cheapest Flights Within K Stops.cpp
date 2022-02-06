class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flightsPairs, int src, int dst, int k) 
    {
        /*
        BFS
        */
        
        unordered_map<int, unordered_map<int, int>> flights;
        
        for(const auto & flightsPair : flightsPairs)
            flights[flightsPair[0]][flightsPair[1]] = flightsPair[2];
        
        queue<pair<int, int>> level;
        level.push({src, 0});
        
        unordered_map<int, int> minPriceFrom;
        
        int minPrice = INT_MAX;
        
        while(k-->=-1 && !level.empty())
        {
            int size = level.size();
            
            while(size-->0)
            {
                const auto & current = level.front();
                
                const auto & currentCity = current.first;
                const auto & currentPrice = current.second;
                
                auto it = minPriceFrom.find(currentCity);
                
                if(it==minPriceFrom.end() || it->second>currentPrice)
                {
                    minPriceFrom[currentCity] = currentPrice;
                    
                    if(dst == currentCity) minPrice = min(minPrice, currentPrice);

                    for(const auto & [nextCity, price] : flights[currentCity])
                    {
                        level.push({nextCity, currentPrice + price});
                    }
                }
                level.pop();
            }
        }
        
        return minPrice == INT_MAX ? -1 : minPrice;
    }
};
