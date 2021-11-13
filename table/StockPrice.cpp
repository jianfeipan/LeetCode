class Solution {
  /*
  Given an arry of unsigned int as stock prices, you will buy at a moment then sell it, compute the most big profit , if cannot make profit, it should return 0
  ex:
  Input: temperatures = [2,3,1,4,2,3,6] Output: 5 (6-1) 
  */
public:
    //O(N^2)
    int bestProfit_solution1(const vector<int> prices) {
        int bestProfit = 0;
        for(int i = 0; i < prices.size(); ++i)
        {
            for(int j = i+1; j < prices.size(); ++j)
            {
                int profit = prices[j] - prices[i];
                if(bestProfit<profit)
                {
                    bestProfit = profit;
                }
            }
        }
    }
    
    int bestProfit(const vector<int> prices) {
        int bestProfit = 0;
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i]< minPrice)
            {
                minPrice = prices[i];
            }
            int profit = prices[i] - minPrice;
            if(profit > bestProfit)
            {
                bestProfit = profit;
            }
        }
        
        return bestProfit;
    }
    
    
};
