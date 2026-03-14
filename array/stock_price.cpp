class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        if(prices.size()>1)
        {
            int minPrice = prices[0];
            for(int price : prices)
            {
                if(price < minPrice)
                {
                    minPrice = price;
                }
                else
                {
                    max = std::max(max, price - minPrice);
                }
            }
        }
        
        return max;
    }
};
