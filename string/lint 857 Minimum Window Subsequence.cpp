class Solution {
public:
    /**
     * @param S: a string
     * @param T: a string
     * @return: the minimum substring of S
     */
    string minWindow(string &s, string &T) 
    {
        int left = 0;
        int right = 0;

        int matched = 0;

        int minLen = INT_MAX;
        string minStr;

        while(right < s.size())
        {
            while(right < s.size() && s[right] != T[0]) ++right;

            left = right;//first letter match
            //cout<<"left"<<left<<endl;

            while(right < s.size() && matched<T.size())//find a left - right match the T
            {
                if(s[right] == T[matched]) ++matched;
                ++right;
            }
            //cout<<"right"<<right<<endl;
            if(right < s.size())
            {
                //here we find a right position matches T
                const int currentLen = right-left;
                if(minLen > currentLen)
                {
                    minLen = currentLen;
                    minStr = s.substr(left, currentLen);
                }
            }
            matched = 0;
            right = left+1;
        }

        return minStr;
    }
};
