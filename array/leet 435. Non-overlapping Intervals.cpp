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
        if(intervals.empty()) return -1; // throw an exception
        
        int toBeDeleted = 0;
        sort(intervals.begin(), intervals.end());
        

        vector<int> currnetInterval = intervals[0];
        
        for(size_t i = 1; i < intervals.size(); ++i)
        {
            //check overlapping
            if(currnetInterval[1] >intervals[i][0])
            {
                toBeDeleted++;
                if(currnetInterval[1] >= intervals[i][1])
                    currnetInterval = intervals[i];//remove the first one
                //remove the first one: currnetInterval stays
            }
            else
                currnetInterval = intervals[i];
        }
        return toBeDeleted;
    }
};
