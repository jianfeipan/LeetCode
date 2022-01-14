class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        return subsets_iterator(nums);
    }
    
    vector<vector<int>> subsets_iterator(const vector<int>& nums)
    {
        vector<vector<int>> subSets; subSets.reserve(pow(2, subSets.size()));
        subSets.push_back({});
        
        for(int num : nums)
        {
            const size_t currentSize = subSets.size();//Care ful, this could not be inlined because the size chnaged with adding
            for(size_t i = 0; i<currentSize; ++i)
            {
                vector<int> toCombine(subSets[i]);
                toCombine.emplace_back(num);
                subSets.emplace_back(toCombine);
            }
        }
        
        return subSets;
        
    }

    
    vector<vector<int>> subsets_recusive(vector<int>& nums)
    {
        auto result = subsets_recusive(nums, 0);
        result.push_back({});//empty cannot be manged by the recusive: because a empty combies a {1} is still {1}, this will make duplications
        return result;
    }

    vector<vector<int>> subsets_recusive(const vector<int>& nums, int from) //we can use a cache to note on from index, what are the results, to avoid duplications
    {
       if(from == nums.size()-1) return {{nums[from]}};
        
        vector<vector<int>> results;

        auto left = nums[from];
        results.push_back({left});
        vector<vector<int>> rights = subsets_recusive(nums, from + 1);
        for(auto & right : rights)
        {
            results.push_back(right);
            right.insert(right.begin(), left);
            results.push_back(right);
        }
        return results;
    }

    
    vector<vector<int>> subsets_combine_add_element(vector<int>& nums) {
        
        vector<vector<int>> subSets;
        subSets.reserve(pow(2, subSets.size()));//every element can be present or not, n element will have 2^n cases
        subSets.push_back({});
        
        for(int i = 0; i<nums.size(); ++i)
        {
            const size_t currentSize = subSets.size();//itering on it self, need to take care the index, here we use this size to note in next rand ,where we stop
            for(int left = 0; left<currentSize; ++left)
            {
                vector<int> combination(subSets.at(left));
                combination.push_back(nums[i]);
                subSets.push_back(combination);
            }
        }
            
        
        return subSets;
    }
};
