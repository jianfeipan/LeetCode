class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        deque<pair<char, size_t>> left;
        for(char c : s)
        {
            if(left.empty() || left.back().first!=c)
            {
                left.push_back({c, 1});
            }
            else 
            {
                left.back().second++;
                if(left.back().second ==k)
                {
                    left.pop_back();
                }
            }
        }
        
        stringstream ss; 
        while(!left.empty())
        {
            ss<<string(left.front().second, left.front().first);
            left.pop_front();
        }
        return ss.str();
    }
};
