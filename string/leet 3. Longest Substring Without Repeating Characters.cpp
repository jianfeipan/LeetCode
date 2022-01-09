class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int maxLen = 0;
        
        unordered_set<char> current;
        int left=0;
        int right = 0;
        
        while(right< s.size())
        {
            while(current.count(s[right]))
            {
                current.erase(s[left]);
                ++left;
            }
            
            current.insert(s[right]);
            right++;
            if(right - left +1 > maxLen)
            {
                maxLen = right - left;
            }
           
        }
        
        return maxLen;
        
    }
};
