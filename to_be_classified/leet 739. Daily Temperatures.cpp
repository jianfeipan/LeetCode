/*
You are given an array of integers temperatures where temperatures[i] represents the daily temperatures on the ith day.

Return an array result where result[i] is the number of days after the ith day before a warmer temperature appears on a future day. If there is no day in the future where a warmer temperature will appear for the ith day, set result[i] to 0 instead.

Example 1:

Input: temperatures = [30,38,30,36,35,40,28]

Output: [1,4,1,2,1,0,0]
Example 2:

Input: temperatures = [22,21,20]

Output: [0,0,0]
Constraints:

1 <= temperatures.length <= 1000.
1 <= temperatures[i] <= 100
*/


class Solution {
public:
    // dynamic programming: 
    // res[i] means how many days to my right warmer -> reuse this information
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = temperatures.size();
        vector<int> res(n, 0);
        //res[n - 1] == 0 is by default and by design
        for(int i = n - 2; i>=0; --i){
            int j = i+1;
            while(j<n){
                if(temperatures[i]<temperatures[j]) break;
                else {
                    if(res[j] == 0) //no warmer for j, and since i is wamer than j, no warmer for i
                    {
                        //keep res[i] 0
                        j=n;
                        break;
                    }
                    else{
                         j+=res[j]; 
                         // j has warmer at j+res[j], let's compare this one with i
                         // this actually avoids the unnecessary comparisons. 
                    }
                }
            }
            if(j<n) res[i] = j-i;
        }
        return res;
    }


    vector<int> dailyTemperatures_monotonStack(vector<int>& temperatures) {
        //monotonStack only take greater than current elements.
        //stack tracks the days needs a warmer temperatures
        vector<int> res(temperatures.size());
        stack<pair<int,int>> indexAndTemp;
        //it's actually a greater stack: only stores bigger, 
        //because smallers are poped when there is a warmer day

        for(int i=0; i<temperatures.size(); ++i){
            while(!indexAndTemp.empty()){
                if(indexAndTemp.top().second < temperatures[i]){
                    res[indexAndTemp.top().first] = i - indexAndTemp.top().first;
                    indexAndTemp.pop();
                }
                else
                {
                    break;
                }
            }
            indexAndTemp.push({i,temperatures[i]});
        }
        //for those stay in the stack after looping, they are 0 by default
        return res;

    }


    vector<int> dailyTemperatures_bf(vector<int>& temperatures) {
        //30,38,30,36,35,40,28
        //^--^
        //   ^-----------^
        //      ^--^
        //         ^-----^
        //BF solution: O(N^2) loop all elements and find the warmer on the right
        vector<int> res(temperatures.size());
        for(int i=0; i<temperatures.size(); ++i){
            int j = i+1;
            while(j<temperatures.size()){
                if(temperatures[j]>temperatures[i]){
                    break;
                }
                ++j;
            }
            if(j==temperatures.size()) 
                res[i] = 0;
            else
                res[i] = j-i;
        }
        return res;
        //use a data structure to have the warmer temp
    }
};
