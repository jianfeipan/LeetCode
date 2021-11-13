class Solution {
public:
    vector<int> dailyTemperatures_solution1(vector<int>& temperatures) {
        vector<int> daysToWait(temperatures.size(), 0);
        map<int, int> tempToNextWarmerIndex;
        
        
        for(size_t i = 0; i<temperatures.size(); ++i)
        {
            
            auto it = tempToNextWarmerIndex.find(temperatures[i]);
            
            if(it!=tempToNextWarmerIndex.end() && it->second> i)
            {
                if(it->second != -1)
                    daysToWait[i] = it->second - i;
            }
            else
            {
                for(size_t j = i+1; j < temperatures.size(); ++j)
                {
                    if(temperatures[j] > temperatures[i])
                    {
                        daysToWait[i] = j-i;
                        tempToNextWarmerIndex[ temperatures[i]] = j;
                        break;
                    }
                    tempToNextWarmerIndex[ temperatures[i]] = -1;
                }
            }
        }
        return daysToWait;
        
    }
    
    // backward --> when you are checking the i point, whichi is his warmer next day, you could check i+1
    // if i+1 is already warmer, so result[i] = 1
    // if not, you can check ask which is i+1 's next warmer day by using the result, then you just check this next warmer day is warmer for i, if not do the same step to search till end.
    vector<int> dailyTemperatures(vector<int>& temperatures) {
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
