class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {//Monoton stack : left small 
        
        vector<int> daysToWait(temperatures.size(), 0);
        stack<pair<int, int>> leftSmall;
        
        for(int i = 0; i<temperatures.size(); ++i)
        {
            while(!leftSmall.empty() && leftSmall.top().second < temperatures[i])
            {
                daysToWait[leftSmall.top().first] = i - leftSmall.top().first;
                leftSmall.pop();
            }
            leftSmall.push({i, temperatures[i]});
        }
        return daysToWait;
    }

    
    // backward --> when you are checking the i point, whichi is his warmer next day, you could check i+1
    // if i+1 is already warmer, so result[i] = 1
    // if not, you can check ask which is i+1 's next warmer day by using the result, then you just check this next warmer day is warmer for i, if not do the same step to search till end.
    vector<int> dailyTemperatures_2(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            int j = i+1;
            while (j < temperatures.size() && temperatures[j] <= temperatures[i]) {
                if (res[j] > 0) 
                    j = res[j] + j;
                else 
                    j = temperatures.size();
            }
            // either j == size || temperatures[j] > temperatures[i]
            if (j < temperatures.size()) 
                res[i] = j - i;
        }
        return res;
    }
};
