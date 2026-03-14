class LongestPalindrome {
private:
    static bool isPalindromic(const std::string & s, size_t start, size_t end)
    {
        for(size_t index = 0; index < (end-start+1) / 2 ; index++)
        {
            if(s[start + index] != s[end - index])
                return false;
        }
        return true;
    }
    
    static string bruteForce(string s) 
    {       
        const size_t length = s.size();
        size_t maxLen = 1;
        size_t maxStart = 0;
        for(size_t start = 0; start<length ; start++)
        {
            for(size_t end = length - 1; end > start ;  end--)
            {
                const size_t len =end - start+1; 
                if(maxLen<len && isPalindromic(s, start, end))
                {
                    maxLen = len;
                    maxStart = start;
                    break;
                }
            }
        }
        
        
        return  s.substr(maxStart, maxLen);       
    }
    
   
    static int longestPalindromicFrom(const string & s, int left, int right)
    {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
    
    static string dynamicProgramming(const string & s)
    {
        int start = 0;;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = longestPalindromicFrom(s, i, i);
            int len2 = longestPalindromicFrom(s, i, i + 1);
            int len = len1>len2 ? len1:len2;
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start,maxLen);
    }
    

public:
    string longestPalindrome(string s) 
    {             
        if(s.size() <= 1)
            return s;
        //return  bruteForce(s);       
        return dynamicProgramming(s);
    }
};
