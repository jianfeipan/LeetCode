class Solution {
  
  /*
  anagrams, substring o(2N) solution 2 pointer left right shift right to match then shift left to remove unmatched...
  
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
