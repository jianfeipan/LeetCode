class Solution {
public:
    int rob(vector<int>& nums) 
    {
        /*
        DP
        */
        vector<int> maxRob(nums.size(), -1);
        
        return rob(nums, 0, maxRob);
        
    }
    
    int rob(vector<int>& nums, int from, vector<int> & maxRob)
    {
        if(from > nums.size() - 1) return 0;
        if(from == nums.size() -1) return nums[from];
        
        auto & cache = maxRob[from];
        if(cache != -1)  return cache;
        
        const int valueRobCurrent = nums[from] + rob(nums, from + 2, maxRob);
        const int valueNotRobCurrent = rob(nums, from + 1, maxRob);
        return cache = max(valueRobCurrent, valueNotRobCurrent);
    }

};
