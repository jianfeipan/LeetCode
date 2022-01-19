class Solution {
public:
    
    bool isMatch(string s, string p) 
    {
        return isMatch_recusive(s.c_str(), p.c_str(),0,0);
    }
    
    bool isMatch_one_loop(const string & s, const string & p) 
    {
      int sStar = -1;
      int pStar = -1;

      int sIndex = 0;
      int pIndex = 0;

      while (sIndex < s.size())
      {
         if ((pIndex<p.size() && p[pIndex] == '?') || (p[pIndex] == s[sIndex])) { ++sIndex; ++pIndex; }

         else if (pIndex<p.size() && p[pIndex] == '*') { pStar = pIndex; ++pIndex; sStar = sIndex; }

         else if (pStar != -1) { pIndex = pStar + 1; ++sStar; sIndex = sStar; }

         else return false;
      }

      //check for remaining characters in pattern
      while (p[pIndex] == '*') { ++pIndex; }

      return pIndex == p.size();
   }

    
    bool isMatch_recusive(const string & s, const string & p, int input, int pattern) 
    {
        while(input < s.size())
        {
            if(pattern < p.size() && p[pattern] == '*')
            {
                while(pattern < p.size() && p[pattern] == '*')  ++pattern;
                
                if(pattern == p.size()) return true;
                                
                while(input < s.size())
                {
                    if((p[pattern]=='?' || p[pattern] == s[input]) && isMatch_recusive(s, p, input+1, pattern+1)) return true;
                
                    ++input;
                }
            }
            else if(pattern < p.size() && (p[pattern] == '?' || s[input] == p[pattern]) ) ++input,++pattern;
            else return false;
        }
        
        while(pattern < p.size() && p[pattern] == '*')  ++pattern;
        
        return input == s.size() && pattern == p.size();
    }
};
