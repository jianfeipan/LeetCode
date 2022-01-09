class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string &s) 
    {
        /*
        idea2 : the set we used in idea1 is precious, we can move the window instand of restart from 0
        */
        if(s.size()<=1) return s.size();

        int maxLen = 1;
        int from = 0;
        int to = 1;
        unordered_set<char> checked;//can be rpelaced by bitmap
        checked.insert(s[0]);
        while(to<s.size())
        {
            auto it = checked.find(s[to]);
            if(it == checked.end())
            {
                checked.insert(s[to]);
                auto len = to - from +1;
                if(len>maxLen)
                    maxLen = len;

                ++to;
            }
            else
            {
                checked.erase(s[from]);
                ++from;
            }
        }
        return maxLen;

    }


    int lengthOfLongestSubstring_brute_forc(string &s) //O(N^2)
    {
        //idea1 from i then incremetnal till repeatation, with a set  
        int maxLen = 0;

        for(int start = 0; start < s.size(); ++start)
        {
            unordered_set<char> checked;
            int to = start;
            for( ; to < s.size(); ++to)
            {
                auto it = checked.find(s[to]);
                if(it == checked.end())
                {
                    checked.insert(s[to]);
                }
                else
                {
                    break;
                }
            }
            --to;
            auto len = to - start+1;
            if(len>maxLen)
                maxLen = len;
        }

        return maxLen;
    }


};
