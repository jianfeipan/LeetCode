/*
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.
*/

class Solution {

/*
fact:
    1. any letter repeated should be in the same partition

idea:
    1. partition is good means nothing in rest of the string is in this partition: 
        --> ointer [from, to] as artition, if "to+1" is already in this partition, we make ++to, if to+1 is a new letter, until the end, there is no more exsisted letter, first partition is good. 

    2. "rest doesn't have any letter in the current partition" -->  this is a complecated operations, why not resolve it by letters ? 
        --> any letter has positions, first pos and last pos make a interval, then we need to merge intervals for all the letters we want to make in one range


*/
public:
    vector<int> partitionLabels(string s) {
        std::array<std::array<int, 2>, 26> intervals;
        for(int i = 0; i<26; ++i)
        {
            intervals[i][0] = -1;
        }

        for(int i = 0; i<s.size(); ++i)
        {
            int key = s[i]-'a';
            if(intervals[key][0] == -1) intervals[key][0] = intervals[key][1] = i;
            else intervals[key][1] = i;
        }
        vector<int> res;

        int from = 0;
        while(from<s.size())
        {
            const auto current = s[from];
            int currentFrom = from;
  
            int currentEnd = intervals[current-'a'][1];
            int to = currentEnd;

            bool moreElementFound= true;
            while(moreElementFound)
            {
                moreElementFound = false;
                for(int j = currentFrom+1; j<currentEnd; ++j)
                {
                    if(intervals[s[j] - 'a'][1] > currentEnd)
                    {
                        to =max(intervals[s[j] - 'a'][1], to);
                        moreElementFound = true;
                    }

                }
                currentFrom = currentEnd;
                currentEnd = to;
            }

            res.push_back(to - from+1);
            from = to+1;
        }

        return res;

    }
};
