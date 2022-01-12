class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> merged;
        //sort intervals then merge one by one
        
        // sort(intervals.begin(), intervals.end());
        sort(intervals.begin(), intervals.end(),[](const vector<int> & left, const vector<int> & right)
             {
                 return left[0]<right[0];
             });
        
        vector<int> currentInterval = intervals[0];
        
        for(int i = 1; i<intervals.size(); ++i)
        {
            if(intervals[i][0]<= currentInterval[1])
            {
                currentInterval[1] = max(intervals[i][1], currentInterval[1]);
            }
            else
            {
                merged.push_back(currentInterval);
                currentInterval = intervals[i];
            }
        }
        merged.push_back(currentInterval);
        
        return merged;
    }
    
    
    vector<vector<int>> merge_with_tree_map_sort(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> merged;
        
        map<int, int> openCloses;
        for(const auto & interval : intervals)
        {
            ++openCloses[interval[0]];                    
            --openCloses[interval[1]];        
        }
        
        stack<int> opens;
        for(auto openClose : openCloses)
        {
            if(openClose.second > 0)
            {
                while(openClose.second>0)
                {
                    --openClose.second;
                    opens.push(openClose.first);//cout<<"push : "<<openClose.first<<endl;
                }
            }
            else if(openClose.second < 0)
            {
                while(openClose.second<0)
                {
                    if(opens.size() == 1)
                    {
                        int start = opens.top();
                        int end = openClose.first;
                        merged.push_back({start, end});//cout<<"insert : "<<start<<"-"<<end<<endl;
                    }
                    ++openClose.second;
                    opens.pop();//cout<<"pop : "<<openClose.first<<endl;
                }
                
            }
            else
            {
                if(opens.empty())
                    merged.push_back({openClose.first, openClose.first});
            }
            
        }
        return merged;
    }
};
