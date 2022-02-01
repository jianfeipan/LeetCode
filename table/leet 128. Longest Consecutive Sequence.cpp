
#include <algorithm>  

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> uniqueNums(nums.begin(), nums.end());
        
        int maxLen = 0;
        
        for(auto num : nums)//vector nums ready only
        {
            if(uniqueNums.count(num))
            {
                int currenLen = 1;
                int left = num-1;
                while(uniqueNums.count(left)) 
                {
                    uniqueNums.erase(left);
                    ++currenLen;
                    --left;
                }
                
                int right = num+1;
                while(uniqueNums.count(right)) 
                {
                    uniqueNums.erase(right);
                    ++currenLen;
                    ++right;
                }
                
                maxLen = max(maxLen, currenLen);
            }
            
        }
        
        return maxLen;
        
    }
};
