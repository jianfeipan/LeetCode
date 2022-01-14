/*

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 
 
[[1,2],[2,3],[3,4],[1,3]]
[[1,2],[1,2],[1,2]]
[[1,2],[2,3]]
[[-52,31],[-73,-26],[82,97],[-65,-11],[-62,-49],[95,99],[58,95],[-31,49],[66,98],[-63,2],[30,47],[-40,-26]] --> MAY HAVE SEVERAL SOLUTION we need the min one


*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        int toBeDeleted = 0;
        sort(intervals.begin(), intervals.end());
        
        auto it = intervals.begin();
        int currentStart = it->at(0);
        int currentEnd = it->at(1);
        ++it;
        for(; it!=intervals.end();++it)
        {
            
            cout<< currentStart <<", "<< currentEnd << " vs "<<it->at(0)<< ", "<<it->at(1)<<endl;
            //check overlapping
            if(currentEnd > it->at(0))
            {
                toBeDeleted++;
                if(currentEnd < it->at(1))//the secons one could have bigger possibility to have overlapping the next intervals
                {
                    //remove the second one
                }
                else
                {
                    //remove the first one
                    currentStart = it->at(0);
                    currentEnd = it->at(1);
                }
            }
            else
            {
                currentStart = it->at(0);
                currentEnd = it->at(1);
            }
        }
        return toBeDeleted;
    }
};
