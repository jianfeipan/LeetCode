class Solution {
    
    /*
    Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104


    */
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        //idea: sort, then use two pointer to merge
        if(intervals.size()<=1) return intervals;//throw an exception
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        
        vector<int> currentInterval = intervals[0];
        
        for(size_t i = 1; i<intervals.size(); ++i)
        {
            //()[], ([)], or([]) ---> dont'' foret that you did the sort
            if(currentInterval[1] < intervals[i][0])
            {
                merged.push_back(currentInterval);
                currentInterval = intervals[i];
            }
            else
            {
                currentInterval[1] = max(currentInterval[1], intervals[i][1]);
            }
        }
        
        merged.push_back(currentInterval);
        
        return merged;

       
    }
};
