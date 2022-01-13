class Solution {
public:
    int countKDifference(vector<int>& nums, int k) 
    {
        return countKDifference_map_cout_two_pointer(nums, k);
    }
private:
    
    int countKDifference_map_cout_two_pointer(vector<int>& nums, int k) 
    {
        if(nums.empty()) return -1;//thow exception
     
        int count = 0;
        
        map<int, size_t> orderedNums;
        for(int num : nums) ++orderedNums[num]; 
        
        vector<int> uniqueOrderedNums;
        for(auto[key, value] : orderedNums)
            uniqueOrderedNums.push_back(key);
        
        size_t left = 0;
        size_t right = 1;
        while(right<uniqueOrderedNums.size() && left<uniqueOrderedNums.size())
        {

            if(uniqueOrderedNums[right] - uniqueOrderedNums[left] == k)
            {
                count+=orderedNums[uniqueOrderedNums[left]] * orderedNums[uniqueOrderedNums[right]];
                ++left;++right;
            }
            else if(uniqueOrderedNums[right] - uniqueOrderedNums[left] < k) ++right;
            else ++left;
        }
        
        return count;
    }
    
    int countKDifference_brute_force(vector<int>& nums, int k) 
    {
        int count = 0;
        for(size_t i = 0; i<nums.size();++i)
            for(size_t j = i+1; j<nums.size(); ++j)
                if(abs(nums[i] - nums[j]) == k) ++count;
        return count;
    }

};
