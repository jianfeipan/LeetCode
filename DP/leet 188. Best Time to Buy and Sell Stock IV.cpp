class Solution {    

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/
public:  
    
    int maxProfit(int k, vector<int>& prices) {
        /*
        DP problem
        */
        vector<vector<int>> maxProfits(k+1, vector<int>(prices.size() + 1, 0));
        for(int tradeNb = 1; tradeNb<=k;++tradeNb)
        {
            int maxDiff = INT_MIN;
            for(int day = 2; day<prices.size()+1; ++day)
            {
                maxDiff = max(maxDiff, maxProfits[tradeNb-1][day-2] - prices[day-2]);//---------> replace the for loop of all buy days
                //maxDiff      = maxProfit0 - price1
             
                //betterProfit = maxDiff +  price2 = maxProfit0 - price1 + price2 --> maxPrice one price1 now on price 2 
                const int maxIfSellThisDay = maxDiff + prices[day-1];

                const int ifNotTradeThisDay = maxProfits[tradeNb][day-1];

                maxProfits[tradeNb][day] = max(maxIfSellThisDay, ifNotTradeThisDay); 
                //cout<<"tradeNb : "<<tradeNb<< " day:"<< day<<" maxDiff:"<<maxDiff<< " maxprofit : "<<maxProfits[tradeNb][day]<<endl;
            }
        }
        return  maxProfits[k][prices.size()];
    }
    
};
