class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) 
    {
        
        vector<vector<int>> result;
        
        size_t i=0;
        size_t j = 0;
        while(i<firstList.size() && j<secondList.size())
        {
            if(firstList[i][0] <= secondList[j][0])//([
            {
                if(firstList[i][1] >= secondList[j][1])//([])
                {
                    result.push_back(secondList[j]);
                    ++j;
                }
                else
                {
                    if(firstList[i][1] >= secondList[j][0])//([)]
                    {
                        result.push_back({secondList[j][0], firstList[i][1]});
                    }//()[]
                    ++i;
                }
            }
            else//[(
            {
                if(firstList[i][1] <= secondList[j][1])//[()]
                {
                    result.push_back(firstList[i]);
                    ++i;
                }
                else
                {
                    if(firstList[i][0] <= secondList[j][1])//[(])
                    {
                        result.push_back({firstList[i][0], secondList[j][1]});
                    }//[]()
                    ++j;
                    
                }
            }
        }
        
        
        return result;
    }
};
