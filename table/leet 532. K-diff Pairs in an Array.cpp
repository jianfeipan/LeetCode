class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        unordered_map<int, int> counts;
        
        int counter = 0;
        
        for(int num : nums) counts[num]++;
         
        for(const auto & [num, count] : counts)
        {
            if(k == 0)
            {
                if(count>=2) ++counter;
            }
            else
            {
                if(counts.count(num+k)) ++counter;
            }
        }
        
        return counter;
    }
        

};
