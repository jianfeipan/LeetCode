class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
        
        
        
        start still with a DP , but since we have a operation limit, (cool down), we need a LIMITED STATUS MACHINE
        
        S0 : initial state ---can go to s1 by BUY, or can stay in s0 by REST
        S1 : POSITIONED --> can come from S0 and can go to S2 by SELL, or can keep postion by REST
        S3 : SELLED  ---> can come from S1 by SELL, can go to S0 by REST
        

Hence, from there, you can now the profit at a state at time i as:

s0[i] = max(s0[i - 1], s2[i - 1]); // Stay at s0, or rest from s2
s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]); // Stay at s1, or buy from s0
s2[i] = s1[i - 1] + prices[i]; // Only one way from s1
Then, you just find the maximum of s0[n] and s2[n], since they will be the maximum profit we need (No one can buy stock and left with more profit that sell right

        
        
        
        */
        return maxProfit_status(prices);
    }
    
private:
    int maxProfit_status(vector<int>& prices){
		if (prices.size() <= 1) return 0;
        
		vector<int> s0(prices.size(), 0);
		vector<int> s1(prices.size(), 0);
		vector<int> s2(prices.size(), 0);
        
		s0[0] = 0; // At the start, you don't have any stock if you just rest
		s1[0] = -prices[0];// After buy, you should have -prices[0] profit.
		s2[0] = INT_MIN;// Lower base case
        
		for (int i = 1; i < prices.size(); i++) 
        {
			s0[i] = max(s0[i - 1], s2[i - 1]);
			s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
			s2[i] = s1[i - 1] + prices[i];
		}
		return max(s0[prices.size() - 1], s2[prices.size() - 1]);//S0 and S2 is two acceptable states ain the end
	}

    
};
