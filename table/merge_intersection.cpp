/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

/*
描述
给出若干闭合区间，合并所有重叠的部分。

样例
样例1:

输入: [(1,3)]
输出: [(1,3)]
样例 2:

输入:  [(1,3),(2,6),(8,10),(15,18)]
输出: [(1,6),(8,10),(15,18)]
挑战
O(n log n) 的时间和 O(1) 的额外空间。

[(2,3),(2,2),(3,3),(1,3),(5,7),(2,2),(4,6)]
[(2,3),(2,2),(3,3),(5,7),(2,2),(4,6),(0,0)]

*/

class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */

     /*
     similar to the validation of parethese : ()(())(((()())))
     we need a stack
     
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // map to sort then merge
        map<int, int> axe;
        for(const auto & interval : intervals) 
        {
            ++axe[interval.start] ;//open
            --axe[interval.end];//close
        }

        vector<Interval> result;
        std::stack<int> openIntervalFroms;
        for(  auto it = axe.begin(); it!=axe.end(); ++it)
        {
            if(it->second > 0)
            {
                while(it->second>0)
                {
                    --it->second;
                    openIntervalFroms.push(it->first);
                }
            }
            else if(it->second < 0)
            {
                while(it->second<0)
                {
                    ++it->second;
                    if(openIntervalFroms.size() == 1)
                    {   
                        int from = openIntervalFroms.top();
                        int to = it->first;
                        result.emplace_back(from, to);
                    }
                    openIntervalFroms.pop();
                }
            }
            else
            {
                if(openIntervalFroms.empty())
                {
                    result.emplace_back(it->first, it->first);
                }
            }
        }
        return result;

    }
};
