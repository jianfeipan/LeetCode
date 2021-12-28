class Solution {
  
  /*
  anagrams, substring o(2N) solution 2 pointer left right shift right to match then shift left to remove unmatched...
  
  
  
  
  Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".


"abab"
"ab"
"cbaebabacd"
"abc"
"a"
"ab"
  */
  
  
public:
    //Idea1: double pointer shift, count with a map if we are anagrams 
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        unordered_map<char, int> toMatch;
        for(char c : p)
        {
            toMatch[c]++;
        }
        
        int matchedCharNB = p.size();
        int left = 0;
        int right = 0;
        while(right<s.size())
        {
            //Move right to right,and count down toMatch, until all letters are matched
            while(matchedCharNB>0 && right<s.size())
            {
                //cout<<"right shift"<<right;
                auto it = toMatch.find(s[right]);
                if(it!=toMatch.end())
                {
                    --(it->second);
                    if(it->second>=0)//a effective match: not a duplicated
                    {
                        --matchedCharNB;
                    }
                }
                
                ++right;
            }
            
            /*after this, I found the first right possible position anagram 
            from left--> right, now I need to shift left to right to identify the anagram
            */
            while(matchedCharNB==0  && left<s.size())//during the shift, I need to still have all letters matched
            {
                //cout<<"left shift"<<left;
                auto it = toMatch.find(s[left]);
                if(it!=toMatch.end())
                {
                    ++(it->second);
                    if(it->second>0)//a effective match: not a duplicated
                    {
                        ++matchedCharNB;
                    }
                }
                ++left;
                
                //after this we found the possible anagram from left-1 --> right-1
                if(right-left+1 == p.size())
                {
                    result.push_back(left-1);
                }
            }
            
            
        }
        
        
        return result;
        
    }
    
    //Idea0: window slide : if anagram one by one slide
    vector<int> findAnagrams_time_limit_exceeded(string s, string p) {
        if(s.size() < p.size())
            return {};
        
        sort(p.begin(), p.end());
        vector<int> result;
        
        for(int i=0; i<= s.size() - p.size(); ++i)
        {
            if(isAnagram(s.substr(i, p.size()), p))
            {
                result.push_back(i);
            }
        }
        return result;
    }
    
private:
    bool isAnagram(string s, const string & p)
    {
        if(s.size() == p.size())
        {
            sort(s.begin(), s.end());
            return  s == p;
        }
        else
        {
            return false;
        }
    }
    
};
