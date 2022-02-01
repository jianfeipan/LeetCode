class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        vector<bool> bucket(nums.size(), false);
        
        for(const auto & num : nums)
        {
            if(0 < num && num <= bucket.size()) bucket[num-1] = true;
        }
        
        
        for(int i = 0; i< bucket.size(); ++i)
        {
            if(!bucket[i]) return i+1;
        }
        
        return bucket.size()+1;
    }
};
