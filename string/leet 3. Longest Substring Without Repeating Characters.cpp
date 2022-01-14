class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int maxLen = 0;
        
        //unordered_set<char> current;
        int current[256] = {0};//use bitmap
        int left=0;
        int right = 0;
        
        while(right< s.size())
        {
            while(current[s[right]] )//right letter is in current map--> i need to move left to remove this duplication
            {
                current[s[left]]=0;
                ++left;
            }
            
            current[s[right]] = 1;// no more duplication on right, mark right in current, move to next
            right++;
            if(right - left +1 > maxLen)//every time right increase one, we have the possiblility to have a max length 
            {
                maxLen = right - left;
            }
           
        }
        
        return maxLen;
        
    }
};
